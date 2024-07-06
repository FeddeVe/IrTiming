#include "database.h"



Database::Database(QObject *parent, Master *refmaster) : QObject(parent)
{
  this->refmaster = refmaster;
  this->db_name = QCoreApplication::applicationDirPath() +"/base.db";
  this->telemetry = new db_Telemetry(this);
  this->track = new DB_Track(this);
  this->windows = new db_Windows(this);
  this->setup_db();
}

void Database::process(){
  QEventLoop l;
  this->exit = false;
  this->load_window(1);
  this->load_window(2);
  this->load_window(3);
  this->load_window(4);
  while(this->exit == false){
      l.processEvents();
      QThread::msleep(100);
    }
}

void Database::set_connects(){
    bool ok = connect(this->refmaster->telreader, SIGNAL(new_telemetrydata(Telemetry_Save_Data*)), this, SLOT(save_telemetry(Telemetry_Save_Data*)));
    ok = connect(this, SIGNAL(telemetry_saved()), this->refmaster->telreader, SLOT(save_finished()));
    ok = connect(this->refmaster->core->track, SIGNAL(new_track(int)), this, SLOT(load_track(int)));
    ok = connect(this->refmaster->core->track, SIGNAL(save_timeoffset(int, int)), this, SLOT(save_track_timeoffset(int, int)));
}

void Database::setup_db(){
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(this->db_name);
  if(!db.open())
     qWarning() << "ERROR: " << db.lastError();


  this->telemetry->setup_db(db);
  this->track->setup_db(db);
  this->windows->setup_db(db);

  db.close();
}

void Database::save_track_timeoffset(int trackid, int offset){
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(this->db_name);
  if(!db.open())
     qWarning() << "ERROR: " << db.lastError();
  this->track->set_timezone_offset(db, offset, trackid);
  db.close();

}

void Database::save_telemetry(Telemetry_Save_Data *d){
    m.lock();
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(this->db_name);
  if(!db.open())
     qWarning() << "ERROR: " << db.lastError();

this->telemetry->save_telemetry(d, db);

db.close();
m.unlock();
emit this->telemetry_saved();
}

void Database::load_track(int trackid){
    /*
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(this->db_name);
  if(!db.open())
     qWarning() << "ERROR: " << db.lastError();

   TrackPoints *pts = this->track->get_trackpoints(db, trackid);
   emit this->track_loaded(pts);

   int time_offset = this->track->load_timezone_offset(db, trackid);
   emit this->new_track_timeoffset(time_offset);
   db.close();
   */
}

void Database::save_window(int windowid, int x, int y, int width, int height, int state){
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(this->db_name);
  if(!db.open())
     qWarning() << "ERROR: " << db.lastError();

  this->windows->save_window(windowid, x, y, width, height, state, db);

  db.close();
}

void Database::load_window(int windowid){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(this->db_name);
    if(!db.open())
       qWarning() << "ERROR: " << db.lastError();

    this->windows->load_window(windowid, db);
    db.close();
}

void Database::reset_windows(){
    m.lock();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(this->db_name);
    if(!db.open())
       qWarning() << "ERROR: " << db.lastError();

    this->windows->reset_windows(db);
    db.close();
    m.unlock();
}
