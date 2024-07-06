#include "driverinfo.h"

DriverInfo::DriverInfo(QObject *parent) : QObject(parent)
{

}

void DriverInfo::set_driver_value(int driverindex, QString key, QString value){
  while(this->drivers.count() <= driverindex){
      DriverInfo_Drivers *dr = new DriverInfo_Drivers(this);
      this->drivers.push_back(dr);
    }
  this->drivers[driverindex]->set_value(key, value);
}

void DriverInfo::clear(){
    for(int i = 0; i < this->drivers.count(); i++){
        delete this->drivers[i];
    }
    this->drivers.clear();
}

DriverInfo_Drivers *DriverInfo::get_driver(int index){
  if(index < this->drivers.count()){
      return this->drivers[index];
    }
  return nullptr;
}

DriverInfo_Drivers *DriverInfo::get_driver_caridx(int CarIDX){
  for(int i = 0;i < this->drivers.count(); i++){
      if(this->drivers[i]->get_CarIdx().toInt() == CarIDX){
          return this->drivers[i];
        }
    }
  return nullptr;
}

void DriverInfo::set_value(QString key, QString value){
    if(key == "DriverCarIdx"){
    this->DriverCarIdx=value;
    }
    else if(key == "DriverUserID"){
    this->DriverUserID=value;
    }
    else if(key == "PaceCarIdx"){
    this->PaceCarIdx=value;
    }
    else if(key == "DriverHeadPosX"){
    this->DriverHeadPosX=value;
    }
    else if(key == "DriverHeadPosY"){
    this->DriverHeadPosY=value;
    }
    else if(key == "DriverHeadPosZ"){
    this->DriverHeadPosZ=value;
    }
    else if(key == "DriverCarIdleRPM"){
    this->DriverCarIdleRPM=value;
    }
    else if(key == "DriverCarRedLine"){
    this->DriverCarRedLine=value;
    }
    else if(key == "DriverCarEngCylinderCount"){
    this->DriverCarEngCylinderCount=value;
    }
    else if(key == "DriverCarFuelKgPerLtr"){
    this->DriverCarFuelKgPerLtr=value;
    }
    else if(key == "DriverCarFuelMaxLtr"){
    this->DriverCarFuelMaxLtr=value;
    }
    else if(key == "DriverCarMaxFuelPct"){
    this->DriverCarMaxFuelPct=value;
    }
    else if(key == "DriverCarSLFirstRPM"){
    this->DriverCarSLFirstRPM=value;
    }
    else if(key == "DriverCarSLShiftRPM"){
    this->DriverCarSLShiftRPM=value;
    }
    else if(key == "DriverCarSLLastRPM"){
    this->DriverCarSLLastRPM=value;
    }
    else if(key == "DriverCarSLBlinkRPM"){
    this->DriverCarSLBlinkRPM=value;
    }
    else if(key == "DriverCarVersion"){
    this->DriverCarVersion=value;
    }
    else if(key == "DriverPitTrkPct"){
    this->DriverPitTrkPct=value;
    }
    else if(key == "DriverCarEstLapTime"){
    this->DriverCarEstLapTime=value;
    }
    else if(key == "DriverSetupName"){
    this->DriverSetupName=value;
    }
    else if(key == "DriverSetupIsModified"){
    this->DriverSetupIsModified=value;
    }
    else if(key == "DriverSetupLoadTypeName"){
    this->DriverSetupLoadTypeName=value;
    }
    else if(key == "DriverSetupPassedTech"){
    this->DriverSetupPassedTech=value;
    }
    else if(key == "DriverIncidentCount"){
    this->DriverIncidentCount=value;
    }else{
        qDebug() << "Unused var in DRIVERINFO " << key << "  -  " << value;
    }

}

QString DriverInfo::get_DriverCarIdx(){
return this->DriverCarIdx;
}
QString DriverInfo::get_DriverUserID(){
return this->DriverUserID;
}
QString DriverInfo::get_PaceCarIdx(){
return this->PaceCarIdx;
}
QString DriverInfo::get_DriverHeadPosX(){
return this->DriverHeadPosX;
}
QString DriverInfo::get_DriverHeadPosY(){
return this->DriverHeadPosY;
}
QString DriverInfo::get_DriverHeadPosZ(){
return this->DriverHeadPosZ;
}
QString DriverInfo::get_DriverCarIdleRPM(){
return this->DriverCarIdleRPM;
}
QString DriverInfo::get_DriverCarRedLine(){
return this->DriverCarRedLine;
}
QString DriverInfo::get_DriverCarEngCylinderCount(){
return this->DriverCarEngCylinderCount;
}
QString DriverInfo::get_DriverCarFuelKgPerLtr(){
return this->DriverCarFuelKgPerLtr;
}
QString DriverInfo::get_DriverCarFuelMaxLtr(){
return this->DriverCarFuelMaxLtr;
}
QString DriverInfo::get_DriverCarMaxFuelPct(){
return this->DriverCarMaxFuelPct;
}
QString DriverInfo::get_DriverCarSLFirstRPM(){
return this->DriverCarSLFirstRPM;
}
QString DriverInfo::get_DriverCarSLShiftRPM(){
return this->DriverCarSLShiftRPM;
}
QString DriverInfo::get_DriverCarSLLastRPM(){
return this->DriverCarSLLastRPM;
}
QString DriverInfo::get_DriverCarSLBlinkRPM(){
return this->DriverCarSLBlinkRPM;
}
QString DriverInfo::get_DriverCarVersion(){
return this->DriverCarVersion;
}
QString DriverInfo::get_DriverPitTrkPct(){
return this->DriverPitTrkPct;
}
QString DriverInfo::get_DriverCarEstLapTime(){
return this->DriverCarEstLapTime;
}
QString DriverInfo::get_DriverSetupName(){
return this->DriverSetupName;
}
QString DriverInfo::get_DriverSetupIsModified(){
return this->DriverSetupIsModified;
}
QString DriverInfo::get_DriverSetupLoadTypeName(){
return this->DriverSetupLoadTypeName;
}
QString DriverInfo::get_DriverSetupPassedTech(){
return this->DriverSetupPassedTech;
}
QString DriverInfo::get_DriverIncidentCount(){
return this->DriverIncidentCount;
}


