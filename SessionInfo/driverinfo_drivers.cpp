#include "driverinfo_drivers.h"

DriverInfo_Drivers::DriverInfo_Drivers(QObject *parent) : QObject(parent)
{

}

void DriverInfo_Drivers::set_value(QString key, QString value){
  if(key == "CarIdx"){
  this->CarIdx=value;
  }
  else if(key == "UserName"){
  this->UserName=value;
  }
  else if(key == "AbbrevName"){
  this->AbbrevName=value;
  }
  else if(key == "Initials"){
  this->Initials=value;
  }
  else if(key == "UserID"){
  this->UserID=value;
  }
  else if(key == "TeamID"){
  this->TeamID=value;
  }
  else if(key == "TeamName"){
  //this->TeamName=value;
  }
  else if(key == "CarNumber"){
  this->CarNumber=value;
  }
  else if(key == "CarNumberRaw"){
  this->CarNumberRaw=value;
  }
  else if(key == "CarPath"){
  this->CarPath=value;
  }
  else if(key == "CarClassID"){
  this->CarClassID=value;
  }
  else if(key == "CarID"){
  this->CarID=value;
  }
  else if(key == "CarIsPaceCar"){
  this->CarIsPaceCar=value;
  }
  else if(key == "CarIsAI"){
  this->CarIsAI=value;
  }
  else if(key == "CarScreenName"){
  this->CarScreenName=value;
  }
  else if(key == "CarScreenNameShort"){
  this->CarScreenNameShort=value;
  }
  else if(key == "CarClassShortName"){
  this->CarClassShortName=value;
  }
  else if(key == "CarClassRelSpeed"){
  this->CarClassRelSpeed=value;
  }
  else if(key == "CarClassLicenseLevel"){
  this->CarClassLicenseLevel=value;
  }
  else if(key == "CarClassMaxFuelPct"){
  this->CarClassMaxFuelPct=value;
  }
  else if(key == "CarClassWeightPenalty"){
  this->CarClassWeightPenalty=value;
  }
  else if(key == "CarClassPowerAdjust"){
  this->CarClassPowerAdjust=value;
  }
  else if(key == "CarClassDryTireSetLimit"){
  this->CarClassDryTireSetLimit=value;
  }
  else if(key == "CarClassColor"){
  this->CarClassColor=value;
  }
  else if(key == "IRating"){
  this->IRating=value;
  }
  else if(key == "LicLevel"){
  this->LicLevel=value;
  }
  else if(key == "LicSubLevel"){
  this->LicSubLevel=value;
  }
  else if(key == "LicString"){
  this->LicString=value;
  }
  else if(key == "LicColor"){
  this->LicColor=value;
  }
  else if(key == "IsSpectator"){
  this->IsSpectator=value;
  }
  else if(key == "CarDesignStr"){
  this->CarDesignStr=value;
  }
  else if(key == "HelmetDesignStr"){
  this->HelmetDesignStr=value;
  }
  else if(key == "SuitDesignStr"){
  this->SuitDesignStr=value;
  }
  else if(key == "CarNumberDesignStr"){
  this->CarNumberDesignStr=value;
  }
  else if(key == "CarSponsor_1"){
  this->CarSponsor_1=value;
  }
  else if(key == "CarSponsor_2"){
  this->CarSponsor_2=value;
  }
  else if(key == "ClubName"){
  this->ClubName=value;
  }
  else if(key == "DivisionName"){
  this->DivisionName=value;
  }
  else if(key == "CurDriverIncidentCount"){
  this->CurDriverIncidentCount=value;
  }
  else if(key == "TeamIncidentCount"){
  this->TeamIncidentCount=value;
  }else{
      qDebug() << "Unused var in DriverInfo_Drivers " << key << "  -  "<< value;
    }
}

