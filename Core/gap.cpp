#include "gap.h"

Gap::Gap(QObject *parent) : QObject(parent)
{
  this->time_mode = true;
  this->ok = false;
  this->gap = 0;

}
