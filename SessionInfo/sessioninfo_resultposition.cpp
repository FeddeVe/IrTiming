#include "sessioninfo_resultposition.h"

SessionInfo_ResultPosition::SessionInfo_ResultPosition(QObject *parent) : QObject(parent)
{

}

void SessionInfo_ResultPosition::set_value(QString key, QString value){
    if(key == "Position"){
    this->Position=value;
    }
    else if(key == "ClassPosition"){
    this->ClassPosition=value;
    }
    else if(key == "CarIdx"){
    this->CarIdx=value;
    }
    else if(key == "Lap"){
    this->Lap=value;
    }
    else if(key == "Time"){
    this->Time=value;
    }
    else if(key == "FastestLap"){
    this->FastestLap=value;
    }
    else if(key == "FastestTime"){
    this->FastestTime=value;
    }
    else if(key == "LastTime"){
    this->LastTime=value;
    }
    else if(key == "LapsLed"){
    this->LapsLed=value;
    }
    else if(key == "LapsComplete"){
    this->LapsComplete=value;
    }
    else if(key == "JokerLapsComplete"){
    this->JokerLapsComplete=value;
    }
    else if(key == "LapsDriven"){
    this->LapsDriven=value;
    }
    else if(key == "Incidents"){
    this->Incidents=value;
    }
    else if(key == "ReasonOutId"){
    this->ReasonOutId=value;
    }
    else if(key == "ReasonOutStr"){
    this->ReasonOutStr=value;
    }else{
        qDebug() << "Unused VAR sessionifo_resultposition" << key <<" - " << value;
    }

}

QString SessionInfo_ResultPosition::get_Position(){
return this->Position;
}
QString SessionInfo_ResultPosition::get_ClassPosition(){
return this->ClassPosition;
}
QString SessionInfo_ResultPosition::get_CarIdx(){
return this->CarIdx;
}
QString SessionInfo_ResultPosition::get_Lap(){
return this->Lap;
}
QString SessionInfo_ResultPosition::get_Time(){
return this->Time;
}
QString SessionInfo_ResultPosition::get_FastestLap(){
return this->FastestLap;
}
QString SessionInfo_ResultPosition::get_FastestTime(){
return this->FastestTime;
}
QString SessionInfo_ResultPosition::get_LastTime(){
return this->LastTime;
}
QString SessionInfo_ResultPosition::get_LapsLed(){
return this->LapsLed;
}
QString SessionInfo_ResultPosition::get_LapsComplete(){
return this->LapsComplete;
}
QString SessionInfo_ResultPosition::get_JokerLapsComplete(){
return this->JokerLapsComplete;
}
QString SessionInfo_ResultPosition::get_LapsDriven(){
return this->LapsDriven;
}
QString SessionInfo_ResultPosition::get_Incidents(){
return this->Incidents;
}
QString SessionInfo_ResultPosition::get_ReasonOutId(){
return this->ReasonOutId;
}
QString SessionInfo_ResultPosition::get_ReasonOutStr(){
return this->ReasonOutStr;
}


