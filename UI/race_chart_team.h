#ifndef RACE_CHART_TEAM_H
#define RACE_CHART_TEAM_H

#include <QObject>
#include <QColor>
#include <QVector>

#include "race_chart_lap.h"
#include "Core/team.h"

#include "Core/core.h"

class Race_Chart_Team : public QObject
{
  Q_OBJECT
public:
  explicit Race_Chart_Team(QObject *parent = nullptr, Team *refteam = nullptr, QColor clr = nullptr);
  QColor clr;
  Team *team;
  QVector<Race_Chart_Lap*>laps;


  bool calculate(Core *c);

signals:

public slots:
};

#endif // RACE_CHART_TEAM_H
