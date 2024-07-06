#ifndef TIRE_WEAR_H
#define TIRE_WEAR_H

#include <QObject>

class Tire_Wear : public QObject
{
  Q_OBJECT
public:
  explicit Tire_Wear(QObject *parent = nullptr);

  float lf;
  float rf;
  float lr;
  float rr;
  int type; //0=undefined, 1=calculated, 2=set

signals:

public slots:
};

#endif // TIRE_WEAR_H
