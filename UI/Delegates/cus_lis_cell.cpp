#include "cus_lis_cell.h"

Cus_lis_cell::Cus_lis_cell(QObject *parent) : QTableWidgetItem()
{
    this->laps_in_stint = -1;
  this->ismy = false;
}

void Cus_lis_cell::setData(int role, const QVariant &value){
    if(role == Qt::EditRole){
        this->laps_in_stint = value.toInt();
        int red = this->laps_in_stint * 10;
        if(red > 200){
            red = 200;
        }else if(red < 0){
            red = 0;
        }
        this->clr.setRgb(200, 200-red, 200-red);
    }else if(role == Qt::UserRole+2){
        ismy = value.toBool();
      }

}

QVariant Cus_lis_cell::data(int role) const{
    if(role == Qt::DisplayRole){
        return this->laps_in_stint;
    }else if(role == Qt::ForegroundRole){
        return this->clr;
    }else if(role == Qt::BackgroundRole){
        QColor ret;
        ret.setRgb(0,0,0);
        if(this->ismy){
            ret.setRgb(32,32,32);
          }
        return ret;
      }
    return QVariant();
}
