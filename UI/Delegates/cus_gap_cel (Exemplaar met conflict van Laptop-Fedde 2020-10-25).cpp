#include "cus_gap_cel.h"

Cus_Gap_Cel::Cus_Gap_Cel(QObject *parent) : QTableWidgetItem()
{
 this->gap = 0.0f;
 this->gap_index = 0;
  this->old_gap = 0.0f;
  this->red = 0;
  this->green = 0;
  this->gl = new Global();
 this->ismy = false;
 this->ok = false;
 this->time_mode = false;
 this->practicemode = 0;
    this->avg_gap_index = 0;
}

Cus_Gap_Cel::~Cus_Gap_Cel(){
  delete this->gl;
}

void Cus_Gap_Cel::setData(int role, const QVariant &value){
  if(role == Qt::EditRole){

      this->gap = value.toFloat();
      this->avg_gap_index++;
      if(this->avg_gap_index >= 30){
          this->avg_gap_index = 0;
      }
      this->avg_gap_arr[this->avg_gap_index] = value.toFloat();

      /*
      if(this->gap < 0){
          //car is ahead
          if(this->gap > this->old_gap){
              if(red > 0){
                  red = red - 2;
                 }else{
                  green = green + 2;
                }
            }else if(this->gap < this->old_gap){
              if(green > 0){
                  green = green - 2;
                }else{
                  red = red + 2;
                }
            }else{
              if(this->green > 0){
                  this->green = this->green - 2;
                }
              if(this->red > 0){
                  this->red = this->red - 2;
                }
            }
        }else{
         // car is behind
          if(this->gap > this->old_gap){
              if(red > 0){
                  red = red - 2;
                 }else{
                  green = green + 2;
                }
            }else if(this->gap < this->old_gap){
              if(green > 0){
                  green = green - 2;
                }else{
                  red = red + 2;
                }
            }else{
              if(this->green > 0){
                  this->green = this->green - 2;
                }
              if(this->red > 0){
                  this->red = this->red - 2;
                }
            }
        }
      if(this->green > 231){
          this->green = 231;
        }
      if(this->green < 0){
          this->green = 0;
        }
      if(this->red > 231){
          this->red = 231;
        }
      if(this->red < 0){
          this->red = 0;
        }


      this->old_gap = this->gap;
      */
    }else if(role == Qt::UserRole+2){
      ismy = value.toBool();
    }else if(role == Qt::UserRole+3){
      this->time_mode = value.toBool();
    }else if(role == Qt::UserRole+4){
      this->ok = value.toBool();
    }else if(role == Qt::UserRole+5){
      this->practicemode= value.toInt();
    }

}

QVariant Cus_Gap_Cel::data(int role) const{
  if(role == Qt::UserRole + 1){
      return this->red;
    }else if(role == Qt::UserRole + 2){
      return this->green;
    }else if(role == Qt::DisplayRole){
      if(this->ismy){
          return QString("");
      }else{
          if(this->ok){
              if(this->time_mode){
                if(this->practicemode == 0){
      return gl->gaptostring(this->gap);
                }else{
                    return gl->timetostring(this->gap);
                }
                }else{
                  QString ret = QString::number(round(this->gap *10) / 10) +" L";
                  return ret;
                }
            }
         return QString("");
      }
    }else if(role == Qt::ForegroundRole){
      QColor ret;
      //if(this->red > 0){
     //    ret.setRgb(this->red, 231-this->red, 231-this->red);
      //  }else if(this->green > 0){
      //    ret.setRgb(231-this->green, this->green, 231-this->green);
      //  }else{
      float avg = 0;
      for(int i = 0; i < 30; i++){
            avg = avg + this->avg_gap_arr[i];
        }
      avg = avg /30;
      float diff = this->gap - avg;

      if(diff < -0.16){
          diff = diff + 0.16;
          diff = diff * -1;
          diff = diff / 2;
          int r = diff * 200;
          if(r > 200){
              r = 200;
          }
          ret.setRgb(200-r,200-r,200);
      }else if(diff > 0.16) {
         diff = diff -0.16;
            diff = diff / 2;
         int r = diff * 200;
         if(r > 200){
             r = 200;
         }
         ret.setRgb(200,200-r,200);
      }else{
           ret.setRgb(200,200,200);
      }

      //  }
      return ret;
    }else if(role == Qt::BackgroundRole){
      QColor ret;
      ret.setRgb(0,0,0);
      if(this->ismy){
          ret.setRgb(64,64,64);
        }
      return ret;
    }else if(role == Qt::FontRole){
      QFont f;
      f.setPointSize(18);
      f.setBold(true);
      return f;
    }
  return QVariant();
}
