#include "db_track.h"

DB_Track::DB_Track(QObject *parent) : QObject(parent)
{
   this->pts = new TrackPoints(this);

}

void DB_Track::setup_db(QSqlDatabase db){
  QSqlQuery *q = new QSqlQuery(db);
  q->prepare("CREATE TABLE IF NOT EXISTS Track_info(id INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,TrackId INTEGER,TimeOffset integer)");

  if(!q->exec()){
    qWarning() << "ERROR: " << q->lastError().text();
    }

  delete q;
}

void DB_Track::set_timezone_offset(QSqlDatabase db, int offset, int trackid){
  QSqlQuery *q = new QSqlQuery(db);
  int rowid = -1;
  q->prepare("SELECT id FROM Track_info WHERE TrackId = :trackid");
  q->bindValue(":trackid", trackid);
  if(!q->exec()){
    qWarning() << "ERROR: " << q->lastError().text();
    }else{
      while(q->next()){
          rowid = q->value(0).toInt();
        }
    }
  if(rowid == -1){
      q->prepare("INSERT INTO Track_info(TrackId, TimeOffset) VALUES(:trackid, :timeoffset)");
      q->bindValue(":trackid", trackid);
      q->bindValue(":timeoffset", offset);
      if(!q->exec()){
        qWarning() << "ERROR: " << q->lastError().text();
        }
    }else{
      q->prepare("UPDATE Track_info SET TimeOffset = :timeoffset WHERE trackid = :trackid");
      q->bindValue(":trackid", trackid);
      q->bindValue(":timeoffset", offset);
      if(!q->exec()){
        qWarning() << "ERROR: " << q->lastError().text();
        }
    }
  delete q;
}

int DB_Track::load_timezone_offset(QSqlDatabase db, int trackid){
  QSqlQuery *q = new QSqlQuery(db);
  q->prepare("SELECT TimeOffset FROM Track_info WHERE TrackID = :trackid");
  q->bindValue(":trackid", trackid);
  int offset = 0;
  if(!q->exec()){
    qWarning() << "ERROR: " << q->lastError().text();
    }else{
      while(q->next()){
          offset = q->value(0).toInt();
        }
    }

  return offset;
}


TrackPoints *DB_Track::get_trackpoints(QSqlDatabase db, int TrackID){

  for(int i = 0; i < 1001; i++){
      QSqlQuery *q = new QSqlQuery(db);
      q->prepare("SELECT AVG(lat), AVG(lon), avg(alt) FROM telemetry_data WHERE trackid = :trackid AND TrackSurface = :tracksurface AND lap_pct = :lappct");
      q->bindValue(":trackid", TrackID);
      q->bindValue(":tracksurface", irsdk_TrkLoc::irsdk_OnTrack);
      q->bindValue(":lappct", i);
      double lat = 0;
      double lon = 0;
      double alt = 0;
      if(!q->exec()){
        qWarning() << "ERROR: " << q->lastError().text();
        }else{
      while(q->next()){
          lat = q->value(0).toDouble();
          lon = q->value(1).toDouble();
          alt = q->value(2).toDouble();
        }
        }

      this->pts->trackpoints[i]->x = lat;
      this->pts->trackpoints[i]->y = lon;
      this->pts->trackpoints[i]->z = alt;

      delete q;
    }
  return pts;
}


