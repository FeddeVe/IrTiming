#ifndef TIRES_H
#define TIRES_H

#include <QWidget>
#include <QtMath>
#include "UI/tire_graph.h"
#include "Core/core.h"

namespace Ui {
  class Tires;
}

class Tires : public QWidget
{
  Q_OBJECT

public:
  explicit Tires(QWidget *parent = nullptr);
  ~Tires();

private:
  Ui::Tires *ui;
  Tire_Graph *tiregraph;
  int delay;
  int oldlap;

  void do_work(Core *c);

signals:
  void restart_telemetry();

public slots:
   void on_core_update(Core *c);
private slots:
   void on_checkBox_stateChanged(int arg1);
};

#endif // TIRES_H
