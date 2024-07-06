#ifndef MYTEAM_H
#define MYTEAM_H

#include <QObject>

#include "SessionInfo/sessionstring.h"
#include "Ir/ir_tel_vars.h"
#include "Core/team.h"
#include "Core/teams.h"
#include "Core/tire_wear.h"

QT_FORWARD_DECLARE_CLASS(Team);

class MyTeam : public QObject
{
    Q_OBJECT
public:
    explicit MyTeam(QObject *parent = nullptr);

  bool carontrack;
  int caridx;
  double time_remain;
  int laps_remain;
  float cur_fuel;
  float fuel_level_start;
  float fuel_distance_start;
  float fuel_avg_lap;
  float fuel_laps;
  float fuel_lap_level;
  float fuel_till_end;
  float fuel_add_laps;
  float fuel_session_time;
  float fuel_time_in_stint;
  float fuel_start_time;
  float fuel_total_laps_stint;

  float lf;
  float rf;
  float lr;
  float rr;

 // QVector<Tire_Wear*>tire_wear;

  Team *my_team;

  void reset();
  void update_from_telemetry(ir_tel_vars *v);
  void update_from_sessionstring(SessionString *s);
  void set_my_team(Team *t);

  void calc_fuel(ir_tel_vars *v);

public slots:
  void set_tyrewear(float lf, float rf, float lr, float rr, int lap);


signals:

private:
int delay;

};

#endif // MYTEAM_H
