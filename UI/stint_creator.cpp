#include "stint_creator.h"
#include "ui_stint_creator.h"

Stint_Creator::Stint_Creator(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Stint_Creator)
{
  ui->setupUi(this);
}

Stint_Creator::~Stint_Creator()
{
  delete ui;
}

void Stint_Creator::on_pushButton_clicked()
{
    //Calculations
  QTime tmp = ui->timeEdit->time();
  int t = ((tmp.hour() * 60) + tmp.minute()) * 60;

  this->running_time = t;
  tmp = ui->timeEdit_2->time();
  float tt = (tmp.minute() * 60) + tmp.second() +(tmp.msec() / 1000);
  this->avg_laptime = tt;
  this->avg_fuel_consumption = ui->doubleSpinBox->value();
  this->time_lost_pitlane = ui->doubleSpinBox_2->value();
  this->refuel_rate = ui->doubleSpinBox_3->value();
  this->tire_change_time= ui->doubleSpinBox_4->value();
  this->x_minutes_length = ui->spinBox->value() * 60;
  this->max_fuel = ui->spinBox_2->value();

  this->med_laps = this->max_fuel / this->avg_fuel_consumption;
  this->low_laps = this->med_laps -1;
  this->high_laps = this->med_laps +1;
  this->x_min_laps = this->x_minutes_length / this->avg_laptime;

  this->setup_table();

  this->calc_low();
}

void Stint_Creator::setup_table(){
  ui->tableWidget_2->clear();
  ui->tableWidget_2->setColumnCount(4);
  ui->tableWidget_2->setRowCount(4);
  QStringList hdr;
  hdr.push_back("X-Minutes");
  hdr.push_back(QString::number(this->low_laps) + " Laps");
  hdr.push_back(QString::number(this->med_laps) + " Laps");
  hdr.push_back(QString::number(this->high_laps) + " Laps");
  ui->tableWidget_2->setHorizontalHeaderLabels(hdr);

  QTableWidgetItem *it = new QTableWidgetItem;
  it->setData(0, "AVG Fuel");
  ui->tableWidget_2->setVerticalHeaderItem(0, it);
  it = new QTableWidgetItem;
  it->setData(0, "Total Pitstops");
  ui->tableWidget_2->setVerticalHeaderItem(1, it);
  it = new QTableWidgetItem;
  it->setData(0, "Total Pitstop Time");
  ui->tableWidget_2->setVerticalHeaderItem(2, it);
  it= new QTableWidgetItem;
  it->setData(0, "Total Laps");
  ui->tableWidget_2->setVerticalHeaderItem(3, it);

}

void Stint_Creator::calc_low(){
  float min_avg_fuel = this->max_fuel / this->low_laps;
  float max_avg_fuel = this->max_fuel / (this->low_laps + 0.99);



  int bp = 0;
  bp++;


}
