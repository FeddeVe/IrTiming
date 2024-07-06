#include "weekendoptions.h"

WeekendOptions::WeekendOptions(QObject *parent) : QObject(parent)
{

}

void WeekendOptions::set_value(QString key, QString value){
  if(key == "NumStarters"){
  this->NumStarters=value;
  }
  else if(key == "StartingGrid"){
  this->StartingGrid=value;
  }
  else if(key == "QualifyScoring"){
  this->QualifyScoring=value;
  }
  else if(key == "CourseCautions"){
  this->CourseCautions=value;
  }
  else if(key == "StandingStart"){
  this->StandingStart=value;
  }
  else if(key == "ShortParadeLap"){
  this->ShortParadeLap=value;
  }
  else if(key == "Restarts"){
  this->Restarts=value;
  }
  else if(key == "WeatherType"){
  this->WeatherType=value;
  }
  else if(key == "Skies"){
  this->Skies=value;
  }
  else if(key == "WindDirection"){
  this->WindDirection=value;
  }
  else if(key == "WindSpeed"){
  this->WindSpeed=value;
  }
  else if(key == "WeatherTemp"){
  this->WeatherTemp=value;
  }
  else if(key == "RelativeHumidity"){
  this->RelativeHumidity=value;
  }
  else if(key == "FogLevel"){
  this->FogLevel=value;
  }
  else if(key == "TimeOfDay"){
  this->TimeOfDay=value;
  }
  else if(key == "Date"){
  this->Date=value;
  }
  else if(key == "EarthRotationSpeedupFactor"){
  this->EarthRotationSpeedupFactor=value;
  }
  else if(key == "Unofficial"){
  this->Unofficial=value;
  }
  else if(key == "CommercialMode"){
  this->CommercialMode=value;
  }
  else if(key == "NightMode"){
  this->NightMode=value;
  }
  else if(key == "IsFixedSetup"){
  this->IsFixedSetup=value;
  }
  else if(key == "StrictLapsChecking"){
  this->StrictLapsChecking=value;
  }
  else if(key == "HasOpenRegistration"){
  this->HasOpenRegistration=value;
  }
  else if(key == "HardcoreLevel"){
  this->HardcoreLevel=value;
  }
  else if(key == "NumJokerLaps"){
  this->NumJokerLaps=value;
  }
  else if(key == "IncidentLimit"){
  this->IncidentLimit=value;
  }
  else if(key == "FastRepairsLimit"){
  this->FastRepairsLimit=value;
  }
  else if(key == "GreenWhiteCheckeredLimit"){
  this->GreenWhiteCheckeredLimit=value;
  }else{
      qDebug() <<"Unused var in WEEKENDOPTIONS " << key << " - " << value;
    }


}

QString WeekendOptions::get_NumStarters(){
return this->NumStarters;
}
QString WeekendOptions::get_StartingGrid(){
return this->StartingGrid;
}
QString WeekendOptions::get_QualifyScoring(){
return this->QualifyScoring;
}
QString WeekendOptions::get_CourseCautions(){
return this->CourseCautions;
}
QString WeekendOptions::get_StandingStart(){
return this->StandingStart;
}
QString WeekendOptions::get_ShortParadeLap(){
return this->ShortParadeLap;
}
QString WeekendOptions::get_Restarts(){
return this->Restarts;
}
QString WeekendOptions::get_WeatherType(){
return this->WeatherType;
}
QString WeekendOptions::get_Skies(){
return this->Skies;
}
QString WeekendOptions::get_WindDirection(){
return this->WindDirection;
}
QString WeekendOptions::get_WindSpeed(){
return this->WindSpeed;
}
QString WeekendOptions::get_WeatherTemp(){
return this->WeatherTemp;
}
QString WeekendOptions::get_RelativeHumidity(){
return this->RelativeHumidity;
}
QString WeekendOptions::get_FogLevel(){
return this->FogLevel;
}
QString WeekendOptions::get_TimeOfDay(){
return this->TimeOfDay;
}
QString WeekendOptions::get_Date(){
return this->Date;
}
QString WeekendOptions::get_EarthRotationSpeedupFactor(){
return this->EarthRotationSpeedupFactor;
}
QString WeekendOptions::get_Unofficial(){
return this->Unofficial;
}
QString WeekendOptions::get_CommercialMode(){
return this->CommercialMode;
}
QString WeekendOptions::get_NightMode(){
return this->NightMode;
}
QString WeekendOptions::get_IsFixedSetup(){
return this->IsFixedSetup;
}
QString WeekendOptions::get_StrictLapsChecking(){
return this->StrictLapsChecking;
}
QString WeekendOptions::get_HasOpenRegistration(){
return this->HasOpenRegistration;
}
QString WeekendOptions::get_HardcoreLevel(){
return this->HardcoreLevel;
}
QString WeekendOptions::get_NumJokerLaps(){
return this->NumJokerLaps;
}
QString WeekendOptions::get_IncidentLimit(){
return this->IncidentLimit;
}
QString WeekendOptions::get_FastRepairsLimit(){
return this->FastRepairsLimit;
}
QString WeekendOptions::get_GreenWhiteCheckeredLimit(){
return this->GreenWhiteCheckeredLimit;
}

