#ifndef LAP_H
#define LAP_H

#include <QObject>
#include <QVector>

#include "Core/lap_sector.h"
#include "Core/team_gap_container.h"
#include "global.h"

class Lap : public QObject
{
    Q_OBJECT
public:
    explicit Lap(QObject *parent = nullptr, int num_sectors = -1);
   ~Lap();

  enum laptype{
    l_ok,
    l_offtrack,
    l_pit
  };

  void set_sector(int sectorno, float sectortime);

  QVector<lap_sector*>sectors;
  QVector<Team_Gap_Container*>intervals;
  int laptype;
  float laptime;
  int driver;
  void set_laptype(int laptype);
  bool set_laptime(float time);
  float get_sectortime(int sectorno);
  float get_sectordistpct(int sectorno);
  float fuel_start;
  float fuel_end;
  void set_fuel(float cur_fuel);
  float get_fuel_usage();

private:
  Global *gl;

signals:

};

#endif // LAP_H
