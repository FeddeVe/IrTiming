#include "global.h"

Global::Global(QObject *parent) : QObject(parent)
{
  this->br_end_lap.setColor(QColor::fromRgb(64,255,64));
  this->br_end_lap.setStyle(Qt::SolidPattern);
  this->br_start_lap.setColor(QColor::fromRgb(64,128,64));
  this->br_start_lap.setStyle(Qt::SolidPattern);
  this->br_pit_lap.setColor(QColor::fromRgb(64,64,200));
  this->br_pit_lap.setStyle(Qt::SolidPattern);
  this->br_my_row.setColor(QColor::fromRgb(64,64,64));
  this->br_my_row.setStyle(Qt::SolidPattern);
  this->br_offtrack.setColor(QColor::fromRgb(200,64,32));
  this->br_offtrack.setStyle(Qt::SolidPattern);
  this->better.setColor(QColor::fromRgb(64,172,64));
  this->worse.setColor(QColor::fromRgb(172,64,64));
  this->interval_count = 500;
}


QString Global::timetostring(float t){
  int time = t * 1000;
  if(time == -1000){
      return "0:00:000";
    }
  if (time < 0){
      time = time * -1;
    }

  int mils = time;
  int seconds = 0;
  int minutes = 0;
  while(mils >= 1000){
      mils = mils - 1000;
      seconds++;
      if(seconds >= 60){
          seconds = 0;
          minutes++;
        }
    }

  QString s_mils = QString::number(mils);
  if(mils < 100){
      s_mils = "0" + QString::number(mils);
    }else if(mils < 10){
      s_mils = "00" + QString::number(mils);
    }
    if(mils == 0){
      s_mils = "000";
    }
  QString s_seconds = QString::number(seconds);
  if(seconds < 10){
      s_seconds = "0" + QString::number(seconds);
    }

  if(time == 0){
      return "";
  }
  if(minutes == 0){
       return s_seconds +"."+ s_mils;
    }else{
  return QString::number(minutes) + ":"+ s_seconds +"."+ s_mils;
    }
}

QString Global::gaptostring(float t){
    int time = t * 1000;
    if(time == -1000){
        return "0:00:000";
      }
    if (time < 0){
        time = time * -1;
      }

    int mils = time;
    int seconds = 0;
    int minutes = 0;
    while(mils >= 1000){
        mils = mils - 1000;
        seconds++;
        if(seconds >= 60){
            seconds = 0;
            minutes++;
          }
      }

    mils = mils / 100;
    QString s_mils = QString::number(mils);
      if(mils == 0){
        s_mils = "0";
      }
    QString s_seconds = QString::number(seconds);
    if(seconds < 10){
        s_seconds = "0" + QString::number(seconds);
      }

    if(time == 0){
        return "";
    }
    if(minutes == 0){
         return s_seconds +"."+ s_mils;
      }else{
    return QString::number(minutes) + ":"+ s_seconds;
      }
}

QString Global::longtimetostring(float t){
  int time = t * 1000;
  int seconds = time / 1000;
  int minutes = 0;
  int hours = 0;
  while(seconds >= 60){
      seconds = seconds - 60;
      minutes++;
      if(minutes >= 60){
          minutes = 0;
          hours++;
        }
    }

  QString s_seconds = QString::number(seconds);
  if(seconds < 10){
      s_seconds = "0"+ QString::number(seconds);
    }
  QString s_minutes = QString::number(minutes);
  if(minutes < 10){
      s_minutes = "0"+ QString::number(minutes);
    }

  return QString::number(hours)+ ":"+ s_minutes +":"+ s_seconds;
}

QString Global::shorttimetostring(float t){
  int time = t * 1000;
  if(time == 0){
      return "";
  }
  bool minus = false;
  if(time < 0){
      minus = true;
      time = time * -1;
    }
  int mils = time;
  int seconds = 0;
  while(mils >= 1000){
      mils = mils - 1000;
      seconds++;
    }
  QString s_mils = QString::number(mils);
  if(mils < 100){
      s_mils = "0"+ QString::number(mils);
    }else if(mils < 10){
      s_mils = "00" + QString::number(mils);
    }


  if (minus){
      return QString::number(seconds)+"."+ s_mils;
    }else{
      return QString::number(seconds)+"."+ s_mils;
    }
}

int Global::qtimetomilsec(QTime time){
    int ms = time.hour() * 60;
   ms = (ms + time.minute()) * 60;
  ms = (ms + time.second()) * 1000;
  ms = ms + time.msec();
  return ms;
}

QTime Global::timemilsectoqtime(float t){
  int time = t * 1000;
  int hour = 0;
  int min = 0;
  int sec = 0;
  int mil = time;
  while(mil >= 1000){
      mil = mil - 1000;
      sec++;
      if(sec >= 60){
          sec = 0;
          min++;
          if(min >=60){
              min = 0;
              hour++;
            }
        }
    }

  QTime ret;
  ret.setHMS(hour, min, sec, mil);
  return ret;
}

QColor Global::randomcolor(int caridx){
  QColor colors;
  float currentHue = 0.3;
          for (int i = 0; i < caridx; i++){
                  //colors.push_back( QColor::fromHslF(currentHue, 1.0, 0.5) );
                  currentHue += 0.618033988749895f;
                //  currentHue = std::fmod(currentHue, 1.0f);
          }
          colors.fromHslF(currentHue, 1.0, 0.5);
          return colors;
}
