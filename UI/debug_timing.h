#ifndef DEBUG_TIMING_H
#define DEBUG_TIMING_H

#include <QWidget>

#include "Core/core.h"

namespace Ui {
  class Debug_Timing;
}

class Debug_Timing : public QWidget
{
  Q_OBJECT

public:
  explicit Debug_Timing(QWidget *parent = nullptr);
  ~Debug_Timing();

  enum db_clms{
    c_caridx,
    c_position,
    c_classposition,
    c_carnr,
    c_distance,
    c_curlap,
    c_cursector,
    c_sector1,
    c_sector2,
    c_lapsinstint,
    c_pitlane,
    c_pitstop,
    no_clms
  };

private:
  Ui::Debug_Timing *ui;

  int get_row(int caridx);
  void create_row(int caridx);

  int refresh_delay;

public slots:
  void on_core_update(Core *c);
  void setup_table();
};

#endif // DEBUG_TIMING_H
