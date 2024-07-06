#include "tire_wear.h"

Tire_Wear::Tire_Wear(QObject *parent) : QObject(parent)
{
  this->lf = 0;
  this->rf = 0;
  this->lr = 0;
  this->rr = 0;
  this->type = 0;

}
