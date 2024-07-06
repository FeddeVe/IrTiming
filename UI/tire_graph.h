#ifndef TIRE_GRAPH_H
#define TIRE_GRAPH_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QVector>
#include "Core/tire_wear.h"


namespace Ui {
  class Tire_Graph;
}

class Tire_Graph : public QWidget
{
  Q_OBJECT

public:
  explicit Tire_Graph(QWidget *parent = nullptr);
  ~Tire_Graph();

  int centerlap;
  int start_lap;
  int end_lap;

  QVector<Tire_Wear*>data;

void paintEvent(QPaintEvent *event) override;

private:
  Ui::Tire_Graph *ui;


};

#endif // TIRE_GRAPH_H
