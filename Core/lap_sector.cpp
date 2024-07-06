#include "lap_sector.h"

lap_sector::lap_sector(QObject *parent) : QObject(parent)
{
    this->enter_time = 0;
    this->exit_time = 0;
    this->sectortime = 0;
  this->raw_sector_time = 0;
  this->sector_percentage = 0;

}

void lap_sector::update_sector(float sessiontime){
    if(this->enter_time == 0){
        this->enter_time = sessiontime;
    }

    this->exit_time = sessiontime;
    this->raw_sector_time = this->exit_time - this->enter_time;
}
