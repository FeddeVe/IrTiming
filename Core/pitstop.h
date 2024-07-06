#ifndef PITSTOP_H
#define PITSTOP_H

#include <QObject>

class PitStop : public QObject
{
    Q_OBJECT
public:
    explicit PitStop(QObject *parent = nullptr);

  float pitlane_start;
  float pitlane_end;
  float pitstop_start;
  float pitstop_end;
  float lap;

  void set_lanetime(float sessiontime);
  void set_stoptime(float sessiontime);

  float get_stoptime();
  float get_lanetime();
signals:

};

#endif // PITSTOP_H
