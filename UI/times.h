#ifndef TIMES_H
#define TIMES_H

#include <QWidget>
#include <QDateTime>
#include "Core/core.h"
#include "global.h"
#include "Ir/irsdk_defines.h"
#include <QBitArray>
#include <QPalette>
#include <QColor>


namespace Ui {
class Times;
}

class Times : public QWidget
{
    Q_OBJECT

public:
    explicit Times(QWidget *parent = nullptr);
    ~Times();

signals:
  void save_window(int windowid, int x, int y, int width, int height, int state);
  void load_window(int windowid);

public slots:
     void on_core_update(Core *c);
      void window_loaded(bool okay, int windowid, int x, int y, int width, int height, int state);

private slots:
     void on_checkBox_stateChanged(int arg1);

private:
    Ui::Times *ui;
    Global *gl;
    void do_work(Core *c);
    int delay;
    int windowid;
};

#endif // TIMES_H
