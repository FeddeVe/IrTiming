#ifndef TEAMS_H
#define TEAMS_H

#include <QObject>
#include <QVector>

#include "team.h"
#include "myteam.h"
#include "track.h"

QT_FORWARD_DECLARE_CLASS(Team);
QT_FORWARD_DECLARE_CLASS(MyTeam);

class Teams : public QObject
{
    Q_OBJECT
public:
    explicit Teams(QObject *parent = nullptr, Track *reftrack = nullptr);

  MyTeam *myteam;
  QVector<Team*> teams;

  void update_from_sessionstring(SessionString *s);
  void update_from_telemetry(ir_tel_vars *vars);
  void reset();
   int gap_updater;

signals:

private:
  Track *reftrack;
  int gap_worker;

};

#endif // TEAMS_H
