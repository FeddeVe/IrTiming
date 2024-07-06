#include "hue.h"
#include "ui_hue.h"

Hue::Hue(QWidget *parent, Core *refcore) :
  QWidget(parent),
  ui(new Ui::Hue)
{
    this->refcore = refcore;
  ui->setupUi(this);
  this->procent = 0;
  this->Sun = new sunset();
  this->do_tcp = false;
  this->delay = 0;
  QTcpSocket *s = new QTcpSocket(this);
  s->connectToHost(QHostAddress("192.168.2.251"), 7011);
  QString senddata = "{\"item\":\"Areas\","
                      "\"action\":\"Set Int\","
                      "\"ID\":11,"
                      "\"Brightness\":100,"
                      "\"Fade\":0}";
//qDebug() << s->state();
s->waitForConnected();
//qDebug() << s->state();
  s->write(senddata.toLatin1());
  s->flush();
  s->close();
  delete s;
  this->on = true;
  this->tmr = new QTimer(this);
  connect(tmr, SIGNAL(timeout()),this, SLOT(TimerSlot()));

}

Hue::~Hue()
{
  delete ui;
}

void Hue::do_work(Core *c){
  this->Sun->setPosition(this->refcore->track->Latitude, this->refcore->track->Longitude, this->refcore->track->timeoffset);
  this->Sun->setCurrentDate(this->refcore->session->SessionDate.year(), this->refcore->session->SessionDate.month(), this->refcore->session->SessionDate.day());
  QTime sunrise = QTime::fromMSecsSinceStartOfDay(this->Sun->calcSunrise() * 60 * 1000);
  QTime sunset = QTime::fromMSecsSinceStartOfDay(this->Sun->calcSunset() * 60 * 1000);

  this->sunset_off = sunset.addSecs(60*20);
  this->sunset_start = sunset.addSecs((60*20) * -1);
  this->sunrise_start_fade = sunrise.addSecs((60*20) * -1);
  this->sunrise_end_fade = sunrise.addSecs(60*20);
  this->carontrack = this->refcore->teams->myteam->carontrack;
  this->sessiontime = this->refcore->session->SessionTimeOfDay;


  ui->label->setText("SessionDate: " + this->refcore->session->SessionDate.toString());
  ui->label_2->setText("Session Time Off Day: " +this->refcore->session->SessionTimeOfDay.toString());
  ui->label_3->setText(sunset_start.toString() + "//"+ sunset_off.toString());
  ui->label_4->setText(sunrise.toString() + "//"+  sunset.toString());
  ui->spinBox->setValue(this->refcore->track->timeoffset);
  ui->label_5->setText(QString::number(this->procent) +" %");
  if(this->tmr->isActive() == false){
      this->tmr->start(4000);
    }
  this->do_tcp = true;
}



void Hue::core_update(Core *c){
 this->delay++;
  if(this->delay > 121){
      this->do_work(c);
      this->delay = 0;
    }

}

void Hue::on_spinBox_valueChanged(int arg1)
{
    emit this->save_timeoffset(arg1);
}

void Hue::TimerSlot(){
  if(this->do_tcp){

  if(this->carontrack){
       int intensity = 100;
       if(this->sessiontime < this->sunrise_start_fade){
           intensity = 0;
       }else if(this->sessiontime < this->sunrise_end_fade){
           float diff = this->sunrise_start_fade.msecsTo(this->sunrise_end_fade);
           float diff2 = this->sunrise_start_fade.msecsTo(this->sessiontime);
           float procent = diff2 / diff;
           intensity = procent * 100;
       }else if(this->sessiontime < this->sunset_start){
           intensity = 100;
       }else if(this->sessiontime < this->sunset_off){
           float diff = this->sunset_start.msecsTo(this->sunset_off);
           float diff2 = this->sunset_start.msecsTo(this->sessiontime);
           float procent = diff2/diff;
           procent = 1-procent;
           intensity = procent * 100;
       }else{
           intensity = 0;
       }
       intensity =0;
      // if(intensity > 50){
      //     intensity = 50;
      // }
       this->procent = intensity;

       QTcpSocket *s = new QTcpSocket(this);
       s->connectToHost(QHostAddress("192.168.2.251"), 7011);
       QString senddata = "{\"item\":\"Areas\","
                           "\"action\":\"Set Int\","
                           "\"ID\":11,"
                           "\"Brightness\":0,"
                           "\"Fade\":0}";
//qDebug() << s->state();
s->waitForConnected();
//qDebug() << s->state();
       s->write(senddata.toLatin1());
       s->flush();
       s->close();
       delete s;


   }else{
         this->procent = 100;

       QTcpSocket *s = new QTcpSocket(this);
       s->connectToHost(QHostAddress("192.168.2.251"), 7011);
       QString senddata = "{\"item\":\"Areas\","
                           "\"action\":\"Set Int\","
                           "\"ID\":11,"
                           "\"Brightness\":100,"
                           "\"Fade\":0}";
//qDebug() << s->state();
s->waitForConnected();
//qDebug() << s->state();
       s->write(senddata.toLatin1());
       s->flush();
       s->close();
       delete s;
       this->on = true;
       }
  this->do_tcp = false;
 }

}
