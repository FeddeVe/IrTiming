#include "times.h"
#include "ui_times.h"

Times::Times(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Times)
{
    this->gl = new Global(this);
    ui->setupUi(this);
    this->delay = 0;
    this->windowid = 2;

}

Times::~Times()
{
    delete this->gl;
    delete ui;
}

void Times::on_core_update(Core *c){
  this->delay++;
  if(this->delay == 30){
      this->do_work(c);
      this->delay = 0;
    }
}

void Times::do_work(Core *c){
    QDateTime nu = QDateTime::currentDateTime();
    ui->label_2->setText(nu.toString("HH:mm:ss"));
    ui->label_4->setText(c->session->SessionTimeOfDay.toString("HH:mm:ss"));
    double time_remain = c->session->SessionTimeRemain;
    if(time_remain == IRSDK_UNLIMITED_TIME){
        time_remain = c->teams->myteam->time_remain;
    }
    ui->label_6->setText(this->gl->longtimetostring(time_remain));
    int laps_remain = c->session->SessionLapsRemain;
    if(laps_remain == IRSDK_UNLIMITED_LAPS){
        laps_remain = c->teams->myteam->laps_remain;
    }
    ui->label_8->setText(QString::number(laps_remain));
    ui->label_10->setText(QString::number(round(c->wheater->air_temperature * 10)/10) +"℃");
    ui->label_12->setText(QString::number(round(c->wheater->track_temperature * 10)/10) +"℃");

    int flags = c->session->SessionFlags;
    bool yellowFlag = ((flags & irsdk_yellow) != 0) || ((flags & irsdk_yellowWaving) != 0) ? true : false;
    bool blueFlag = ((flags & irsdk_blue) != 0) ? true : false;

    QPalette p_yellow;
    p_yellow.setColor(QPalette::Background, QColor::fromRgb(231,231,32));
    QPalette p_blue;
    p_blue.setColor(QPalette::Background, QColor::fromRgb(32,32,231));
    QPalette p_black;
    p_black.setColor(QPalette::Background, QColor::fromRgb(0,0,0));


    if(yellowFlag){

        this->setPalette(p_yellow);

      }else if(blueFlag){
        this->setPalette(p_blue);

      }else{
        this->setPalette(p_black);

      }
}

void Times::on_checkBox_stateChanged(int arg1)
{
  int state = 0;
  if(arg1 == 0){
      this->setWindowFlags(Qt::Window);
      this->show();
    }else{
      this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
      state = 1;
      this->show();
    }
  emit this->save_window(this->windowid, this->x(), this->y(),  this->width(), this->height(), state);
}

void Times::window_loaded(bool okay, int windowid, int x, int y, int width, int height, int state){
    if(okay){
        if(this->windowid == windowid){
            if(state == 0){
                this->setWindowFlags(Qt::Window);
                this->show();
            }else if(state == 1){
                this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
                this->show();
            }
            this->move(x,y);
            this->setFixedSize(width, height);

        }
    }
}



