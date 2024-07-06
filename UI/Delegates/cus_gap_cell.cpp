#include "cus_gap_cell.h"

Cus_Gap_Cell::Cus_Gap_Cell(QObject *parent) : QTableWidgetItem()
{
    this->ismy = false;
    this->this_lap = 0.0f;
    this->compare_lap = 0.0f;
    this->graylevel = 0;
    this->gl = new Global();
}

Cus_Gap_Cell::~Cus_Gap_Cell(){
    delete this->gl;
}

void Cus_Gap_Cell::setData(int role, const QVariant &value){
    if(role == Qt::EditRole){
        if(this->this_lap != value.toFloat()){
        this->this_lap = value.toFloat();
         this->graylevel = 100;
        }else{
            this->graylevel = this->graylevel -5;
            if(this->graylevel < 0){
                this->graylevel = 0;
            }
        }
    }else if(role == Qt::UserRole + 1){
        this->compare_lap = value.toFloat();
    }else if(role == Qt::UserRole + 2){
        this->ismy = value.toBool();
    }
}

QVariant Cus_Gap_Cell::data(int role) const{
    if(role == Qt::DisplayRole){
        if(this->ismy){
            return gl->timetostring(this->this_lap);
        }else{
            if((this->this_lap == 0) || (this->compare_lap == 0)){
                return gl->shorttimetostring(0);
            }else{
        return gl->shorttimetostring(this->this_lap - this->compare_lap);
            }
   }
        }else if(role == Qt::ForegroundRole){
        QColor ret;
        ret.setRgb(231,231,231);
        if(this->ismy == false){
        int diff = (this->this_lap * 1000) - (this->compare_lap * 1000);
        diff = diff / 2;
        if(diff < 0){
             diff = diff *-1;
            diff = diff - 16;
            int r = diff;
            if(r > 200){
                r = 200;
            }
            if(r < 0){
                r = 0;
            }
            ret.setRgb(200, 200-r, 200-r);
        }else if(diff > 0){

            diff = diff + 16;
            int g = diff;
            if (g > 200){
                g = 200;
            }
            if(g < 0){
                g = 0;
            }
            ret.setRgb(200-g, 200,200-g);
        }
       }
        return ret;
    }else if(role == Qt::BackgroundRole){
        QColor ret;
        ret.setRgb(this->graylevel,this->graylevel,this->graylevel);
        if(this->ismy){
            if(this->graylevel < 32){
               ret.setRgb(32,32,32);
            }
        }
        return ret;
    }

    return QVariant();
}

