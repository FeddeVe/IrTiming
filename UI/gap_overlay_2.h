#ifndef GAP_OVERLAY_2_H
#define GAP_OVERLAY_2_H

#include <QWidget>

#include "Core/core.h"
#include "UI/Delegates/cus_gap_cel.h"
#include "UI/Delegates/cus_default_cell.h"
#include "UI/Delegates/cus_state_cell.h"
#include "UI/Delegates/cus_lis_cell.h"
#include "UI/Delegates/cus_laptime_cell.h"
#include "UI/Delegates/cus_gap_cell.h"
#include "UI/Delegates/cus_driverlaps_cell.h"


namespace Ui {
  class Gap_Overlay_2;
}

class Gap_Overlay_2 : public QWidget
{
  Q_OBJECT

public:
  explicit Gap_Overlay_2(QWidget *parent = nullptr);
  ~Gap_Overlay_2();

private:
  Ui::Gap_Overlay_2 *ui;
  enum gap_type{
    race,
    practice
  };

  enum clms{
    c_caridx,
    c_status,
    c_gap,
    c_classposition,
    c_no_clms
  };

  int mode;
  int windowid;
  int old_gap_updater;

  void setup_table();
  int add_row(int caridx);
  int get_row(int caridx);
  void do_work(Core *c);

public slots:
  void set_mode(int mode);
   void window_loaded(bool okay, int windowid, int x, int y, int width, int height, int state);
    void on_core_update(Core *c);

signals:
  void save_window(int windowid, int x, int y, int width, int height, int state);
  void load_window(int windowid);
private slots:
  void on_checkBox_stateChanged(int arg1);
};

#endif // GAP_OVERLAY_2_H
