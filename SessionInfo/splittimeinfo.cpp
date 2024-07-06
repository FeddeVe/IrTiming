#include "splittimeinfo.h"

SplitTimeInfo::SplitTimeInfo(QObject *parent) : QObject(parent)
{

}

void SplitTimeInfo::set_sector(int sectorindex, QString key, QString value){
  if(this->sectors.count() <= sectorindex){
      SplitTimeInfo_Sectors *sec = new SplitTimeInfo_Sectors(this);
      this->sectors.push_back(sec);
    }

  this->sectors[sectorindex]->set_value(key, value);
}

void SplitTimeInfo::clear(){
  for(int i = 0;i < this->sectors.count(); i++){
      delete this->sectors[i];
    }
  this->sectors.clear();
}
