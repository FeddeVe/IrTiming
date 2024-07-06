#include "race_chart.h"
#include "ui_race_chart.h"

Race_Chart::Race_Chart(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Race_Chart)
{
  ui->setupUi(this);
  this->gl = new Global();
  this->firstrun = true;
  this->my_classid = 0;

}

Race_Chart::~Race_Chart()
{
  delete ui;
}

void Race_Chart::do_work(Core *c){
  if(c->teams->myteam->my_team != nullptr){
  this->my_classid = c->teams->myteam->my_team->classid;
  if(this->firstrun){
      this->firstrun = false;
      for(int i = 0; i < c->teams->teams.count(); i++){
          Race_Chart_Team *t = new Race_Chart_Team(this, c->teams->teams[i], this->gl->randomcolor(i));
        }
    }

  bool refresh = false;
  for(int i = 0; i < this->Teams.count(); i++){
      if(this->Teams[i]->calculate(c)){
          refresh = true;
        }
    }
  if(refresh){
      this->draw_grid();
    }
    }
}

void Race_Chart::draw_grid(){
  int max_laps = 0;
  for(int i = 0; i < this->Teams.count(); i++){
      if(ui->checkBox->isChecked()){
          if(this->Teams[i]->team->classid == this->my_classid){
              if(this->Teams[i]->laps.count() > max_laps){
                  max_laps = this->Teams[i]->laps.count();
                }
            }
        }else{
          if(this->Teams[i]->laps.count() > max_laps){
              max_laps = this->Teams[i]->laps.count();
            }
        }
    }


}
