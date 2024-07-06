#include "teams.h"

Teams::Teams(QObject *parent, Track *reftrack) : QObject(parent)
{
  this->reftrack = reftrack;
  this->myteam = new MyTeam(this);
  this->gap_worker = 0;
  for(int i = 0; i < 64; i++){
      Team *t = new Team(this, i, this->reftrack);
      this->teams.push_back(t);
    }
  this->gap_updater = 0;
}

void Teams::update_from_telemetry(ir_tel_vars *vars){
  for(int i = 0; i < this->teams.count(); i++){
      this->teams[i]->update_from_telemetry(vars);
    }

  for(int i = 0; i < this->teams.count(); i++){
      this->teams[i]->calc_my_position(this);
    }

  this->myteam->update_from_telemetry(vars);
  if(this->gap_worker > this->teams.count() -1){
      this->gap_worker = 0;
      this->gap_updater++;
              if(this->gap_updater > 100){
                  this->gap_updater = 0;
              }
    }
  this->teams[gap_worker]->calc_gaps(this);
  this->gap_worker++;
 // this->teams[gap_worker]->calc_gaps(this);
 // this->gap_worker++;

}

void Teams::update_from_sessionstring(SessionString *s){
  this->myteam->update_from_sessionstring(s);
  for(int i = 0; i<this->teams.count(); i++){
      this->teams[i]->update_from_sessionstring(s);
      if(this->teams[i]->CarIDX == myteam->caridx){
          myteam->set_my_team(this->teams[i]);
        }
    }


}

void Teams::reset(){
  for(int i = 0; i<this->teams.count(); i++){
      this->teams[i]->reset();
    }
  this->myteam->reset();
}
