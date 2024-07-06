#include "session.h"

Session::Session(QObject *parent, Core *refcore) : QObject(parent)
{
    this->refcore = refcore;

}

void Session::on_telemetry_update(ir_tel_vars *vars){

    this->SessionTime = vars->SessionTime->value[0].toDouble();
    if(this->SessionNum != vars->SessionNum->value[0].toInt()){
    this->SessionNum = vars->SessionNum->value[0].toInt();
       this->refcore->reset_core();
    }
    this->SessionState = vars->SessionState->value[0].toInt();
    this->SessionFlags = vars->SessionFlags->value[0].toInt();
    this->SessionTimeRemain = vars->SessionTimeRemain->value[0].toDouble();
    this->SessionLapsRemain = vars->SessionLapsRemainEx->value[0].toDouble();
    this->SessionTimeOfDay = QTime::fromMSecsSinceStartOfDay(vars->SessionTimeOfDay->value[0].toFloat() * 1000);
    this->SessionFlags = vars->SessionFlags->value[0].toInt();
    emit this->on_update(this);
}

void Session::on_sessionstring_update(SessionString *s){
  this->SessionDate = QDate::fromString(s->weekendoptions->get_Date(), "yyyy-MM-dd");
    if(this->SessionID != s->weekendinfo->get_SessionID().toInt()){
        this->SessionID = s->weekendinfo->get_SessionID().toInt();
        this->refcore->reset_core();
    }
  emit this->on_update(this);
}
