#ifndef RACE_CHART_LAP_H
#define RACE_CHART_LAP_H

#include <QObject>

class Race_Chart_Lap : public QObject
{
  Q_OBJECT
public:
  explicit Race_Chart_Lap(QObject *parent = nullptr);

  float session_time_enter;
  int laptype;
  bool predicted;
  float time_diff_best;

signals:

public slots:
};

#endif // RACE_CHART_LAP_H
