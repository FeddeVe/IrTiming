#include "sessioninfo.h"

SessionInfo::SessionInfo(QObject *parent) : QObject(parent)
{

}

SessionInfo_Session *SessionInfo::Get_Session(int sessionnum){
  for(int i = 0; i < this->Sessions.count(); i++){
      if(this->Sessions[i]->get_SessionNum().toInt() == sessionnum){
          return this->Sessions[i];
        }
    }
  return nullptr;
}

void SessionInfo::Put_From_Yaml(int sessionindex, QString key, QString value){
    while(sessionindex + 1 > this->Sessions.length()){
        SessionInfo_Session *s = new SessionInfo_Session(this);
        this->Sessions.push_back(s);
    }
   this->Sessions[sessionindex]->set_value(key, value);
}

void SessionInfo::Put_resultposition_from_yaml(int sessionindex, int resultpositionindex, QString key, QString value){
    while(sessionindex + 1 > this->Sessions.length()){
        SessionInfo_Session *s = new SessionInfo_Session(this);
        this->Sessions.push_back(s);
    }
    this->Sessions[sessionindex]->set_resultposition_value(resultpositionindex, key, value);
}

void SessionInfo::clear(){
    for(int i =0;i < this->Sessions.count(); i++){
        this->Sessions[i]->clear();
        delete this->Sessions[i];
    }
    this->Sessions.clear();
}
