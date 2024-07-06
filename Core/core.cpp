#include "core.h"

Core::Core(QObject *parent, Master *refmaster) : QObject(parent)
{
  this->refmaster = refmaster;
  this->track = new Track(this);
  this->session = new Session(this, this);
  this->teams = new Teams(this, this->track);
  this->wheater = new Weather(this);
}

void Core::set_connects(){
  connect(this->refmaster->database, SIGNAL(track_loaded(TrackPoints*)), this->track, SLOT(track_loaded(TrackPoints*)));
  connect(this->refmaster->database, SIGNAL(telemetry_saved()), this->track, SLOT(reload()));
  connect(this->refmaster->database, SIGNAL(new_track_timeoffset(int)), this->track, SLOT(new_timeoffset(int)));
  connect(this->refmaster->sessionstring, SIGNAL(new_sessionstring(SessionString*)), this, SLOT(sessionstring_update(SessionString*)));
  connect(this->refmaster->irsdk, SIGNAL(new_data_ready(ir_tel_vars*)), this, SLOT(telemetry_update(ir_tel_vars*)));
 // connect(this->session, SIGNAL(reset_core()), this, SLOT(reset_core()));
//  connect(this->refmaster->telreader, SIGNAL(new_tyre_wear(float, float, float, float, int)), this->teams->myteam, SLOT(set_tyrewear(float,float,float,float,int)));
 // connect(this->refmaster->telreader, SIGNAL(reading_done()), this->teams->myteam, SLOT(calculate_tyres()));
}

void Core::telemetry_update(ir_tel_vars *v){
    this->teams->update_from_telemetry(v);
    this->wheater->on_telemetry_update(v);
   this->track->update_from_telemetry(v);
   this->session->on_telemetry_update(v);

   emit this->on_update(this);


}

void Core::sessionstring_update(SessionString *s){
   this->track->update_from_sessionstring(s);

   this->teams->update_from_sessionstring(s);
   this->wheater->on_sessionstring_update(s);
    this->session->on_sessionstring_update(s);
   emit this->on_update(this);
}


void Core::reset_core(){
    this->reset = true;
    this->teams->reset();
}
