#include "weekendinfo.h"

WeekendInfo::WeekendInfo(QObject *parent) : QObject(parent)
{

}

void WeekendInfo::set_value(QString key, QString value){
  if(key == "TrackName"){
  this->TrackName=value;
  }
  else if(key == "TrackID"){
      if(this->TrackID.toInt() != value.toInt()){
          emit this->new_track_id();
        }
    this->TrackID=value;
  }
  else if(key == "TrackLength"){
  this->TrackLength=value;
  }
  else if(key == "TrackDisplayName"){
  this->TrackDisplayName=value;
  }
  else if(key == "TrackDisplayShortName"){
  this->TrackDisplayShortName=value;
  }
  else if(key == "TrackConfigName"){
  this->TrackConfigName=value;
  }
  else if(key == "TrackCity"){
  this->TrackCity=value;
  }
  else if(key == "TrackCountry"){
  this->TrackCountry=value;
  }
  else if(key == "TrackAltitude"){
  this->TrackAltitude=value;
  }
  else if(key == "TrackLatitude"){
  this->TrackLatitude=value;
  }
  else if(key == "TrackLongitude"){
  this->TrackLongitude=value;
  }
  else if(key == "TrackNorthOffset"){
  this->TrackNorthOffset=value;
  }
  else if(key == "TrackNumTurns"){
  this->TrackNumTurns=value;
  }
  else if(key == "TrackPitSpeedLimit"){
  this->TrackPitSpeedLimit=value;
  }
  else if(key == "TrackType"){
  this->TrackType=value;
  }
  else if(key == "TrackDirection"){
  this->TrackDirection=value;
  }
  else if(key == "TrackWeatherType"){
  this->TrackWeatherType=value;
  }
  else if(key == "TrackSkies"){
  this->TrackSkies=value;
  }
  else if(key == "TrackSurfaceTemp"){
  this->TrackSurfaceTemp=value;
  }
  else if(key == "TrackAirTemp"){
  this->TrackAirTemp=value;
  }
  else if(key == "TrackAirPressure"){
  this->TrackAirPressure=value;
  }
  else if(key == "TrackWindVel"){
  this->TrackWindVel=value;
  }
  else if(key == "TrackWindDir"){
  this->TrackWindDir=value;
  }
  else if(key == "TrackRelativeHumidity"){
  this->TrackRelativeHumidity=value;
  }
  else if(key == "TrackFogLevel"){
  this->TrackFogLevel=value;
  }
  else if(key == "TrackCleanup"){
  this->TrackCleanup=value;
  }
  else if(key == "TrackDynamicTrack"){
  this->TrackDynamicTrack=value;
  }
  else if(key == "TrackVersion"){
  this->TrackVersion=value;
  }
  else if(key == "SeriesID"){
  this->SeriesID=value;
  }
  else if(key == "SeasonID"){
  this->SeasonID=value;
  }
  else if(key == "SessionID"){
  this->SessionID=value;
  }
  else if(key == "SubSessionID"){
  this->SubSessionID=value;
  }
  else if(key == "LeagueID"){
  this->LeagueID=value;
  }
  else if(key == "Official"){
  this->Official=value;
  }
  else if(key == "RaceWeek"){
  this->RaceWeek=value;
  }
  else if(key == "EventType"){
  this->EventType=value;
  }
  else if(key == "Category"){
  this->Category=value;
  }
  else if(key == "SimMode"){
  this->SimMode=value;
  }
  else if(key == "TeamRacing"){
  this->TeamRacing=value;
  }
  else if(key == "MinDrivers"){
  this->MinDrivers=value;
  }
  else if(key == "MaxDrivers"){
  this->MaxDrivers=value;
  }
  else if(key == "DCRuleSet"){
  this->DCRuleSet=value;
  }
  else if(key == "QualifierMustStartRace"){
  this->QualifierMustStartRace=value;
  }
  else if(key == "NumCarClasses"){
  this->NumCarClasses=value;
  }
  else if(key == "NumCarTypes"){
  this->NumCarTypes=value;
  }
  else if(key == "HeatRacing"){
  this->HeatRacing=value;
  }
  else if(key == "BuildType"){
  this->BuildType=value;
  }
  else if(key == "BuildTarget"){
  this->BuildTarget=value;
  }
  else if(key == "BuildVersion"){
  this->BuildVersion=value;
  }else{
      qDebug() << "SESSIONINFO UNUSED VAR  "<< key <<" - " << value;
    }

}

