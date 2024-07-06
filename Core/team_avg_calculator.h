#ifndef TEAM_AVG_CALCULATOR_H
#define TEAM_AVG_CALCULATOR_H

#include <QObject>
#include <QThread>
#include <QEventLoop>
#include "Core/lap.h"
#include "Core/team.h"

QT_FORWARD_DECLARE_CLASS(Team);


class Team_avg_calculator : public QObject
{
    Q_OBJECT
public:
    explicit Team_avg_calculator(QObject *parent = nullptr, Team *refteam = nullptr);

private:
    Lap *avg_5_lap;
    Lap *avg_10_lap;
    Lap *avg_20_lap;
    Lap *avg_40_lap;
    bool dowork;
    Team *refteam;
    bool exit;

signals:
      void finished();
      void new_data(Lap *avg_5_lap, Lap *avg_10_lap, Lap *avg_20_lap, Lap *avg_40_lap);

public slots:
    void do_work();
    void process();

};

#endif // TEAM_AVG_CALCULATOR_H
