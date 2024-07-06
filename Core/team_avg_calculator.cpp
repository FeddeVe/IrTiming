#include "team_avg_calculator.h"

Team_avg_calculator::Team_avg_calculator(QObject *parent, Team *refteam) : QObject(parent)
{
    this->avg_5_lap = new Lap(this);
    this->avg_10_lap = new Lap(this);
    this->avg_20_lap = new Lap(this);
    this->avg_40_lap = new Lap(this);
    this->dowork = false;
    this->refteam = refteam;
}

void Team_avg_calculator::do_work(){
    this->dowork = true;
}

void Team_avg_calculator::process(){
    /*
    this->exit = false;
    QEventLoop l;
    while(this->exit == false){
        if(this->dowork){
            int x_5 = 5;
            int x_10 = 10;
            int x_20 = 20;
            int x_40 = 40;
            int count_5 = 0;
            int count_10 = 0;
            int count_20 = 0;
            int count_40 = 0;
            int count_40_x = 41;
            int count_40_y = 0;
            float avg_5 = 0;
            float avg_10 = 0;
            float avg_20 = 0;
            float avg_40 = 0;
            QVector<int>count_interval;
            QVector<float>count_results;
            float calc_sessiontime = 0.0f;
            for(int y = 0; y < 501; y++){
                count_interval.push_back(0);
                count_results.push_back(0.0f);
              }

            int i = this->refteam->Laps.count();
            while(i > 0){
                i = i -1;
                 if((this->refteam->Laps[i]->laptime > 0)){
                if(count_5 < x_5){
                        avg_5 = avg_5 + this->refteam->Laps[i]->laptime;
                        count_5++;
                    }
                if(count_10 < x_10){
                    avg_10 = avg_10 + this->refteam->Laps[i]->laptime;
                    count_10++;
                }
                if(count_20 < x_20){
                    avg_20 = avg_20 + (this->refteam->Laps[i]->laptime);
                    count_20++;
                }
                if(count_40 < x_40){
                    avg_40 = avg_40 + (this->refteam->Laps[i]->laptime * count_40_x);
                    for(int y = 0; y < this->refteam->Laps[i]->intervals.count(); y++){
                        if(calc_sessiontime == 0.0f){
                          }else{
                            if((this->refteam->Laps[i]->intervals[y]->sessiontime > 0)){
                                float diff = this->refteam->Laps[i]->intervals[y]->sessiontime - calc_sessiontime;
                                if((diff > 0) && (diff < 10)){
                                    count_interval[y] = count_interval[y] + (diff * count_40_x);
                                    count_results[y] = count_results[y] + count_40_x;
                                  }
                              }
                          }
                         calc_sessiontime = this->refteam->Laps[i]->intervals[y];
                         QThread::usleep(1);
                      }
                    count_40_y = count_40_y + count_40_x;
                    count_40_x = count_40_x - 1;
                    count_40++;
                }
                 }else{
                     calc_sessiontime = 0.0f;
                 }
                 QThread::usleep(10);
            }

            if(count_5 > 0){
                avg_5 = avg_5 / count_5;
            }
            if(count_10 > 0){
                avg_10 = avg_10 / count_10;
            }
            if(count_20 > 0){
                avg_20 = avg_20 / count_20;
            }
            if(count_40_y > 0){
                avg_40 = avg_40 / count_40_y;
            }

            this->avg_5_lap->set_laptime(avg_5);
            this->avg_10_lap->set_laptime(avg_10);
            this->avg_20_lap->set_laptime(avg_20);
            this->avg_40_lap->set_laptime(avg_40);
            for(int i = 0; i < 500; i++){
                if(count_results[i] > 0){
                    this->avg_40_lap->intervals[i] = count_interval[i] / count_results[i];
                  }else{
                    this->avg_40_lap->intervals[i] = 0;
                  }
              }
            emit this->new_data(this->avg_5_lap, this->avg_10_lap, this->avg_20_lap, this->avg_40_lap);
            this->dowork = false;
        }
       l.processEvents();
       QThread::usleep(100);
    }
    */
}
