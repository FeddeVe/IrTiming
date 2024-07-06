#include "telemetry_save_data_lap.h"

Telemetry_Save_Data_Lap::Telemetry_Save_Data_Lap(QObject *parent) : QObject(parent)
{
  for(int i = 0; i < 1001; i++){
      Telemetry_Save_Data_Lap_PCT *d = new Telemetry_Save_Data_Lap_PCT(this);
      d->lap_pct = i;
      this->Data.push_back(d);
    }
}

Telemetry_Save_Data_Lap::~Telemetry_Save_Data_Lap(){
  for(int i = 0; i < this->Data.count(); i++){
      delete this->Data[i];
    }
}
