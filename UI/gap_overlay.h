#ifndef GAP_OVERLAY_H
#define GAP_OVERLAY_H

#include <QWidget>

#include "UI/Delegates/cus_gap_cel.h"
#include "UI/Delegates/cus_default_cell.h"
#include "UI/Delegates/cus_state_cell.h"
#include "UI/Delegates/cus_lis_cell.h"
#include "UI/Delegates/cus_laptime_cell.h"
#include "UI/Delegates/cus_gap_cell.h"
#include "UI/Delegates/cus_driverlaps_cell.h"

#include "Core/core.h"



namespace Ui {
  class Gap_Overlay;
}

class Gap_Overlay : public QWidget
{
  Q_OBJECT



public:
  explicit Gap_Overlay(QWidget *parent = nullptr, Core *refcore = nullptr);
  ~Gap_Overlay();

  enum gap_type{
    race,
    practice
  };

  enum clms{
    c_caridx,
    c_status,
    c_gap,
    c_classposition,
    c_name,
    c_lapsinstint,
    c_driverlaps,
    c_drivercontlaps,
  //  c_lastlap_sec_clrs,
    c_lastlap,
    c_lastlap_diff,
  //  c_avgxlap_sec_clrs, // best lap in practice
    c_avgxlap, // best lap in practice
    c_avgxlap_diff,
    c_avgstintlap,
    c_avgstintlap_diff,
      c_calclap,
      c_calclap_diff,
   // c_lastlap_s1,
   // c_lastlap_s2,
   // c_lastlap_s3,
   // c_lastlap_s4,
   // c_lastlap_s5,
   // c_lastlap_s6,
   // c_lastlap_s7,
   // c_lastlap_s8,
   // c_lastlap_s9,
   // c_lastlap_s10,
   // c_lastlap_s11,
   // c_lastlap_s12,
   // c_lastlap_s13,
   // c_lastlap_s14,
   // c_lastlap_s15,
   // c_lastlap_s16,
   // c_lastlap_s18,
   // c_lastlap_s19,
   // c_lastlap_s20,
    c_no_clms
  };


private:
  Ui::Gap_Overlay *ui;

  void setup_table();
  int add_row(int CarIDX);
  int get_row(int CarIDX);
  void do_work();

  Core *refcore;
  int mode;
  int delay = 0;
  int windowid;
  int old_gap_updater;

  void load_position();

public slots:
  void on_core_update(Core *c);

signals:
  void save_window(int windowid, int x, int y, int width, int height, int state);
  void load_window(int windowid);
  void mode_changed(int mode);
private slots:
  void on_checkBox_stateChanged(int arg1);
  void on_checkBox_2_stateChanged(int arg1);
  void on_comboBox_currentIndexChanged(int index);

public slots:
  void window_loaded(bool okay, int windowid, int x, int y, int width, int height, int state);
};

#endif // GAP_OVERLAY_H
