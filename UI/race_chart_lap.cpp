#include "race_chart_lap.h"

Race_Chart_Lap::Race_Chart_Lap(QObject *parent) : QObject(parent)
{
  this->session_time_enter = 0;
  this->laptype = 0;
  this->predicted = true;
  this->time_diff_best = 0;
}
