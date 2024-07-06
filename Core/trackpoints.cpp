#include "trackpoints.h"

TrackPoints::TrackPoints(QObject *parent) : QObject(parent)
{
  for(int i = 0; i < 1001; i++){
      TrackPoint *p = new TrackPoint(this);
      this->trackpoints.push_back(p);
    }
}

TrackPoints::~TrackPoints(){
  for(int i = 0; i < this->trackpoints.count(); i++){
      delete this->trackpoints[i];
    }
  this->trackpoints.clear();
}

void TrackPoints::reset(){
  for(int i = 0; i < this->trackpoints.count(); i++){
      this->trackpoints[i]->x = 0;
      this->trackpoints[i]->y = 0;
      this->trackpoints[i]->z = 0;
    }
}
