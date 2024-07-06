#include "gap_overlay.h"
#include "ui_gap_overlay.h"

Gap_Overlay::Gap_Overlay(QWidget *parent, Core *refcore) :
  QWidget(parent),
  ui(new Ui::Gap_Overlay)
{
    this->refcore = refcore;
  ui->setupUi(this);
  this->setup_table();
  this->mode = race;
  this->windowid = 1;
  this->delay = 0;
  this->old_gap_updater = 0;
}

Gap_Overlay::~Gap_Overlay()
{
  delete ui;
}

void Gap_Overlay::setup_table(){
  ui->tableWidget->setRowCount(0);
  ui->tableWidget->setColumnCount(c_no_clms);
  QStringList hdr_items;
  for(int i = 0; i < c_no_clms; i++){
      hdr_items.push_back("");
    }
  ui->tableWidget->setHorizontalHeaderLabels(hdr_items);
 // ui->tableWidget->sortByColumn(c_classposition, Qt::AscendingOrder);
  ui->tableWidget->hideColumn(c_caridx);
  ui->tableWidget->setColumnWidth(c_status, 20);
  ui->tableWidget->horizontalHeader()->hide();
  ui->tableWidget->verticalHeader()->hide();

}

int Gap_Overlay::add_row(int CarIDX){
  int row = 0;
 // ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    ui->tableWidget->insertRow(row);
  qDebug() << "RowCOunt Add:  " << ui->tableWidget->rowCount();
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
    case c_lapsinstint:
    {
        QTableWidgetItem *it = new Cus_lis_cell;
        it->setData(0,0);
        ui->tableWidget->setItem(row, i, it);
    }
        break;
    case c_lastlap:
    {
        QTableWidgetItem *it = new cus_laptime_cell;
        it->setData(0,0);
        ui->tableWidget->setItem(row, i, it);
    }
        break;
    case c_avgxlap:
    {
        QTableWidgetItem *it = new cus_laptime_cell;
        it->setData(0,0);
        ui->tableWidget->setItem(row, i, it);
    }
        break;
    case c_calclap:
    {
        QTableWidgetItem *it = new cus_laptime_cell;
        it->setData(0,0);
        ui->tableWidget->setItem(row, i, it);
    }
        break;
      case c_avgstintlap:
      {
          QTableWidgetItem *it = new cus_laptime_cell;
          it->setData(0,0);
          ui->tableWidget->setItem(row, i, it);
      }
          break;
    case c_avgxlap_diff:
    {
        QTableWidgetItem *it = new Cus_Gap_Cell;
        it->setData(0,0);
        ui->tableWidget->setItem(row, i, it);
    }
        break;
    case c_lastlap_diff:
    {
        QTableWidgetItem *it = new Cus_Gap_Cell;
        it->setData(0,0);
        ui->tableWidget->setItem(row, i, it);
    }
        break;
    case c_calclap_diff:
    {
        QTableWidgetItem *it = new Cus_Gap_Cell;
        it->setData(0,0);
        ui->tableWidget->setItem(row, i, it);
    }
        break;
      case c_avgstintlap_diff:
        {
          QTableWidgetItem *it = new Cus_Gap_Cell;
          it->setData(0,0);
          ui->tableWidget->setItem(row, i, it);
        }
        break;
    case c_name:
    {
        QTableWidgetItem *it = new Cus_default_Cell;
        it->setData(0, -1);
        QFont f = ui->label->font();
        it->setFont(f);
        ui->tableWidget->setItem(row, i, it);
    }
        break;
      case c_driverlaps:
        {
          QTableWidgetItem *it = new Cus_DriverLaps_Cell;
          it->setData(0,-1);
          ui->tableWidget->setItem(row, i, it);
        }
        break;
      case c_drivercontlaps:
        {
          QTableWidgetItem *it = new Cus_DriverLaps_Cell;
          it->setData(0,-1);
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

void Gap_Overlay::on_core_update(Core *c){
  if(c->teams->gap_updater != this->old_gap_updater){
      this->old_gap_updater = c->teams->gap_updater;
      this->do_work();
  }

}

int Gap_Overlay::get_row(int CarIDX){
  for(int zi = 0; zi < ui->tableWidget->rowCount(); zi++){
      int val = ui->tableWidget->item(zi, c_caridx)->data(0).toInt();
      if(val == CarIDX){
          return zi;
        }
    }
  return -1;
}

void Gap_Overlay::do_work(){
  ui->tableWidget->setSortingEnabled(false);
  Team *myteam = this->refcore->teams->myteam->my_team;
  if(myteam != nullptr){
      for(int z = 0; z < this->refcore->teams->teams.count(); z++){
          Team *dr = this->refcore->teams->teams[z];
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
                    case c_name:
                      {
                        QString driver = "";
                        if(dr->current_driver != -1){
                            driver = dr->Drivers[dr->current_driver]->AbbrevName;
                      }
                        ui->tableWidget->item(row, i)->setData(Qt::EditRole, driver);
                        if(dr->CarIDX == myteam->CarIDX){
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                        }else{
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                        }
                      }
                      break;
                    case c_driverlaps:
                      {
                        int laps_driven = -1;
                        if(dr->current_driver != -1){
                            laps_driven = dr->Drivers[dr->current_driver]->total_laps_driven;
                      }
                        ui->tableWidget->item(row, i)->setData(Qt::EditRole, laps_driven);
                        if(dr->CarIDX == myteam->CarIDX){
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                        }else{
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                        }
                      }
                      break;
                    case c_drivercontlaps:
                      {
                        int laps_driven = -1;
                        if(dr->current_driver != -1){
                            laps_driven = dr->Drivers[dr->current_driver]->continues_laps_driven;
                      }
                        ui->tableWidget->item(row, i)->setData(Qt::EditRole, laps_driven);
                        if(dr->CarIDX == myteam->CarIDX){
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                        }else{
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                        }
                      }
                      break;
                  case c_lapsinstint:
                  {
                      ui->tableWidget->item(row, i)->setData(Qt::EditRole, dr->laps_in_stint);

                      if(dr->CarIDX == myteam->CarIDX){
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                      }else{
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                      }

                  }
                      break;
                  case c_lastlap:
                  {
                      float curlap = 0.0f;
                      int y = dr->Laps.count();
                      while(y > 0){
                          y = y -1;
                          curlap = dr->Laps[y]->laptime;
                          if(curlap > 0){
                              break;
                          }
                      }
                      ui->tableWidget->item(row,i)->setData(Qt::EditRole, curlap);
                      if(dr->CarIDX == myteam->CarIDX){
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                      }else{
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                      }
                    }
                      break;
                  case c_avgxlap:
                  {
                      if(this->mode == race){
                      ui->tableWidget->item(row,i)->setData(Qt::EditRole, dr->avg_5_lap->laptime);
                      }else{
                          if(dr->fastestlap != -1){
                              ui->tableWidget->item(row, i)->setData(Qt::EditRole, dr->Laps[dr->fastestlap]->laptime);
                          }
                      }
                      if(dr->CarIDX == myteam->CarIDX){
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                      }else{
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                      }
                  }
                  break;
                  case c_calclap:
                  {
                      if(dr->avg_40_lap != nullptr){
                      ui->tableWidget->item(row, i)->setData(Qt::EditRole, dr->avg_40_lap->laptime);
                      if(dr->CarIDX == myteam->CarIDX){
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                      }else{
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                      }
                      }
                  }
                      break;
                    case c_avgstintlap:{
                        ui->tableWidget->item(row,i)->setData(Qt::EditRole, dr->avg_20_lap->laptime);
                        if(dr->CarIDX == myteam->CarIDX){
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                        }else{
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                        }
                      }
                      break;
                  case c_lastlap_diff:
                  {
                      float curlap = 0.0f;
                      int y = dr->Laps.count();
                      while(y > 0){
                          y = y -1;
                          curlap = dr->Laps[y]->laptime;
                          if(curlap > 0){
                              break;
                          }
                      }
                      ui->tableWidget->item(row,i)->setData(Qt::EditRole, curlap);
                      curlap = 0.0f;
                      y = myteam->Laps.count();
                      while(y > 0){
                          y= y -1;
                          curlap = myteam->Laps[y]->laptime;
                          if(curlap > 0){
                              break;
                          }
                      }
                      ui->tableWidget->item(row, i)->setData(Qt::UserRole+1, curlap);
                      if(dr->CarIDX == myteam->CarIDX){
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                      }else{
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                      }
                  }
                      break;
                  case c_avgxlap_diff:
                  {
                      ui->tableWidget->item(row,i)->setData(Qt::EditRole, dr->avg_5_lap->laptime);
                      ui->tableWidget->item(row,i)->setData(Qt::UserRole +1, myteam->avg_5_lap->laptime);
                      if(dr->CarIDX == myteam->CarIDX){
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                      }else{
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                      }

                  }
                      break;

                    case c_avgstintlap_diff:
                      {
                        ui->tableWidget->item(row,i)->setData(Qt::EditRole, dr->avg_20_lap->laptime);
                        ui->tableWidget->item(row,i)->setData(Qt::UserRole +1, myteam->avg_20_lap->laptime);
                        if(dr->CarIDX == myteam->CarIDX){
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                        }else{
                            ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                        }
                      }
                      break;
                  case c_calclap_diff:
                  {
                      if((dr->avg_40_lap != nullptr) && (myteam->avg_40_lap != nullptr)){
                      ui->tableWidget->item(row,i)->setData(Qt::EditRole, dr->avg_40_lap->laptime);
                      ui->tableWidget->item(row,i)->setData(Qt::UserRole +1, myteam->avg_40_lap->laptime);
                      if(dr->CarIDX == myteam->CarIDX){
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, true);
                      }else{
                          ui->tableWidget->item(row,i)->setData(Qt::UserRole +2, false);
                      }
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

    if(ui->checkBox_3->isChecked()){
     int calc_row = this->get_row(myteam->CarIDX);
     int myrow = calc_row;
     if(myrow > 4){
         myrow = myrow - 4;
     }else{
         myrow = 0;
       }
     QTableWidgetItem *it = ui->tableWidget->item(myrow, c_gap);
     if(it != nullptr){

         ui->tableWidget->scrollToItem(it);
     }
     myrow = calc_row + 2;
     if(myrow > ui->tableWidget->rowCount() -1){
         myrow = ui->tableWidget->rowCount()-1;
     }
     it = ui->tableWidget->item(myrow, c_gap);
     ui->tableWidget->item(myrow, c_gap);
          if(it != nullptr){
              ui->tableWidget->scrollToItem(it);
          }
    }
  }



}

void Gap_Overlay::on_checkBox_stateChanged(int arg1)
{
 if(arg1 == 0){
     ui->tableWidget->hideColumn(c_lastlap);
     ui->tableWidget->hideColumn(c_avgxlap);
     ui->tableWidget->hideColumn(c_avgstintlap);
     ui->tableWidget->hideColumn(c_calclap);
   }else{
     ui->tableWidget->showColumn(c_lastlap);
     ui->tableWidget->showColumn(c_avgxlap);
     ui->tableWidget->showColumn(c_avgstintlap);
     ui->tableWidget->showColumn(c_calclap);
   }
}

void Gap_Overlay::on_checkBox_2_stateChanged(int arg1)
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

void Gap_Overlay::on_comboBox_currentIndexChanged(int index)
{
    this->mode = index;
  emit this->mode_changed(mode);
}

void Gap_Overlay::window_loaded(bool okay, int windowid, int x, int y, int width, int height, int state){
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

void Gap_Overlay::load_position(){
  emit this->load_window(this->windowid);
}