QString DriverInfo_Drivers::get_CarIdx(){
return this->CarIdx;
}
QString DriverInfo_Drivers::get_UserName(){
return this->UserName;
}
QString DriverInfo_Drivers::get_AbbrevName(){
return this->AbbrevName;
}
QString DriverInfo_Drivers::get_Initials(){
return this->Initials;
}
QString DriverInfo_Drivers::get_UserID(){
return this->UserID;
}
QString DriverInfo_Drivers::get_TeamID(){
return this->TeamID;
}
QString DriverInfo_Drivers::get_TeamName(){
return this->TeamName;
}
QString DriverInfo_Drivers::get_CarNumber(){
return this->CarNumber;
}
QString DriverInfo_Drivers::get_CarNumberRaw(){
return this->CarNumberRaw;
}
QString DriverInfo_Drivers::get_CarPath(){
return this->CarPath;
}
QString DriverInfo_Drivers::get_CarClassID(){
return this->CarClassID;
}
QString DriverInfo_Drivers::get_CarID(){
return this->CarID;
}
QString DriverInfo_Drivers::get_CarIsPaceCar(){
return this->CarIsPaceCar;
}
QString DriverInfo_Drivers::get_CarIsAI(){
return this->CarIsAI;
}
QString DriverInfo_Drivers::get_CarScreenName(){
return this->CarScreenName;
}
QString DriverInfo_Drivers::get_CarScreenNameShort(){
return this->CarScreenNameShort;
}
QString DriverInfo_Drivers::get_CarClassShortName(){
return this->CarClassShortName;
}
QString DriverInfo_Drivers::get_CarClassRelSpeed(){
return this->CarClassRelSpeed;
}
QString DriverInfo_Drivers::get_CarClassLicenseLevel(){
return this->CarClassLicenseLevel;
}
QString DriverInfo_Drivers::get_CarClassMaxFuelPct(){
return this->CarClassMaxFuelPct;
}
QString DriverInfo_Drivers::get_CarClassWeightPenalty(){
return this->CarClassWeightPenalty;
}
QString DriverInfo_Drivers::get_CarClassPowerAdjust(){
return this->CarClassPowerAdjust;
}
QString DriverInfo_Drivers::get_CarClassDryTireSetLimit(){
return this->CarClassDryTireSetLimit;
}
QString DriverInfo_Drivers::get_CarClassColor(){
return this->CarClassColor;
}
QString DriverInfo_Drivers::get_IRating(){
return this->IRating;
}
QString DriverInfo_Drivers::get_LicLevel(){
return this->LicLevel;
}
QString DriverInfo_Drivers::get_LicSubLevel(){
return this->LicSubLevel;
}
QString DriverInfo_Drivers::get_LicString(){
return this->LicString;
}
QString DriverInfo_Drivers::get_LicColor(){
return this->LicColor;
}
QString DriverInfo_Drivers::get_IsSpectator(){
return this->IsSpectator;
}
QString DriverInfo_Drivers::get_CarDesignStr(){
return this->CarDesignStr;
}
QString DriverInfo_Drivers::get_HelmetDesignStr(){
return this->HelmetDesignStr;
}
QString DriverInfo_Drivers::get_SuitDesignStr(){
return this->SuitDesignStr;
}
QString DriverInfo_Drivers::get_CarNumberDesignStr(){
return this->CarNumberDesignStr;
}
QString DriverInfo_Drivers::get_CarSponsor_1(){
return this->CarSponsor_1;
}
QString DriverInfo_Drivers::get_CarSponsor_2(){
return this->CarSponsor_2;
}
QString DriverInfo_Drivers::get_ClubName(){
return this->ClubName;
}
QString DriverInfo_Drivers::get_DivisionName(){
return this->DivisionName;
}
QString DriverInfo_Drivers::get_CurDriverIncidentCount(){
return this->CurDriverIncidentCount;
}
QString DriverInfo_Drivers::get_TeamIncidentCount(){
return this->TeamIncidentCount;
}

