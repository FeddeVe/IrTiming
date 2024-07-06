#include "sessioninfo_session.h"

SessionInfo_Session::SessionInfo_Session(QObject *parent) : QObject(parent)
{

}

void SessionInfo_Session::set_resultposition_value(int index, QString key, QString value){
    while(this->resultpositions.count() <= index){
        SessionInfo_ResultPosition *r = new SessionInfo_ResultPosition(this);
        this->resultpositions.push_back(r);
    }

    this->resultpositions[index]->set_value(key, value);
}

void SessionInfo_Session::clear(){
    for(int i = 0; i < this->resultpositions.count(); i++){
        delete this->resultpositions[i];
    }
    this->resultpositions.clear();
}

SessionInfo_ResultPosition *SessionInfo_Session::get_resultposition(int CarIDX){
  for(int i = 0; i < this->resultpositions.count(); i++){
      if(this->resultpositions[i]->get_CarIdx().toInt() == CarIDX){
          return this->resultpositions[i];
        }
    }
  return nullptr;
}

void SessionInfo_Session::set_value(QString key, QString value){
    if(key == "SessionNum"){
    this->SessionNum=value;
    }
    else if(key == "SessionLaps"){
    this->SessionLaps=value;
    }
    else if(key == "SessionTime"){
    this->SessionTime=value;
    }
    else if(key == "SessionNumLapsToAvg"){
    this->SessionNumLapsToAvg=value;
    }
    else if(key == "SessionType"){
    this->SessionType=value;
    }
    else if(key == "SessionTrackRubberState"){
    this->SessionTrackRubberState=value;
    }
    else if(key == "SessionName"){
    this->SessionName=value;
    }
    else if(key == "SessionSubType"){
    this->SessionSubType=value;
    }
    else if(key == "SessionSkipped"){
    this->SessionSkipped=value;
    }
    else if(key == "SessionRunGroupsUsed"){
    this->SessionRunGroupsUsed=value;
    }
    else if(key == "ResultsAverageLapTime"){
    this->ResultsAverageLapTime=value;
    }
    else if(key == "ResultsNumCautionFlags"){
    this->ResultsNumCautionFlags=value;
    }
    else if(key == "ResultsNumCautionLaps"){
    this->ResultsNumCautionLaps=value;
    }
    else if(key == "ResultsNumLeadChanges"){
    this->ResultsNumLeadChanges=value;
    }
    else if(key == "ResultsLapsComplete"){
    this->ResultsLapsComplete=value;
    }
    else if(key == "ResultsOfficial"){
    this->ResultsOfficial=value;
    }else{
        qDebug() << "UNUSED VARIABLE in SESSION - " << key;
    }

}

QString SessionInfo_Session::get_SessionNum(){
return this->SessionNum;
}
QString SessionInfo_Session::get_SessionLaps(){
return this->SessionLaps;
}
QString SessionInfo_Session::get_SessionTime(){
return this->SessionTime;
}
QString SessionInfo_Session::get_SessionNumLapsToAvg(){
return this->SessionNumLapsToAvg;
}
QString SessionInfo_Session::get_SessionType(){
return this->SessionType;
}
QString SessionInfo_Session::get_SessionTrackRubberState(){
return this->SessionTrackRubberState;
}
QString SessionInfo_Session::get_SessionName(){
return this->SessionName;
}
QString SessionInfo_Session::get_SessionSubType(){
return this->SessionSubType;
}
QString SessionInfo_Session::get_SessionSkipped(){
return this->SessionSkipped;
}
QString SessionInfo_Session::get_SessionRunGroupsUsed(){
return this->SessionRunGroupsUsed;
}
QString SessionInfo_Session::get_ResultsAverageLapTime(){
return this->ResultsAverageLapTime;
}
QString SessionInfo_Session::get_ResultsNumCautionFlags(){
return this->ResultsNumCautionFlags;
}
QString SessionInfo_Session::get_ResultsNumCautionLaps(){
return this->ResultsNumCautionLaps;
}
QString SessionInfo_Session::get_ResultsNumLeadChanges(){
return this->ResultsNumLeadChanges;
}
QString SessionInfo_Session::get_ResultsLapsComplete(){
return this->ResultsLapsComplete;
}
QString SessionInfo_Session::get_ResultsOfficial(){
return this->ResultsOfficial;
}
