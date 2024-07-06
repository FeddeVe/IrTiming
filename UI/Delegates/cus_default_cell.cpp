#include "cus_default_cell.h"

Cus_default_Cell::Cus_default_Cell(QObject *parent) : QTableWidgetItem()
{
  this->oldvalue = "";
  this->gray_level = 0;
  this->ismy = false;
}

void Cus_default_Cell::setData(int role, const QVariant &value){
  if(role == Qt::EditRole){
      this->value = value;
      if(this->oldvalue != value){
          this->gray_level = 100;
          this->oldvalue = value;
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

QVariant Cus_default_Cell::data(int role) const{
  if(role == Qt::DisplayRole){
      return this->value;
    }else if(role == Qt::BackgroundRole){
      QColor ret;
      ret.setRgb(this->gray_level, this->gray_level, this->gray_level);
      if(this->ismy){
          if(this->gray_level < 32){
              ret.setRgb(32,32,32);
            }
        }
      return ret;
    }
  return QVariant();
}
