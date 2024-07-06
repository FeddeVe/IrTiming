#include "driver.h"

Driver::Driver(QObject *parent) : QObject(parent)
{
    this->total_laps_driven = 0;
    this->continues_laps_driven = 0;
}
