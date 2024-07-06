#ifndef TEAM_H
#define TEAM_H

#include <QObject>
#include <QVector>
#include <QEventLoop>
#include <QThread>

#include "Core/driver.h"
#include "Core/pitstop.h"
#include "Core/lap.h"
#include "Ir/ir_tel_vars.h"
#include "SessionInfo/sessionstring.h"
#include "Core/track.h"
#include "Core/teams.h"
#include "Core/gap.h"
#include "Core/team_avg_calculator.h"
#include "global.h"


QT_FORWARD_DECLARE_CLASS(Teams);
QT_FORWARD_DECLARE_CLASS(Team_avg_calculator);

class Team : public QObject
{
    Q_OBJECT
public:
    explicit Team(QObject *parent = nullptr, int CarIDX = -1, Track *reftrack = nullptr);

    int CarIDX;
    int curlap;
    float lap_dct;
    float old_lapdistance;
    float old_sessiontime;
    float distance_driven;
    int TrackSurface;
    int currentstint;
    int current_sector;
    bool onpitroad;
    int laps_in_stint;
    int currentsession;
    int current_driver;
    int position;
    int classposition;
    int my_position;
    int my_classposition;
    int fastestlap;
    QString clas;
    int classid;
    int pitcounter;
    int offtrackcounter;
    int end_lap;
    float end_sessiontime;


  //  Lap *avgxlap;
  //  Lap *avg_laps;
  //  Lap *avg_stint_lap;
  //  Lap *avg_clean_lap;

    Lap *avg_5_lap;
    Lap *avg_10_lap;
    Lap *avg_20_lap;
    Lap *avg_40_lap;

    QVector<Driver*>Drivers;
    QVector<Lap*>Laps;
    QVector<PitStop*>Pitstops;
    QVector<Gap*>Gaps;



    void update_from_telemetry(ir_tel_vars *v);
    void update_from_sessionstring(SessionString *s);
    void calc_gaps(Teams *teams);
    void calc_my_position(Teams *teams);
    void reset();



signals:
    void new_lap(Team*);
    void new_sector(Team*);
    void in_pits(Team*);
    void off_track(Team*);
    void update_trackposition(Team*);
    void driver_change(Team*);
    void do_avg_calculation();

public slots:
    void new_avg_data(Lap *avg_5_lap, Lap *avg_10_lap, Lap *avg_20_lap, Lap *avg_40_lap);

private:
    Track *reftrack;
    Team_avg_calculator *avg_calculator;
    Global *gl;

    QEventLoop l;
   // QThread *calc_thread;
 //   bool calc_thread_started;

    void new_lap(ir_tel_vars *v);
    void calc_driver_laps();
    void calc_sector(ir_tel_vars *v);
    void handle_pitstop(ir_tel_vars *v);
    void set_lap(SessionInfo_ResultPosition *r);
    void calculate_avg();
    void calculate_avg_2();


};

#endif // TEAM_H
