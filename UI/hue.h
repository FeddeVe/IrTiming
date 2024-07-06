#ifndef HUE_H
#define HUE_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QTcpSocket>
#include <QHostAddress>

#include "Core/core.h"
#include "Core/sunset.h"

namespace Ui {
  class Hue;
}

class Hue : public QWidget
{
  Q_OBJECT

public:
  explicit Hue(QWidget *parent = nullptr, Core *refcore = nullptr);
  ~Hue();

public slots:
  void core_update(Core *c);

signals:
  void save_timeoffset(int offset);

private slots:
  void on_spinBox_valueChanged(int arg1);
  void TimerSlot();

private:
  Ui::Hue *ui;
  Core *refcore;
  bool on;
  sunset *Sun;
  QTimer *tmr;
  QTime sunset_off;
  QTime sunset_start;
  QTime sunrise_start_fade;
  QTime sunrise_end_fade;
  bool carontrack;
  QTime sessiontime;
  int procent;
  bool do_tcp;

  void do_work(Core *c);
  int delay;
};

#endif // HUE_H
