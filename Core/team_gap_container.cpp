#include "team_gap_container.h"

Team_Gap_Container::Team_Gap_Container(QObject *parent) : QObject(parent)
{
    this->sessiontime = 0;
    this->tracklok = irsdk_OnTrack;

}

void Team_Gap_Container::set_tracktype(int tracktype){
    if(tracktype != irsdk_OnTrack){
        this->tracklok = tracktype;
    }
}

void Team_Gap_Container::set_sessiontime(float sessiontime){
    this->sessiontime = sessiontime;
}
