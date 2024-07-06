#include "team.h"

Team::Team(QObject *parent, int CarIDX, Track *reftrack) : QObject(parent)
{
  this->reftrack = reftrack;
  this->CarIDX = CarIDX;
  this->reset();
}

void Team::update_from_telemetry(ir_tel_vars *v){

  if(this->pitcounter > 0){
      this->pitcounter = this->pitcounter - 1;
    }
  if(this->offtrackcounter > 0){
      this->offtrackcounter = this->offtrackcounter - 1;
    }
  this->currentsession = v->SessionNum->value[0].toInt();

  if(this->curlap != v->CarIdxLap->value[this->CarIDX].toInt()){
      this->curlap = v->CarIdxLap->value[this->CarIDX].toInt();
      this->new_lap(v);
    }

  if(this->curlap != -1){
  this->TrackSurface = v->CarIdxTrackSurface->value[this->CarIDX].toInt();

  if(this->TrackSurface == irsdk_TrkLoc::irsdk_OffTrack){
      this->Laps[this->curlap]->set_laptype(Lap::l_offtrack);
      this->offtrackcounter = 255;
    }


  this->lap_dct = v->CarIdxLapDistPct->value[this->CarIDX].toFloat();
  if(this->lap_dct < 0){
      this->lap_dct = 0;
    }
  int interval = this->lap_dct * 250;
  if((interval >= 0) && (interval <= 250)){
      this->Laps[this->curlap]->intervals[interval] = v->SessionTime->value[0].toFloat();
    }
  this->distance_driven = float(this->curlap) + this->lap_dct;
  //this->classposition = v->CarIdxClassPosition->value[this->CarIDX].toInt();
  this->calc_sector(v);
  this->handle_pitstop(v);  
  int bp = 0;
  bp++;
    }
}

void Team::update_from_sessionstring(SessionString *s){
  DriverInfo_Drivers *dr = s->driverinfo->get_driver_caridx(this->CarIDX);
  SessionInfo_Session *ses = s->sessioninfo->Get_Session(this->currentsession);
  SessionInfo_ResultPosition *res = nullptr;
  if(ses!= nullptr){
      res = ses->get_resultposition(this->CarIDX);
      if(res != nullptr){
      this->set_lap(res);
          this->classposition = res->get_ClassPosition().toInt() +1;
          this->position = res->get_Position().toInt();
        }
    }
  if(dr != nullptr){
      int UserID = dr->get_UserID().toInt();
      bool nieuw = true;
      for(int i = 0; i < this->Drivers.count(); i++){
          if(this->Drivers[i]->UserID == UserID){
              this->current_driver = i;
              if(this->curlap != -1){
              this->Laps[this->curlap]->driver = i;
                }
              nieuw = false;
            }
        }
      if(nieuw){
          Driver *d = new Driver(this);
          d->UserID = dr->get_UserID().toInt();
          d->Irating = dr->get_IRating().toInt();
          d->ClubName = dr->get_ClubName();
          d->Initials = dr->get_Initials();
          d->LicColor = dr->get_LicColor();
          d->UserName = dr->get_UserName();
          d->LicString = dr->get_LicString();
          d->AbbrevName = dr->get_AbbrevName();
          d->DivisionName = dr->get_DivisionName();
          this->Drivers.push_back(d);
          this->current_driver = this->Drivers.count() -1;
        }

      this->clas = dr->get_CarClassShortName();
      this->classid = dr->get_CarClassID().toInt();
      int bp = 0;
      bp++;
    }

}

void Team::new_lap(ir_tel_vars *v){
  while(this->Laps.count() <= this->curlap){
      Lap *l = new Lap(this, this->reftrack->Sectors.count());
      this->Laps.push_back(l);
    }
  if(this->Pitstops.count() > 0){
      this->laps_in_stint = this->curlap - this->Pitstops[this->Pitstops.count()-1]->lap;
  }else{
      this->laps_in_stint = this->curlap;
  }
  this->calc_driver_laps();
}

