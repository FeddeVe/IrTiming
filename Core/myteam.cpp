#include "myteam.h"

MyTeam::MyTeam(QObject *parent) : QObject(parent)
{
  this->reset();

}

void MyTeam::reset(){
  this->carontrack = false;
  this->caridx = -1;
  this->my_team = nullptr;
    this->time_remain = 0;
    this->laps_remain = 0;
  this->cur_fuel = 0;
  this->fuel_level_start = 0;
  this->fuel_distance_start = 0;
  this->fuel_laps = 0;
  this->fuel_avg_lap = 0;
  this->fuel_lap_level = 0;
  this->fuel_till_end = 0;
  this->fuel_add_laps = 1;
  this->fuel_session_time = 0;
  this->fuel_total_laps_stint = 0;
    this->lf = 0.0f;
    this->rf = 0.0f;
    this->lr = 0.0f;
    this->rr = 0.0f;
    this->fuel_start_time = 0;
    this->fuel_time_in_stint = 0;
    this->delay = 0;


}

void MyTeam::update_from_telemetry(ir_tel_vars *v){
  this->carontrack = v->IsOnTrack->value[0].toBool();

  if(this->my_team != nullptr){
  if(this->my_team->avg_40_lap->laptime != 0){
      this->laps_remain = ((v->SessionTimeRemain->value[0].toFloat() / this->my_team->avg_40_lap->laptime) + 1);
      this->time_remain = v->SessionLapsRemainEx->value[0].toInt() * this->my_team->avg_40_lap->laptime;
  }
    }
  delay++;
  if(delay > 10){
  this->calc_fuel(v);
    delay = 0;
  }

}

void MyTeam::set_tyrewear(float lf, float rf, float lr, float rr, int lap){ 
  this->lf = lf;
  this->rf = rf;
  this->lr = lr;
  this->rr = rr;
} 

void MyTeam::calc_fuel(ir_tel_vars *v){
   if((this->my_team != nullptr)){
  float f = v->FuelLevel->value[0].toFloat();;
  float ses_time = v->SessionTimeRemain->value[0].toFloat();
  if((ses_time < 0) || (this->my_team->onpitroad)){
      this->fuel_level_start = f;
      this->fuel_distance_start = this->my_team->distance_driven;
      this->fuel_start_time = v->SessionTime->value[0].toFloat();

    }
  if(f > this->cur_fuel){
      this->fuel_level_start = f;
      this->fuel_distance_start = this->my_team->distance_driven;
       this->fuel_start_time = v->SessionTime->value[0].toFloat();
    }
  this->cur_fuel = f;
  this->fuel_session_time = ses_time;
  this->fuel_time_in_stint = v->SessionTime->value[0].toFloat() - this->fuel_start_time;

      if(this->my_team->curlap != -1){
          this->my_team->Laps[this->my_team->curlap]->set_fuel(this->cur_fuel);
        }
    }
   float diff = this->fuel_level_start - this->cur_fuel;
   if(diff > 0){
        float diff_driven = this->my_team->distance_driven - this->fuel_distance_start;
        if(diff_driven > 0){
            this->fuel_avg_lap = diff / diff_driven;
          }

     }

   if(this->fuel_avg_lap > 0){
       this->fuel_laps = this->cur_fuel / this->fuel_avg_lap;
     }
   int calc_laps = v->SessionLapsRemainEx->value[0].toFloat();
   if(calc_laps == IRSDK_UNLIMITED_LAPS){
       calc_laps = this->laps_remain;
     }
   calc_laps = calc_laps + 1;
   float fuel_needed = calc_laps * this->fuel_avg_lap;
   fuel_needed = fuel_needed - this->cur_fuel;
   this->fuel_till_end = fuel_needed;
     if((this->my_team != nullptr)){
   this->fuel_total_laps_stint = (this->my_team->distance_driven - this->fuel_distance_start) + this->fuel_laps;
       }

}

void MyTeam::update_from_sessionstring(SessionString *s){
  this->caridx = s->driverinfo->get_DriverCarIdx().toInt();
}

void MyTeam::set_my_team(Team *t){
  this->my_team = t;
}