QString WeekendInfo::get_TrackName(){
return this->TrackName;
}
QString WeekendInfo::get_TrackID(){
return this->TrackID;
}
QString WeekendInfo::get_TrackLength(){
return this->TrackLength;
}
QString WeekendInfo::get_TrackDisplayName(){
return this->TrackDisplayName;
}
QString WeekendInfo::get_TrackDisplayShortName(){
return this->TrackDisplayShortName;
}
QString WeekendInfo::get_TrackConfigName(){
return this->TrackConfigName;
}
QString WeekendInfo::get_TrackCity(){
return this->TrackCity;
}
QString WeekendInfo::get_TrackCountry(){
return this->TrackCountry;
}
QString WeekendInfo::get_TrackAltitude(){
return this->TrackAltitude;
}
QString WeekendInfo::get_TrackLatitude(){
return this->TrackLatitude;
}
QString WeekendInfo::get_TrackLongitude(){
return this->TrackLongitude;
}
QString WeekendInfo::get_TrackNorthOffset(){
return this->TrackNorthOffset;
}
QString WeekendInfo::get_TrackNumTurns(){
return this->TrackNumTurns;
}
QString WeekendInfo::get_TrackPitSpeedLimit(){
return this->TrackPitSpeedLimit;
}
QString WeekendInfo::get_TrackType(){
return this->TrackType;
}
QString WeekendInfo::get_TrackDirection(){
return this->TrackDirection;
}
QString WeekendInfo::get_TrackWeatherType(){
return this->TrackWeatherType;
}
QString WeekendInfo::get_TrackSkies(){
return this->TrackSkies;
}
QString WeekendInfo::get_TrackSurfaceTemp(){
return this->TrackSurfaceTemp;
}
QString WeekendInfo::get_TrackAirTemp(){
return this->TrackAirTemp;
}
QString WeekendInfo::get_TrackAirPressure(){
return this->TrackAirPressure;
}
QString WeekendInfo::get_TrackWindVel(){
return this->TrackWindVel;
}
QString WeekendInfo::get_TrackWindDir(){
return this->TrackWindDir;
}
QString WeekendInfo::get_TrackRelativeHumidity(){
return this->TrackRelativeHumidity;
}
QString WeekendInfo::get_TrackFogLevel(){
return this->TrackFogLevel;
}
QString WeekendInfo::get_TrackCleanup(){
return this->TrackCleanup;
}
QString WeekendInfo::get_TrackDynamicTrack(){
return this->TrackDynamicTrack;
}
QString WeekendInfo::get_TrackVersion(){
return this->TrackVersion;
}
QString WeekendInfo::get_SeriesID(){
return this->SeriesID;
}
QString WeekendInfo::get_SeasonID(){
return this->SeasonID;
}
QString WeekendInfo::get_SessionID(){
return this->SessionID;
}
QString WeekendInfo::get_SubSessionID(){
return this->SubSessionID;
}
QString WeekendInfo::get_LeagueID(){
return this->LeagueID;
}
QString WeekendInfo::get_Official(){
return this->Official;
}
QString WeekendInfo::get_RaceWeek(){
return this->RaceWeek;
}
QString WeekendInfo::get_EventType(){
return this->EventType;
}
QString WeekendInfo::get_Category(){
return this->Category;
}
QString WeekendInfo::get_SimMode(){
return this->SimMode;
}
QString WeekendInfo::get_TeamRacing(){
return this->TeamRacing;
}
QString WeekendInfo::get_MinDrivers(){
return this->MinDrivers;
}
QString WeekendInfo::get_MaxDrivers(){
return this->MaxDrivers;
}
QString WeekendInfo::get_DCRuleSet(){
return this->DCRuleSet;
}
QString WeekendInfo::get_QualifierMustStartRace(){
return this->QualifierMustStartRace;
}
QString WeekendInfo::get_NumCarClasses(){
return this->NumCarClasses;
}
QString WeekendInfo::get_NumCarTypes(){
return this->NumCarTypes;
}
QString WeekendInfo::get_HeatRacing(){
return this->HeatRacing;
}
QString WeekendInfo::get_BuildType(){
return this->BuildType;
}
QString WeekendInfo::get_BuildTarget(){
return this->BuildTarget;
}
QString WeekendInfo::get_BuildVersion(){
return this->BuildVersion;
}


