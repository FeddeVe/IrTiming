#include "gap_overlay_2.h"
#include "ui_gap_overlay_2.h"

Gap_Overlay_2::Gap_Overlay_2(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Gap_Overlay_2)
{
  ui->setupUi(this);
  this->mode = 0;
  this->windowid = 4;
  this->old_gap_updater = 0;
  this->setup_table();

}

Gap_Overlay_2::~Gap_Overlay_2()
{
  delete ui;
}

void Gap_Overlay_2::setup_table(){
  ui->tableWidget->setColumnCount(this->c_no_clms);
  ui->tableWidget->hideColumn(c_caridx);
  ui->tableWidget->setColumnWidth(c_status, 20);
  ui->tableWidget->horizontalHeader()->hide();
  ui->tableWidget->verticalHeader()->hide();
}

int Gap_Overlay_2::add_row(int CarIDX){
  int row = 0;
    ui->tableWidget->insertRow(row);
  for(int i = 0; i < this->c_no_clms; i++){
    switch(i){
      case c_caridx:
        {
          QTableWidgetItem *it = new QTableWidgetItem();
          it->setData(Qt::EditRole, CarIDX);
          ui->tableWidget->setItem(row, c_caridx, it);
        }
        break;
      case c_gap:
        {
          QTableWidgetItem *it = new Cus_Gap_Cel;
         //   QTableWidgetItem *it = new QTableWidgetItem;
          it->setData(0,0);
          QFont f;
          f = ui->tableWidget->font();
f.setPointSize(22);
it->setFont(f);
          ui->tableWidget->setItem(row, i, it);
        }
        break;
      case c_status:
        {
          QTableWidgetItem *it = new Cus_state_cell;
          it->setData(0,0);
          ui->tableWidget->setItem(row, i, it);
        }
        break;



      default:
        QTableWidgetItem *it = new Cus_default_Cell;
        it->setData(0, -1);
        ui->tableWidget->setItem(row, i, it);
break;

      }

    }

  return row;
}

int Gap_Overlay_2::get_row(int CarIDX){
  for(int zi = 0; zi < ui->tableWidget->rowCount(); zi++){
      int val = ui->tableWidget->item(zi, c_caridx)->data(0).toInt();
      if(val == CarIDX){
          return zi;
        }
    }
  return -1;
}

void Gap_Overlay_2::do_work(Core *c){
  ui->tableWidget->setSortingEnabled(false);
  Team *myteam = c->teams->myteam->my_team;
  if(myteam != nullptr){
      for(int z = 0; z < c->teams->teams.count(); z++){
          Team *dr = c->teams->teams[z];
          int row = this->get_row(dr->CarIDX);
          if((row != -1) && (dr->classid != myteam->classid)){
               ui->tableWidget->removeRow(row);
               qDebug() << "RowCOunt Remove:  " << ui->tableWidget->rowCount();

            }
          if(dr->classid == myteam->classid){
              if(row == -1){
                  row = this->add_row(dr->CarIDX);
                }

              for(int i = 0; i < c_no_clms; i++){
                  switch(i){
                    case c_status:
                      {
                      int state = 0;
                      if(dr->onpitroad){
                          state = 2;
                        }else if(dr->TrackSurface == 0){
                          state = 1;
                        }
                        ui->tableWidget->item(row, i)->setData(Qt::EditRole, state);
                      }
                      break;
                    case c_gap:
                      {
                        float gap = 0;
                        if(this->mode == race){
                            if(dr->Gaps[myteam->CarIDX]->ok){
                             //   ui->tableWidget->item(row, i)->setData(Qt::EditRole, dr->Gaps[myteam->CarIDX]->gap * -1);
                                ui->tableWidget->item(row, i)->setData(Qt::EditRole, dr->Gaps[myteam->CarIDX]->gap);
                                ui->tableWidget->item(row,i)->setData(Qt::UserRole+3, dr->Gaps[myteam->CarIDX]->time_mode);
                                ui->tableWidget->item(row,i)->setData(Qt::UserRole+4, dr->Gaps[myteam->CarIDX]->ok);
                              }else{
                                    ui->tableWidget->item(row, i)->setData(Qt::EditRole, myteam->Gaps[dr->CarIDX]->gap * -1);
                                    ui->tableWidget->item(row,i)->setData(Qt::UserRole+3, myteam->Gaps[dr->CarIDX]->time_mode);
                                    ui->tableWidget->item(row,i)->setData(Qt::UserRole+4, myteam->Gaps[dr->CarIDX]->ok);

                              }

                             ui->tableWidget->item(row,i)->setData(Qt::UserRole+5, 0);

                        }else{
                            if((dr->fastestlap != -1) && (myteam->fastestlap != -1)){
                                gap = myteam->Laps[myteam->fastestlap]->laptime - dr->Laps[dr->fastestlap]->laptime;
                                 ui->tableWidget->item(row, i)->setData(Qt::EditRole, gap);
                                 ui->tableWidget->item(row,i)->setData(Qt::UserRole+3, true);
                                 ui->tableWidget->item(row,i)->setData(Qt::UserRole+4, true);
                                  ui->tableWidget->item(row,i)->setData(Qt::UserRole+5, 1);
                            }
                        }

                        if(dr->CarIDX == myteam->CarIDX){
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                        }else{
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                        }

                      }
                      break;
                    case c_classposition:
                      {
                        if(this->mode == race){
                      ui->tableWidget->item(row, i)->setData(Qt::EditRole, dr->my_classposition);
                          }else{
                            int pos = dr->classposition;
                            if(pos == 0){
                                pos = 99;
                            }
                               ui->tableWidget->item(row, i)->setData(Qt::EditRole, pos);
                          }
                        if(dr->CarIDX == myteam->CarIDX){
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                        }else{
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                        }

                      }
                      break;




                }

            }

}
    }
     ui->tableWidget->setSortingEnabled(true);
     ui->tableWidget->sortByColumn(c_classposition, Qt::AscendingOrder);
     ui->tableWidget->resizeColumnsToContents();
     ui->tableWidget->resizeRowsToContents();

   // if(ui->checkBox_3->isChecked()){
     int calc_row = 0;

     QTableWidgetItem *it = ui->tableWidget->item(0, c_gap);
     if(it != nullptr){

         ui->tableWidget->scrollToItem(it);
     }
  }

}

void Gap_Overlay_2::set_mode(int mode){
  this->mode = mode;
}
void Gap_Overlay_2::window_loaded(bool okay, int windowid, int x, int y, int width, int height, int state){
    if(okay){
        if(this->windowid == windowid){
            if(state == 0){
                this->setWindowFlags(Qt::Window);
                this->show();
            }else if(state == 1){
                this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
                this->show();
            }
            this->move(x,y);
            this->resize(width, height);
            //this->setFixedSize(width, height);
        }
    }
}

void Gap_Overlay_2::on_core_update(Core *c){
  if(c->teams->gap_updater != this->old_gap_updater){
      this->old_gap_updater = c->teams->gap_updater;
      this->do_work(c);
  }

}

void Gap_Overlay_2::on_checkBox_stateChanged(int arg1)
{
  int state = 0;
  if(arg1 == 0){
      this->setWindowFlags(Qt::Window);
      this->show();
    }else{
      this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
      state = 1;
      this->show();
    }
  emit this->save_window(this->windowid, this->x(), this->y(),  this->width(), this->height(), state);
}
