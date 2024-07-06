#ifndef STINT_OVERLAY_H
#define STINT_OVERLAY_H

#include <QWidget>
#include "Core/core.h"
#include "global.h"
#include "UI/Delegates/cus_laptime_cell.h"
#include "UI/Delegates/cus_default_cell.h"
#include "UI/Delegates/cus_gap_cell.h"
#include "UI/Delegates/cus_fuel_cell.h"


namespace Ui {
  class Stint_Overlay;
}

class Stint_Overlay : public QWidget
{
  Q_OBJECT

public:
  explicit Stint_Overlay(QWidget *parent = nullptr);
  ~Stint_Overlay();

private:
  enum clms{
    c_lapsort,
    c_lap,
    c_laptime,
    c_laptime_vs_avg,
    c_laptime_vs_target,
    c_fuel,
    c_fuel_vs_avg,
    c_fuel_vs_target,
    c_no_clms
  };

  Ui::Stint_Overlay *ui;
  Global *gl;

  void do_work(Core *c);
  void setup_table();
  void set_table(Core *c);
  int delay;
  int table_row;
  int windowid;

signals:
  void save_window(int windowid, int x, int y, int width, int height, int state);
  void load_window(int windowid);

public slots:
   void on_core_update(Core *c);
   void window_loaded(bool okay, int windowid, int x, int y, int width, int height, int state);
private slots:
   void on_checkBox_stateChanged(int arg1);
};

#endif // STINT_OVERLAY_H
