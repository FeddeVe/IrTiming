#include "pitstop.h"

PitStop::PitStop(QObject *parent) : QObject(parent)
{
  this->pitlane_start = 0;
  this-> pitlane_end = 0;
  this-> pitstop_start = 0;
  this-> pitstop_end = 0;
  this->lap = 0;
}


void PitStop::set_lanetime(float sessiontime){
  if(this->pitlane_start == 0){
      this->pitlane_start = sessiontime;
    }
  this->pitlane_end = sessiontime;
}

void PitStop::set_stoptime(float sessiontime){
  if(this->pitstop_start == 0){
      this->pitstop_start = sessiontime;
    }
  this->pitstop_end = sessiontime;
}

float PitStop::get_lanetime(){
  return this->pitlane_end - this->pitlane_start;
}

float PitStop::get_stoptime(){
  return this->pitstop_end - this->pitstop_start;
}
