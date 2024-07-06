#include "telemetry_save_data.h"

Telemetry_Save_Data::Telemetry_Save_Data(QObject *parent) : QObject(parent)
{

}

Telemetry_Save_Data::~Telemetry_Save_Data(){
  for(int i = 0; i < this->Laps.count(); i++){
      delete this->Laps[i];
    }
}
