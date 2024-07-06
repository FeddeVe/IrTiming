#include "tires.h"
#include "ui_tires.h"

Tires::Tires(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Tires)
{
  ui->setupUi(this);
  this->tiregraph = new Tire_Graph(this);
  this->delay = 0;
  this->oldlap = -1;
  ui->horizontalLayout->addWidget(this->tiregraph);
}

Tires::~Tires()
{
  delete ui;
}

void Tires::on_core_update(Core *c){
  this->delay++;
  if(this->delay > 119){
      this->delay = 0;
          this->do_work(c);
    }


}

void Tires::do_work(Core *c){
  if(c->teams->myteam->my_team != nullptr){
  MyTeam *my = c->teams->myteam;
  for(int i = 0; i < this->tiregraph->data.count(); i++){
      delete this->tiregraph->data[i];
    }

  int curlap = my->my_team->curlap;
  if(oldlap != -1){
      if(curlap - oldlap >= 5){
          if(ui->checkBox_2->isChecked()){
              emit this->restart_telemetry();
            }
          oldlap = curlap;
        }
    }else{
      oldlap = curlap;
    }
  curlap = curlap;
  if(curlap > 0){
      this->tiregraph->centerlap = curlap;
      ui->label->setText(QString::number(round(my->lf * 100)) + "%");
      ui->label_2->setText(QString::number(round(my->rf * 100)) + "%");
      ui->label_3->setText(QString::number(round(my->lr * 100)) + "%");
      ui->label_4->setText(QString::number(round(my->rr * 100)) + "%");
    }
   this->tiregraph->repaint();
   }
}

void Tires::on_checkBox_stateChanged(int arg1)
{
  if(arg1 == 0){
      this->setWindowFlags(Qt::Window);
      this->show();
    }else{
      this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
      this->show();
    }
}
