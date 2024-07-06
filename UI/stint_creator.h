#ifndef STINT_CREATOR_H
#define STINT_CREATOR_H

#include <QWidget>

namespace Ui {
  class Stint_Creator;
}

class Stint_Creator : public QWidget
{
  Q_OBJECT

public:
  explicit Stint_Creator(QWidget *parent = nullptr);
  ~Stint_Creator();

private slots:
  void on_pushButton_clicked();

private:
  Ui::Stint_Creator *ui;

  int running_time; //in seconds
  float avg_laptime; //in seconds;
  float avg_fuel_consumption; //in liters
  float max_fuel;
  float time_lost_pitlane;
  float refuel_rate;
  float tire_change_time;
  int x_minutes_length;
  int med_laps;
  int low_laps;
  int high_laps;
  int x_min_laps;

  void calc_low();
  void calc_med();
  void calc_high();
  void calc_x_min();

  void setup_table();


};

#endif // STINT_CREATOR_H
