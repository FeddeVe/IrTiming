#include "telemetryoptions.h"

TelemetryOptions::TelemetryOptions(QObject *parent) : QObject(parent)
{

}

void TelemetryOptions::set_value(QString key, QString value){
  if(key == "TelemetryDiskFile"){
  this->TelemetryDiskFile=value;
  }else{
      qDebug() << "Unused var in TELEMETRYOPTIONS "<< key <<" - " << value;
    }

}

QString TelemetryOptions::get_TelemetryDiskFile(){
  return this->TelemetryDiskFile;
}
