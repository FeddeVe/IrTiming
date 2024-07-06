#include "splittimeinfo_sectors.h"

SplitTimeInfo_Sectors::SplitTimeInfo_Sectors(QObject *parent) : QObject(parent)
{

}

void SplitTimeInfo_Sectors::set_value(QString key, QString value){
  if(key == "SectorNum"){
  this->SectorNum=value;
  }
  else if(key == "SectorStartPct"){
  this->SectorStartPct=value;
  }else{
      qDebug() << "Unused Var in splittimeinfo_sectors " << key << " - " << value;
    }

}

QString SplitTimeInfo_Sectors::get_SectorNum(){
return this->SectorNum;
}
QString SplitTimeInfo_Sectors::get_SectorStartPct(){
return this->SectorStartPct;
}
