#include "lap.h"

Lap::Lap(QObject *parent, int nosectors) : QObject(parent)
{
    this->gl = new Global(this);
  this->laptype = l_ok;
  this->laptime = 0;
  this->driver = -1;
  this->fuel_end = 0;
  this->fuel_start = 0;
  for(int i = 0; i < this->gl->interval_count +1; i++){
      Team_Gap_Container *gap = new Team_Gap_Container(this);
      this->intervals.push_back(gap);
    }
}

Lap::~Lap(){
  for(int i = 0; i < this->sectors.count(); i++){
      delete this->sectors[i];
    }
  this->sectors.clear();
}

void Lap::set_sector(int sectorno, float sectortime){
  if(sectorno >= 0){
  while(this->sectors.count() <= sectorno){
      lap_sector *s = new lap_sector(this);
      this->sectors.push_back(s);
    }

  this->sectors[sectorno]->update_sector(sectortime);
    }
}

float Lap::get_sectortime(int sectorno){
  if((sectorno >= 0) && (sectorno < this->sectors.count())){
      if(this->sectors[sectorno]->sectortime != 0){
      return this->sectors[sectorno]->raw_sector_time;
        }else{
          return this->sectors[sectorno]->sectortime;
        }
    }
  return -1;
}

float Lap::get_sectordistpct(int sectorno){

  return -1;
}

void Lap::set_laptype(int laptype){
  if(this->laptype == l_ok){
      this->laptype = laptype;
    }else if(this->laptype == l_pit){
      //pit is most important;
    }else if(this->laptype == l_offtrack){
      if(laptype != l_pit){
          this->laptype = l_offtrack;
        }
    }
}

bool Lap::set_laptime(float time){
  if(this->laptime != time){
      this->laptime = time;
      /*
      for(int i = 0; i< this->sectors.count(); i++){
          if(this->sectors[i]->raw_sector_time == 0){
              break;
            }else{
              this->sectors[i]->sector_percentage = this->sectors[i]->raw_sector_time / this->laptime;
            }
        }
      float total_percentage = 0;
      for(int i = 0; i < this->sectors.count(); i++){
          total_percentage = total_percentage + this->sectors[i]->sector_percentage;
        }
      float diff = 1.0 - total_percentage;
      diff = diff / this->sectors.count();
      for(int i = 0; i < this->sectors.count(); i++){
          this->sectors[i]->sector_percentage = this->sectors[i]->sector_percentage + diff;
          this->sectors[i]->sectortime = this->laptime * this->sectors[i]->sector_percentage;
          diff = this->sectors[i]->sectortime - this->sectors[i]->raw_sector_time;
          diff = diff - 1;
        }
       */
      return true;
    }
  return false;
}

void Lap::set_fuel(float cur_fuel){
  if(this->fuel_start == 0){
      this->fuel_start = cur_fuel;
    }
  this->fuel_end = cur_fuel;
}

float Lap::get_fuel_usage(){
  return this->fuel_start - this->fuel_end;
}
