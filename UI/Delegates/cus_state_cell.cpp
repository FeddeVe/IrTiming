#include "cus_state_cell.h"

Cus_state_cell::Cus_state_cell(QObject *parent) : QTableWidgetItem()
{
  this->lap_type = 0;
  this->color_value_1 = 0;
  this->color_value_2 = 0;
}

void Cus_state_cell::setData(int role, const QVariant &value){
  if(role == Qt::EditRole){
      this->lap_type = value.toInt();
      if(this->lap_type == Lap::l_offtrack){
          this->color_value_1 = 255;
          this->color_value_2 = 0;
        }else if(this->lap_type == Lap::l_pit){
          this->color_value_2 = 255;
          this->color_value_1 = 0;
        }else{
          this->color_value_1 = this->color_value_1 - 20;
          this->color_value_2 = this->color_value_2 - 20;
          if(this->color_value_1 < 0){
              this->color_value_2 = 0;
            }
          if(this->color_value_2 < 0){
              this->color_value_2 = 0;
            }
        }
    }
}

QVariant Cus_state_cell::data(int role) const{
  if(role == Qt::DisplayRole){
      QString ret = " ";
      if(this->lap_type == Lap::l_pit){
          ret = "P";
        }else if(this->lap_type == Lap::l_offtrack){
          ret = "O";
        }
      return ret;
    }else if(role == Qt::BackgroundRole){
      QColor ret;
      ret.setRgb(0,0,0);
      if(this->lap_type == Lap::l_pit){
          ret.setRgb(32,32,175);
        }
      if(this->lap_type == Lap::l_offtrack){
          ret.setRgb(175,32,16);
        }
      return ret;
    }
  return QVariant();
}
