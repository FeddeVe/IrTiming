#include "cus_driverlaps_cell.h"

Cus_DriverLaps_Cell::Cus_DriverLaps_Cell(QObject *parent) : QTableWidgetItem()
{
  this->laps_driven = -1;
  this->ismy = false;
  this->gray_level = 0;
}

void Cus_DriverLaps_Cell::setData(int role, const QVariant &value){
  if(role == Qt::EditRole){
      if(this->laps_driven != value.toInt()){
          this->gray_level = 100;
          this->laps_driven = value.toInt();
        }else{
          this->gray_level = this->gray_level - 5;
          if(this->gray_level < 0){
              this->gray_level = 0;
            }
        }
    }else if(role == Qt::UserRole +2){
      this->ismy = value.toBool();
    }
}

QVariant Cus_DriverLaps_Cell::data(int role) const{
  if(role == Qt::DisplayRole){
      if(this->laps_driven >= 0){
      return this->laps_driven;
        }else{
          return QString("");
        }
    }else if(role == Qt::BackgroundRole){
      QColor ret;
      ret.setRgb(this->gray_level, this->gray_level, this->gray_level);
      if(this->ismy){
          if(this->gray_level < 32){
              ret.setRgb(32,32,32);
            }
        }
      return ret;
    }else if(role == Qt::ForegroundRole){
       QColor ret;
      if(this->laps_driven >= 0){

      int val = this->laps_driven * 10;
      if(val > 200){
          val = 200;
        }
      ret.setRgb(200,200,val);

        }else{
          ret.setRgb(200,200,200);
        }
       return ret;
    }
  return QVariant();
}