void Team::calc_sector(ir_tel_vars *v){
  if(this->curlap != -1){
  if(reftrack->isinsector(this->lap_dct) != this->current_sector){
      this->current_sector = reftrack->isinsector(this->lap_dct);
    }

  if(this->old_lapdistance != -1){
        this->Laps[this->curlap]->set_sector(reftrack->isinsector(this->lap_dct), v->SessionTime->value[0].toFloat());
      /*
  if(reftrack->isinsector(this->old_lapdistance) == reftrack->isinsector(this->lap_dct)){
      this->Laps[this->curlap]->set_sector(reftrack->isinsector(this->lap_dct), v->SessionTime->value[0].toFloat());
    }else{
      int oldsector = reftrack->isinsector(this->old_lapdistance);
      int newsector = reftrack->isinsector(this->lap_dct);
      if(newsector < oldsector){
          //overlap
          float new_distance = this->lap_dct + 1.0f;
          float total_distance = new_distance - this->old_lapdistance;
          float distance_newsector = this->lap_dct;
          float distance_oldsector = total_distance - distance_newsector;
          float total_time = v->SessionTime->value[0].toFloat() - this->old_sessiontime;
          float percentage_oldsector = distance_oldsector / total_distance;
          float percentage_newsector = distance_newsector / total_distance;
          float time_add_newsector = total_time * percentage_newsector;
          float time_add_oldsector = total_time * percentage_oldsector;
          float time_oldsector = this->old_sessiontime + time_add_oldsector;
          float time_newsector = this->old_sessiontime + time_add_newsector;
          int oldlap = this->curlap - 1;
          if(oldlap > 0){
            this->Laps[oldlap]->set_sector(oldsector, time_oldsector);

            }
          this->Laps[this->curlap]->set_sector(oldsector, time_newsector);


        }else{

          float total_distance = this->lap_dct - this->old_lapdistance;
          float distance_newsector = this->lap_dct - this->reftrack->Sectors[newsector];
          float distance_oldsector = total_distance - distance_newsector;
          float total_time = v->SessionTime->value[0].toFloat() - this->old_sessiontime;
          float percentage_oldsector = distance_oldsector / total_distance;
          float percentage_newsector = distance_newsector / total_distance;
          float time_add_newsector = total_time * percentage_newsector;
          float time_add_oldsector = total_time * percentage_oldsector;
          float time_oldsector = this->old_sessiontime + time_add_oldsector;
          float time_newsector = this->old_sessiontime + time_add_newsector;

           this->Laps[this->curlap]->set_sector(oldsector, time_oldsector);
           this->Laps[this->curlap]->set_sector(newsector, time_newsector);



         }
    }
      */
    }

}
  this->old_lapdistance = this->lap_dct;
  this->old_sessiontime = v->SessionTime->value[0].toFloat();
}

void Team::handle_pitstop(ir_tel_vars *v){
  if(this->curlap != -1){
  if(this->onpitroad){
  this->onpitroad = v->CarIdxOnPitRoad->value[this->CarIDX].toBool();
      this->pitcounter = 255;
  if(this->onpitroad){
      this->Laps[this->curlap]->set_laptype(Lap::l_pit);
      this->Pitstops[this->currentstint]->set_lanetime(v->SessionTime->value[0].toFloat());
      this->Pitstops[this->currentstint]->lap = this->distance_driven;
      if(v->CarIdxTrackSurface->value[this->CarIDX].toInt() == irsdk_TrkLoc::irsdk_InPitStall){
          this->Pitstops[this->currentstint]->set_stoptime(v->SessionTime->value[0].toFloat());
        }
   }
    }else{
      if(v->CarIdxOnPitRoad->value[this->CarIDX].toBool()){
          this->onpitroad = v->CarIdxOnPitRoad->value[this->CarIDX].toBool();
          PitStop *p = new PitStop(this);
          p->lap = this->distance_driven;
          p->set_lanetime(v->SessionTime->value[0].toFloat());
          if(v->CarIdxTrackSurface->value[this->CarIDX].toInt() == irsdk_TrkLoc::irsdk_InPitStall){
              p->set_stoptime(v->SessionTime->value[0].toFloat());
            }
          this->Pitstops.push_back(p);
          this->currentstint = this->Pitstops.count() -1;
        }
    }

  float pitlap = 0;
  if(this->Pitstops.count() > 0){
      pitlap = this->Pitstops[this->Pitstops.count()-1]->lap;
    }
  this->laps_in_stint = this->distance_driven - pitlap;
}
}

void Team::set_lap(SessionInfo_ResultPosition *r){
  int completed = r->get_LapsComplete().toInt();
  float last_laptime = r->get_LastTime().toFloat();
  int bestlap = r->get_FastestLap().toInt();
  float bestlaptime = r->get_FastestTime().toFloat();

  if(completed != -1){
      while(this->Laps.count() <= completed){
          Lap *l = new Lap(this, this->reftrack->Sectors.count());
          this->Laps.push_back(l);
        }
      if(this->Laps[completed]->set_laptime(last_laptime)){
          this->calculate_avg();
        }
  }
  if(bestlap != -1){
      while(this->Laps.count() <= bestlap){
          Lap *l = new Lap(this, this->reftrack->Sectors.count());
          this->Laps.push_back(l);
        }
      this->fastestlap = bestlap;
      if(this->Laps[bestlap]->set_laptime(bestlaptime)){
          this->calculate_avg();
        }
   }
  int bp = 0;
  bp++;

}

