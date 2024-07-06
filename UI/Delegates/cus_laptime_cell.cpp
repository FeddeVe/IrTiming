#include "cus_laptime_cell.h"

cus_laptime_cell::cus_laptime_cell(QObject *parent) : QTableWidgetItem()
{
    this->laptime = 0;
    this->graylevel = 0;
    this->gl = new Global();
    this->ismy = false;
}

cus_laptime_cell::~cus_laptime_cell(){
    delete this->gl;
}

void cus_laptime_cell::setData(int role, const QVariant &value){
    if(role == Qt::EditRole){
        if(this->laptime != value.toFloat()){
            this->laptime = value.toFloat();
            this->graylevel = 100;
        }else{
            this->graylevel = this->graylevel - 5;
            if(this->graylevel < 0){
                this->graylevel = 0;
            }
        }
    }else if(role == Qt::UserRole+2){
        this->ismy = value.toBool();
    }
}

QVariant cus_laptime_cell::data(int role) const{
    if(role == Qt::DisplayRole){
        return this->gl->timetostring(this->laptime);
    }else if(role == Qt::BackgroundRole){
        QColor ret;
        ret.setRgb(this->graylevel, this->graylevel, this->graylevel);
        if((ismy) && (graylevel < 32)){
            ret.setRgb(32,32,32);
        }
        return ret;
    }
    return QVariant();
}

