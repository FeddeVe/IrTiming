#include "cus_fuel_cell.h"

Cus_Fuel_Cell::Cus_Fuel_Cell(QObject *parent) : QTableWidgetItem()
{
  this->fuel = 0;
  this->compare_fuel = 0;
}

void Cus_Fuel_Cell::setData(int role, const QVariant &value){
  if(role == Qt::EditRole){
      this->fuel = value.toFloat();
    }else if(role == Qt::UserRole){
      this->compare_fuel = value.toFloat();
    }

}

QVariant Cus_Fuel_Cell::data(int role) const{
  if(role == Qt::DisplayRole){
      if(this->compare_fuel == 0){
          QString ret = QString::number(round(this->fuel * 100) / 100);
          return ret;
        }else{
          float diff = this->compare_fuel - this->fuel;
          QString ret = QString::number(round(diff * 100)/ 100);
          return ret;
        }
    }else if(role == Qt::ForegroundRole){
      QColor ret;
      ret.setRgb(200,200,200);
      if(this->compare_fuel != 0){
          float diff = this->compare_fuel - this->fuel;
          if(diff > 0){
              ret.setRgb(200,0,0);
            }else if(diff < 0){
              ret.setRgb(0,200,0);
            }
          return ret;
        }
    }
  return QVariant();
}