void Team::calculate_avg(){

  int x = 5;
  int count = 0;
  float avg_laptime = 0;
  int i = this->Laps.count();
  QVector<float>avg_sector_times;
  QVector<int>avg_sector_count;

  while(i > 0){
      i = i - 1;
      if(this->Laps[i]->laptime > 0){
          avg_laptime = avg_laptime + this->Laps[i]->laptime;
          for(int y = 0; y < this->Laps[i]->sectors.count(); y++){
              while(avg_sector_times.count() -1 < y){
                  avg_sector_times.push_back(0.0f);
                  avg_sector_count.push_back(0);
              }
              if(this->Laps[i]->sectors[y]->sectortime != 0){
                  avg_sector_times[y] = avg_sector_times[y] + this->Laps[i]->sectors[y]->sectortime;
                  avg_sector_count[y]++;
                }
            }
          count++;
          if(count == x){
              break;
            }
        }
    }
  this->avgxlap->laptime = avg_laptime / count;

  for(int i = 0; i < avg_sector_times.count(); i++){
      if(avg_sector_count[i] >0){
          this->avgxlap->set_sector(i, avg_sector_times[i] / avg_sector_count[i]);
        }
    }
  i = this->Laps.count();
  int end = 1;
  count = 0;
  avg_laptime = 0.0f;
  if(this->Pitstops.count() > 0){
      end = this->Pitstops[this->Pitstops.count() -1]->lap +1;
    }
  while(i > end){
      i = i -1;
      if(this->Laps[i]->laptime != 0){
          avg_laptime = avg_laptime + this->Laps[i]->laptime;
          count++;
        }
    }
  if(count > 0){
      this->avg_stint_lap->set_laptime(avg_laptime / count);
    }


  x = 1;
  count = 0;
  int count1 = 0;
  int count2 = 0;
  avg_laptime = 0;
  float avg_laptime1=0;
  float calc_sessiontime1 = 0;
  float calc_sessiontime2 = 0;
  float avg_laptime2=0;
  QVector<int>count_interval;
  QVector<float>count_results;
  QVector<int>count_interval2;
  QVector<float>count_results2;
  for(int y = 0; y < 251; y++){
      count_interval.push_back(0);
      count_results.push_back(0.0f);
      count_interval2.push_back(0);
      count_results2.push_back(0.0f);
    }
  int stop = 0;
  for(int i = 0; i<this->Laps.count(); i++){
      if(this->Laps[i]->laptime > 0){
          avg_laptime = avg_laptime + (this->Laps[i]->laptime * x);
          count = count + x;
          if(this->Laps[i]->laptype != 2){
              avg_laptime2 = avg_laptime2 + (this->Laps[i]->laptime * x);
              count2 = count2 + x;
            }

          for(int y = 0; y < count_results.length(); y++){
              if((calc_sessiontime1 == 0) || (this->Laps[i]->intervals[y] == 0)){
                  calc_sessiontime1 = this->Laps[i]->intervals[y];
              }else{
                  float time = this->Laps[i]->intervals[y] - calc_sessiontime1;
                  count_results[y] = count_results[y] + (time * x);
                  count_interval[y] = count_interval[y] + x;
                  calc_sessiontime1 = this->Laps[i]->intervals[y];
                  if(this->Laps[i]->laptype != 2){
                      if(calc_sessiontime2 == 0){
                          calc_sessiontime2 = this->Laps[i]->intervals[y];
                        }else{
                          float time = this->Laps[i]->intervals[y] - calc_sessiontime2;
                          count_results2[y] = count_results2[y] + (time * x);
                          count_interval2[y] = count_interval2[y] + x;
                          calc_sessiontime2 = this->Laps[i]->intervals[y];
                        }
                    }else{
                      calc_sessiontime2 = 0;
                    }
              }
          }

          x = x +1;
        }
      stop++;
      if(stop > 50){
          break;
      }
    }

  if(count > 0){
  this->avg_laps->laptime = avg_laptime / count;
    }else{
      this->avg_laps->laptime = 0;
    }
  if(count2 > 0){
  this->avg_clean_lap->laptime = avg_laptime/count2;
    }else{
      this->avg_clean_lap->laptime = 0;
    }
for(int i = 0; i < count_results.length(); i++){
if(count_results[i] != 0){
  this->avg_laps->intervals[i] = count_results[i] / count_interval[i];
}else{
    this->avg_laps->intervals[i] = 0;
}
if(count_results2[i] != 0){
    this->avg_clean_lap->intervals[i] = count_results2[i] / count_interval2[i];
  }else{
    this->avg_clean_lap->intervals[i] = 0;
  }

}
int bp = 0;
bp++;
}

