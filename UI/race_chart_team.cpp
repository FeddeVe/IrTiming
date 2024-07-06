#include "race_chart_team.h"

Race_Chart_Team::Race_Chart_Team(QObject *parent, Team *refteam, QColor clr) : QObject(parent)
{
  this->team = refteam;
  this->clr = clr;
}

bool Race_Chart_Team::calculate(Core *c){
  bool ret = false;
  if(this->team->curlap > 1){
  int lap = 0;
  float calc_sessiontime_enter = 0;
  for(int i = 0; i < this->team->Laps.count(); i++){
      if(this->laps.count() <= i){
          Race_Chart_Lap *l = new Race_Chart_Lap(this);
          this->laps.push_back(l);
        }
      if(this->laps[i]->session_time_enter != this->team->Laps[i]->sectors[0]->enter_time){
          ret = true;
          this->laps[i]->session_time_enter = this->team->Laps[i]->sectors[0]->enter_time;
          this->laps[i]->laptype = 0;
          if(this->team->Laps[i]->laptype == 2){
              this->laps[i]->laptype = 2;
            }
          this->laps[i]->predicted = false;
        }
      lap = i;
      calc_sessiontime_enter = this->team->Laps[i]->sectors[0]->enter_time;
    }
  float calc_laptime = this->team->avg_laps->laptime;
  float time_remain = c->session->SessionTimeRemain;
  while(time_remain > 0){
      calc_sessiontime_enter = calc_sessiontime_enter + calc_laptime;
      lap++;
      if(this->laps.count() <= lap){
          Race_Chart_Lap *l = new Race_Chart_Lap(this);
          this->laps.push_back(l);
        }
      this->laps[lap]->session_time_enter = calc_sessiontime_enter;
      this->laps[lap]->laptype = 0;
      this->laps[lap]->predicted = true;
      lap++;
      time_remain = time_remain - calc_laptime;
    }
    }
  return ret;
}
