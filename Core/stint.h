#ifndef STINT_H
#define STINT_H

#include <QObject>
#include <QVector>

#include "Core/stint_pitstop.h"

class Stint : public QObject
{
  Q_OBJECT
public:
  explicit Stint(QObject *parent = nullptr);

  int stint_type; //0=timed, 1=laps
  int Lap_Offset; //Laps offset from avg_fuel;
  float avg_laptime; //in seconds;
  float avg_fuel_consumption; //in liters
  float max_fuel;
  float time_lost_pitlane;
  float refuel_rate;
  float tire_change_time;
  int x_minutes_length;
  int current_stint;
  int next_pitstop;


  QVector<Stint_Pitstop*>Pitstops;

  void do_calc(int curlap, float curfuel, float avg_fuel_per_lap, float stint_starttime, float current_sessiontime);

signals:

public slots:
};

#endif // STINT_H
