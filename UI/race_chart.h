#ifndef RACE_CHART_H
#define RACE_CHART_H

#include <QWidget>
#include <QVector>
#include "Core/core.h"
#include "UI/race_chart_team.h"
#include "global.h"

namespace Ui {
  class Race_Chart;
}

class Race_Chart : public QWidget
{
  Q_OBJECT

public:
  explicit Race_Chart(QWidget *parent = nullptr);
  ~Race_Chart();




public slots:


private:
  Ui::Race_Chart *ui;
  Global *gl;
  QVector<Race_Chart_Team*>Teams;
  bool firstrun;
  int my_classid;

  void do_work(Core *c);

  void draw_grid();

};

#endif // RACE_CHART_H
