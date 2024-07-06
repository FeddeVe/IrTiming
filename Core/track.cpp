#include "track.h"

Track::Track(QObject *parent) : QObject(parent)
{

  this->TrackID = -1;
  this->timeoffset = 0;
  this->pts = new TrackPoints(this);


}

void Track::reload(){
   emit this->new_track(this->TrackID);
}

void Track::new_timeoffset(int offset){
  this->timeoffset = offset;
}

void Track::set_timeoffset(int offset){
  this->timeoffset = offset;
  emit this->save_timeoffset(this->TrackID, this->timeoffset);
}

void Track::update_from_sessionstring(SessionString *s){
  if(this->TrackID != s->weekendinfo->get_TrackID().toInt()){
      this->TrackID = s->weekendinfo->get_TrackID().toInt();
     this->pts->reset();
     this->Sectors.clear();
     for(int i = 0; i < s->splittimeinfo->sectors.count(); i++){
         while(s->splittimeinfo->sectors[i]->get_SectorNum().toInt() > this->Sectors.count() -1){
             this->Sectors.push_back(0);
           }
         this->Sectors[s->splittimeinfo->sectors[i]->get_SectorNum().toInt()] = s->splittimeinfo->sectors[i]->get_SectorStartPct().toFloat();
       }


     this->TrackName = s->weekendinfo->get_TrackName();
     QString tmp = s->weekendinfo->get_TrackLength();
     this->TrackDisplayName = s->weekendinfo->get_TrackDisplayName();
     this->TrackNumTurns = s->weekendinfo->get_TrackNumTurns().toInt();
     QStringList pos = s->weekendinfo->get_TrackLatitude().split(" ");
     this->Latitude = pos[0].toDouble();

     QStringList pos2 = s->weekendinfo->get_TrackLongitude().split(" ");
     this->Longitude = pos2[0].toDouble();
     emit this->new_track(this->TrackID);
    }
}

void Track::track_loaded(TrackPoints *points){
 for(int i = 0; i < pts->trackpoints.count(); i++){
     this->pts->trackpoints[i]->x = points->trackpoints[i]->x;
     this->pts->trackpoints[i]->y = points->trackpoints[i]->y;
     this->pts->trackpoints[i]->z = points->trackpoints[i]->z;
   }
 emit this->new_trackpoints(this);
}

void Track::update_from_telemetry(ir_tel_vars *v){

}

int Track::isinsector(float lap_dct){

  int i = this->Sectors.count();
  while(i>0){
      i = i -1;
      if(lap_dct >= this->Sectors[i]){
          return i;
        }
    }

  return -1;
}

float Track::get_sector_end(int sectorno){
  if(sectorno +1 == this->Sectors.count()){
      return 1.0f;
    }else{
      return this->Sectors[sectorno +1];
    }
}