void Team::calc_gaps(Teams *teams){
  for(int i = 0; i < teams->teams.count(); i++){
      Team *t = teams->teams[i];
      int calc_distance = this->distance_driven * 250;
      int calc_distance_2 = t->distance_driven * 250;
      float gap = 0.0f;
      while(calc_distance <= calc_distance_2){
          int tmp_distance = calc_distance;
          while(tmp_distance > 250){
              tmp_distance = tmp_distance - 250;
            }
          if((tmp_distance >=0) && (tmp_distance < 250)){
          gap = gap + this->avg_clean_lap->intervals[tmp_distance];
          }
          calc_distance = calc_distance + 1;
        }
      this->Gaps[i] = gap;
    }


  /*
  int start_interval = (this->lap_dct * 250);
  for(int i = 0; i < teams->teams.count(); i++){
      Team *t = teams->teams[i];
      if(t->distance_driven > this->distance_driven){
           int calc_distance = this->distance_driven * 250;
           int calc_distance_2 = t->distance_driven * 250;
           int calc_interval = start_interval;

           float gap = 0.0f;
           while(calc_distance < calc_distance_2){
               if((calc_interval >= 0) && (calc_interval <= 250)){
                   gap = gap + this->avg_laps->intervals[calc_interval];
                }
               calc_interval++;
               if(calc_interval >= 250){
                   calc_interval = 0;
                 }
               calc_distance = calc_distance + 1;
             }
           this->Gaps[i] = gap;


        }else{
          this->Gaps[i] = -1.0f;
        }
    }
    */


}

void Team::calc_my_position(Teams *teams){
  int position = 1;
  int classpos = 1;
  for(int i = 0; i < teams->teams.count(); i++){
      Team *t = teams->teams[i];
      if(t->CarIDX != this->CarIDX){
          if(t->distance_driven > this->distance_driven){
              position++;
              if(t->classid == this->classid){
                  classpos++;
                }
            }
        }
    }
  this->my_position = position;
  this->my_classposition = classpos;


}

void Team::calc_driver_laps(){
    for(int y = 0; y < this->Drivers.count(); y++){
  int i = this->curlap - 1;
  int total = 0;
  int continues = 0;
  bool cont_set = false;
  while(i > 0){
          if(this->Laps[i]->driver == y){
              if(cont_set == false){
                  continues++;
                }
              total++;
            }else{
              cont_set = true;
            }
            i = i -1;
        }
     this->Drivers[y]->total_laps_driven = total;
  this->Drivers[y]->continues_laps_driven = continues;
    }
}

void Team::reset(){
  this->curlap = -1;
  this->lap_dct = -1;
  this->TrackSurface = -1;
  this->currentstint = 0;
  this->distance_driven = -1;
  this->old_lapdistance = -1;
  this->old_sessiontime = -1;
 this->current_sector = -1;
  this->onpitroad = false;
  this->laps_in_stint = 0;
  this->currentsession = -1;
  this->fastestlap = -1;
  this->avgxlap = new Lap(this);
  this->avg_laps = new Lap(this);
  this->avg_clean_lap = new Lap(this);
  this->avg_stint_lap = new Lap(this);
  this->clas = "";
  this->classid = -1;
  this->current_driver = -1;
  this->classposition = 99;
  this->position = 99;
  this->my_position = 99;
  this->my_classposition = 99;
  this->pitcounter = 0;
  this->offtrackcounter = 0;

  while(this->Gaps.count() < 64){
      this->Gaps.push_back(-1.0f);
    }
  for(int i = 0; i < this->Gaps.count(); i++){
      this->Gaps[i] = -1.0f;
    }

  for(int i = 0; i < this->Laps.count(); i++){
      delete this->Laps[i];
    }
  this->Laps.clear();
  for(int i = 0; i < this->Drivers.count(); i++){
      delete this->Drivers[i];
    }
  this->Drivers.clear();
  for(int i = 0; i < this->Pitstops.count(); i++){
      delete this->Pitstops[i];
    }
  this->Pitstops.clear();
}




