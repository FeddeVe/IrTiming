#include "weather.h"

Weather::Weather(QObject *parent) : QObject(parent)
{
  this->air_temperature = 0;
  this->track_temperature = 0;

}

void Weather::on_telemetry_update(ir_tel_vars *v){
  this->air_temperature = v->AirTemp->value[0].toFloat();
  this->track_temperature = v->TrackTemp->value[0].toFloat();
}

void Weather::on_sessionstring_update(SessionString *s){

}
