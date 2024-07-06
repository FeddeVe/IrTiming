#include "debug_timing.h"
#include "ui_debug_timing.h"

Debug_Timing::Debug_Timing(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Debug_Timing)
{
  this->refresh_delay = 0;
  ui->setupUi(this);
  this->setup_table();

}

Debug_Timing::~Debug_Timing()
{
  delete ui;
}

void Debug_Timing::setup_table(){

      ui->tableWidget->setColumnCount(no_clms + 251);
      for(int i = 0; i < no_clms; i++){
          QTableWidgetItem *it= new QTableWidgetItem;
          switch(i){
            case c_caridx:
              it->setText("CarIDX");
              ui->tableWidget->setHorizontalHeaderItem(i, it);
              break;
            case c_position:
              it->setText("POS");
              ui->tableWidget->setHorizontalHeaderItem(i, it);
              break;
            case c_classposition:
              it->setText("CLASSPOS");
              ui->tableWidget->setHorizontalHeaderItem(i, it);
              break;
            case c_carnr:
              it->setText("CARNR");
              ui->tableWidget->setHorizontalHeaderItem(i, it);
              break;
            case c_distance:
              it->setText("DISTANCE");
              ui->tableWidget->setHorizontalHeaderItem(i, it);
              break;
            case c_curlap:
              it->setText("CURLAP");
              ui->tableWidget->setHorizontalHeaderItem(i, it);
              break;
            case c_cursector:
              it->setText("CURSECTOR");
              ui->tableWidget->setHorizontalHeaderItem(i, it);
              break;
            case c_sector1:
              it->setText("S1");
              ui->tableWidget->setHorizontalHeaderItem(i, it);
              break;
            case c_sector2:
              it->setText("S2");
              ui->tableWidget->setHorizontalHeaderItem(i, it);
              break;
            case c_pitstop:
              it->setText("STOP");
              ui->tableWidget->setHorizontalHeaderItem(i, it);
              break;
            case c_pitlane:
              it->setText("PITLANE");
              ui->tableWidget->setHorizontalHeaderItem(i, it);
              break;

            }

  }
}

void Debug_Timing::on_core_update(Core *c){
  /*
  this->refresh_delay++;
  if(this->refresh_delay == 10){
  for(int i = 0; i < c->teams->teams.count(); i++){
      Team *t = c->teams->teams[i];
      int row = this->get_row(t->CarIDX);
      if(row == -1){
          this->create_row(t->CarIDX);
        }
      row = this->get_row(t->CarIDX);
      if(row == -1){
          qDebug() << "SOMETHING WRONG IN THE DEBUG TIMING";
        }else{
          for(int i = 0; i < no_clms + 251; i++){

              switch(i){

                case c_distance:
                 ui->tableWidget->item(row, i)->setData(0, t->distance_driven);
                  break;
                case c_curlap:
                  ui->tableWidget->item(row, i)->setData(0, t->curlap);
                   break;
                  break;
                case c_cursector:
                  ui->tableWidget->item(row, i)->setData(0, t->current_sector);
                   break;
                case c_sector1:
                  if((t->curlap -1 != -1) && (t->current_sector != -1)){
                   ui->tableWidget->item(row, i)->setData(0, t->Laps[t->curlap-1]->get_sectortime(0));

                    }
                   break;
                case c_sector2:
                  if((t->curlap -1 != -1) && (t->current_sector != -1)){
                  ui->tableWidget->item(row, i)->setData(0, t->Laps[t->curlap-1]->get_sectortime(1));

                    }
                   break;
                case c_pitstop:
                  if(t->Pitstops.count() > 0){
                      ui->tableWidget->item(row, i)->setData(0, t->Pitstops[t->Pitstops.count() -1]->get_stoptime());
                    }
                  break;
                case c_pitlane:
                  if(t->Pitstops.count() > 0){
                      ui->tableWidget->item(row, i)->setData(0, t->Pitstops[t->Pitstops.count() -1]->get_lanetime());
                    }
                  break;
                case c_lapsinstint:
                  if(t->Pitstops.count() > 0){
                      ui->tableWidget->item(row, i)->setData(0, t->laps_in_stint);
                    }
                  break;
                }
              if(i > no_clms){
                  int z = i - no_clms;
                  ui->tableWidget->item(row, i)->setData(0, t->avg_clean_laps->intervals[z]);
                }
        }
    }

    }
  this->refresh_delay = 0;

}
*/
}

int Debug_Timing::get_row(int caridx){
  for(int i = 0; i < ui->tableWidget->rowCount(); i++){
      if(ui->tableWidget->item(i, c_caridx) != nullptr){
      if(ui->tableWidget->item(i,c_caridx)->data(0).toInt() == caridx){
          return i;
        }
        }
    }
  return -1;
}

void Debug_Timing::create_row(int caridx){
  ui->tableWidget->setSortingEnabled(false);
  ui->tableWidget->setRowCount(ui->tableWidget->rowCount() +1);
  int row = ui->tableWidget->rowCount()-1;
  for(int i = 0; i < no_clms + 251; i++){

      QTableWidgetItem *it= new QTableWidgetItem;
      if(i == c_caridx){
          it->setData(0,caridx);
        }else{
           it->setData(0,0);
        }
       ui->tableWidget->setItem(row, i, it);
    }
}
