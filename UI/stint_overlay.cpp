#include "stint_overlay.h"
#include "ui_stint_overlay.h"

Stint_Overlay::Stint_Overlay(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Stint_Overlay)
{
  this->gl = new Global(this);
  ui->setupUi(this);
  this->setup_table();
  this->delay = 0;
  this->table_row = 0;
  this->windowid = 3;

}

Stint_Overlay::~Stint_Overlay()
{
  delete this->gl;
  delete ui;
}

void Stint_Overlay::on_core_update(Core *c){
  this->delay++;
  if(this->delay > 30){
      this->delay = 0;
      this->do_work(c);

    }
  this->table_row++;
  if(this->table_row == 120){
      this->table_row = 0;
      //this->set_table(c);
  }
}

void Stint_Overlay::setup_table(){
  ui->tableWidget->setRowCount(15);
  ui->tableWidget->setColumnCount(c_no_clms);
  QStringList hdr;
  for(int i = 0; i < c_no_clms; i++){
      hdr.push_back("");
    }
  for(int i = 0; i < ui->tableWidget->rowCount(); i++){
      for(int y = 0; y < c_no_clms; y++){
          switch(y){
            case c_laptime:
              {
                QTableWidgetItem *it = new cus_laptime_cell;
                it->setData(Qt::EditRole, 0);
                ui->tableWidget->setItem(i,y,it);
              }
              break;
            case c_laptime_vs_avg:
              {
                QTableWidgetItem *it= new Cus_Gap_Cell;
                it->setData(Qt::EditRole, 0);
                ui->tableWidget->setItem(i,y,it);
              }
            break;
            case c_laptime_vs_target:
              {
               QTableWidgetItem *it = new Cus_Gap_Cell;
               it->setData(Qt::EditRole, 0);
               ui->tableWidget->setItem(i,y,it);
              }
              break;
            case c_fuel:
              {
                QTableWidgetItem *it = new Cus_Fuel_Cell;
                it->setData(Qt::EditRole, 0);
                ui->tableWidget->setItem(i,y,it);
              }
              break;
            case c_fuel_vs_avg:
              {
                QTableWidgetItem *it = new Cus_Fuel_Cell;
                it->setData(Qt::EditRole, 0);
                ui->tableWidget->setItem(i,y,it);
              }
              break;
            case c_fuel_vs_target:
              {
                QTableWidgetItem *it = new Cus_Fuel_Cell;
                it->setData(Qt::EditRole, 0);
                ui->tableWidget->setItem(i,y,it);
              }
              break;
            default:
              {
                QTableWidgetItem *it = new QTableWidgetItem;
                it->setData(0,"-");
                ui->tableWidget->setItem(i,y,it);
              }
              break;
            }
        }
    }

 ui->tableWidget->setHorizontalHeaderLabels(hdr);
 ui->tableWidget->verticalHeader()->hide();
 ui->tableWidget->horizontalHeader()->hide();
 ui->tableWidget->hideColumn(c_lapsort);
 ui->tableWidget->hideColumn(c_lap);
 ui->tableWidget->hideColumn(c_laptime_vs_target);
 ui->tableWidget->hideColumn(c_fuel_vs_target);

 ui->tableWidget->hide();
}




void Stint_Overlay::do_work(Core *c){
  ui->label_2->setText(QString::number(round(c->teams->myteam->cur_fuel * 10) / 10) +" L ");
  ui->label->setText(QString::number(round(c->teams->myteam->fuel_laps * 10) / 10));
  ui->label_3->setText(QString::number(round(c->teams->myteam->fuel_till_end * 10) / 10) +" L ");
  ui->label_4->setText(QString::number(round(c->teams->myteam->fuel_avg_lap * 100) / 100) +" L ");
 if(c->teams->myteam->my_team != nullptr){
  //ui->label_5->setText(this->gl->timetostring(c->teams->myteam->my_team->avg_40_lap->laptime));
  }
 ui->label_6->setText(this->gl->longtimetostring(c->teams->myteam->fuel_time_in_stint));
 QPalette warning;
  warning.setColor(QPalette::Window, QColor::fromRgb(200,100,0));
QPalette stress;
 stress.setColor(QPalette::Window, QColor::fromRgb(200,0,0));
 QPalette nothing;
  nothing.setColor(QPalette::Window, QColor::fromRgb(0,0,0));

  if(c->teams->myteam->fuel_laps < 1){
        this->setPalette(stress);
    }else if(c->teams->myteam->fuel_laps < 3){
      this->setPalette(warning);
    }else{
      this->setPalette(nothing);
    }

  ui->label_14->setText(QString::number(round(c->teams->myteam->fuel_total_laps_stint * 10) / 10));

}

void Stint_Overlay::set_table(Core *c){
  if(c->teams->myteam->my_team != nullptr){
  int row =-1;
  Team *myteam = c->teams->myteam->my_team;
  int lap = myteam->curlap;

  while (lap > 0){
      lap = lap - 1;
      row = row + 1;
      if(row >= ui->tableWidget->rowCount()){
          break;
        }
      ui->tableWidget->item(row, c_lap)->setData(Qt::EditRole, lap);
      ui->tableWidget->item(row, c_laptime)->setData(Qt::EditRole, myteam->Laps[lap]->laptime);
      ui->tableWidget->item(row, c_laptime_vs_avg)->setData(Qt::UserRole+1, myteam->Laps[lap]->laptime);
     // ui->tableWidget->item(row, c_laptime_vs_avg)->setData(Qt::EditRole, myteam->avg_stint_lap->laptime);
      //
      //
      ui->tableWidget->item(row, c_fuel)->setData(Qt::EditRole, myteam->Laps[lap]->get_fuel_usage());
      ui->tableWidget->item(row, c_fuel_vs_avg)->setData(Qt::UserRole, myteam->Laps[lap]->get_fuel_usage());
      ui->tableWidget->item(row,c_fuel_vs_avg)->setData(Qt::EditRole, c->teams->myteam->fuel_avg_lap);
      //
      //


    }
    }
 ui->tableWidget->resizeColumnsToContents();
 ui->tableWidget->viewport()->update();
}

void Stint_Overlay::on_checkBox_stateChanged(int arg1)
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

void Stint_Overlay::window_loaded(bool okay, int windowid, int x, int y, int width, int height, int state){
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
