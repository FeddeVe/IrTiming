#include "trackpoint.h"

TrackPoint::TrackPoint(QObject *parent) : QObject(parent)
{
  this->x = 0;
  this->y = 0;
  this->z = 0;
}
