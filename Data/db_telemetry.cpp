#include "db_telemetry.h"

db_Telemetry::db_Telemetry(QObject *parent) : QObject(parent)
{

}

void db_Telemetry::setup_db(QSqlDatabase db){
  QSqlQuery *q = new QSqlQuery(db);
  q->prepare("CREATE TABLE IF NOT EXISTS Telemetry_header(id INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,time INTEGER,USERID integer, SessionID INTEGER, SubSessionID INTEGER,SessionNum INTEGER, SessionType TEXT, TrackID INTEGER,CarID	INTEGER)");

  if(!q->exec()){
    qWarning() << "ERROR: " << q->lastError().text();
    }
  QString query = "CREATE TABLE IF NOT EXISTS Telemetry_data ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,"
               "header_id INTEGER,"
               "lap INTEGER,"
               "lap_pct INTEGER,"
               "TrackID INTEGER,"
               "lat REAL,"
               "lon REAL,"
               "alt REAL,"
               "TrackTemp REAL,"
               "TrackSurface INTEGER,"
               "throttle REAL,"
               "brake REAL,"
               "fuel REAL,"
               "RRSpeed REAL,"
               "RRPressure REAL,"
               "RRColdPressure REAL,"
               "RRTempL REAL,"
               "RRTempM REAL,"
               "RRTempR REAL,"
               "RRTempCL REAL,"
               "RRTempCM REAL,"
               "RRTempCR REAL,"
               "RRWearL REAL,"
               "RRWearM REAL,"
               "RRWearR REAL,"
               "LRSpeed REAL,"
               "LRPressure REAL,"
               "LRColdPressure REAL,"
               "LRTempL REAL,"
               "LRTempM REAL,"
               "LRTempR REAL,"
               "LRTempCL REAL,"
               "LRTempCM REAL,"
               "LRTempCR REAL,"
               "LRWearL REAL,"
               "LRWearM REAL,"
               "LRWearR REAL,"
               "RFSpeed REAL,"
               "RFPressure REAL,"
               "RFColdPressure REAL,"
               "RFTempL REAL,"
               "RFTempM REAL,"
               "RFTempR REAL,"
               "RFTempCL REAL,"
               "RFTempCM REAL,"
               "RFTempCR REAL,"
               "RFWearL REAL,"
               "RFWearM REAL,"
               "RFWearR REAL,"
               "LFSpeed REAL,"
               "LFPressure REAL,"
               "LFColdPressure REAL,"
               "LFTempL REAL,"
               "LFTempM REAL,"
               "LFTempR REAL,"
               "LFTempCL REAL,"
               "LFTempCM REAL,"
               "LFTempCR REAL,"
               "LFWearL REAL,"
               "LFWearM REAL,"
               "LFWearR REAL,"
               "LFRideHeight REAL,"
               "RFRideHeight REAL,"
               "LRRideHeight REAL,"
               "RRRideHeight REAL,"
               "CFSRideHeight REAL"
               ")";
//  qDebug() << query;
  q->prepare(query);
  if(!q->exec()){
    qWarning() << "ERROR: " << q->lastError().text();
    }

  delete q;

}

void db_Telemetry::save_telemetry(Telemetry_Save_Data *data, QSqlDatabase db){
  int header_id = -1;
  qint64 timedelete = QDateTime::currentSecsSinceEpoch();

  QSqlQuery *q = new QSqlQuery(db);
  q->prepare("Select ID from Telemetry_header WHERE UserID = :userid AND SessionID = :sessionid AND SubSessionID = :subsessionid AND SessionNum = :sessionnum AND TrackID = :trackid AND CarID = :carid");
  q->bindValue(":userid", data->userid);
  q->bindValue(":sessionid", data->sessionid);
  q->bindValue(":subsessionid",  data->subsessionid);
  q->bindValue(":sessionnum", data->SessionNo);
  q->bindValue(":trackid",  data->TrackID);
  q->bindValue(":carid",  data->CarID);

  if(!q->exec()){
    qWarning() << "ERROR: " << q->lastError().text();
    }else{
      while(q->next()){
          header_id=q->value(0).toInt();
        }
    }

  if(header_id == -1){

      q->prepare("Insert into Telemetry_header(time, USERID, SessionID, SubSessionID, SessionNum, SessionType, TrackID, CarID)"
                 "VALUES(:time, :userid, :sessionid, :subsessionid, :sessionnum, :sessiontype, :trackid, :carid)");
      q->bindValue(":time", timedelete);
      q->bindValue(":userid", data->userid);
      q->bindValue(":sessionid", data->sessionid);
      q->bindValue(":subsessionid", data->subsessionid);
      q->bindValue(":sessionnum", data->SessionNo);
      q->bindValue(":sessiontype", data->SessionType);
      q->bindValue(":trackid",  data->TrackID);
      q->bindValue(":carid", data->CarID);
      if(!q->exec()){
        qWarning() << "ERROR: " << q->lastError().text();
        }else{
          QSqlQuery *q = new QSqlQuery(db);
          q->prepare("Select ID from Telemetry_header WHERE UserID = :userid AND SessionID = :sessionid AND SubSessionID = :subsessionid AND SessionNum = :sessionnum AND TrackID = :trackid AND CarID = :carid");
          q->bindValue(":userid", data->userid);
          q->bindValue(":sessionid", data->sessionid);
          q->bindValue(":subsessionid",  data->subsessionid);
          q->bindValue(":sessionnum", data->SessionNo);
          q->bindValue(":trackid",  data->TrackID);
          q->bindValue(":carid",  data->CarID);

          if(!q->exec()){
            qWarning() << "ERROR: " << q->lastError().text();
            }else{
              while(q->next()){
                  header_id=q->value(0).toInt();
                }
            }

        }
    }else{
      q->prepare("Update Telemetry_header SET time = :time WHERE id = :id");
      q->bindValue(":time", timedelete);
      q->bindValue(":id", header_id);
      if(!q->exec()){
        qWarning() << "ERROR: " << q->lastError().text();
        }
    }

  for(int i = 0; i < data->Laps.count(); i++){
      for(int y = 0; y < data->Laps[i]->Data.count(); y++){
          if(data->Laps[i]->Data[y]->isset){

              q->prepare("INSERT INTO Telemetry_data ("
                         "header_id, lap, lap_pct, lat, lon, alt, TrackTemp, TrackSurface, throttle,brake,fuel,RRSpeed,RRPressure,"
                         "RRColdPressure, RRTempL, RRTempM,RRTempR,RRTempCL,RRTempCM,RRTempCR,RRWearL,RRWearM,RRWearR,"
                         "LRSpeed, LRPressure, LRColdPressure,LRTempL,LRTempM,LRTempR,LRTempCL,LRTempCM,LRTempCR,LRWearL,LRWearM,LRWearR,"
                         "RFSpeed, RFPressure,RFColdPressure,RFTempL,RFTempM,RFTempR,RFTempCL,RFTempCM,RFTempCR,RFWearL,RFWearM,"
                         "RFWearR,LFSpeed,LFPressure,LFColdPressure,LFTempL,LFTempM,LFTempR,LFTempCL,LFTempCM,LFTempCR,LFWearL,LFWearM,"
                         "LFWearR,LFRideHeight,RFRideHeight,LRRideHeight,RRRideHeight,CFSRideHeight, TrackID)"
                         "VALUES("
                                      ":header_id,"
                                       ":lap,"
                                       ":lap_pct,"
                                       ":lat ,"
                                       ":lon ,"
                                       ":alt ,"
                                       ":TrackTemp ,"
                                       ":TrackSurface,"
                                       ":throttle ,"
                                       ":brake ,"
                                       ":fuel ,"
                                       ":RRSpeed ,"
                                       ":RRPressure ,"
                                       ":RRColdPressure ,"
                                       ":RRTempL ,"
                                       ":RRTempM ,"
                                       ":RRTempR ,"
                                       ":RRTempCL ,"
                                       ":RRTempCM ,"
                                       ":RRTempCR ,"
                                       ":RRWearL ,"
                                       ":RRWearM ,"
                                       ":RRWearR ,"
                                       ":LRSpeed ,"
                                       ":LRPressure ,"
                                       ":LRColdPressure ,"
                                       ":LRTempL ,"
                                       ":LRTempM ,"
                                       ":LRTempR ,"
                                       ":LRTempCL ,"
                                       ":LRTempCM ,"
                                       ":LRTempCR ,"
                                       ":LRWearL ,"
                                       ":LRWearM ,"
                                       ":LRWearR ,"
                                       ":RFSpeed ,"
                                       ":RFPressure ,"
                                       ":RFColdPressure ,"
                                       ":RFTempL ,"
                                       ":RFTempM ,"
                                       ":RFTempR ,"
                                       ":RFTempCL ,"
                                       ":RFTempCM ,"
                                       ":RFTempCR ,"
                                       ":RFWearL ,"
                                       ":RFWearM ,"
                                       ":RFWearR ,"
                                       ":LFSpeed ,"
                                       ":LFPressure ,"
                                       ":LFColdPressure ,"
                                       ":LFTempL ,"
                                       ":LFTempM ,"
                                       ":LFTempR ,"
                                       ":LFTempCL ,"
                                       ":LFTempCM ,"
                                       ":LFTempCR ,"
                                       ":LFWearL ,"
                                       ":LFWearM ,"
                                       ":LFWearR ,"
                                       ":LFRideHeight ,"
                                       ":RFRideHeight ,"
                                       ":LRRideHeight ,"
                                       ":RRRideHeight ,"
                                       ":CFSRideHeight,"
                                       ":trackid)");


                            q->bindValue(":header_id", header_id);
                             q->bindValue(":lap", data->Laps[i]->Data[y]->lap);
                             q->bindValue(":lap_pct", data->Laps[i]->Data[y]->lap_pct);
                             q->bindValue(":lat", data->Laps[i]->Data[y]->lat);
                             q->bindValue(":lon", data->Laps[i]->Data[y]->lon);
                             q->bindValue(":alt", data->Laps[i]->Data[y]->alt);
                             q->bindValue(":TrackTemp", data->Laps[i]->Data[y]->TrackTemp);
                             q->bindValue(":TrackSurface", data->Laps[i]->Data[y]->TrackSurface);
                             q->bindValue(":throttle", data->Laps[i]->Data[y]->throttle);
                             q->bindValue(":brake", data->Laps[i]->Data[y]->brake);
                             q->bindValue(":fuel", data->Laps[i]->Data[y]->fuel);
                             q->bindValue(":RRSpeed", data->Laps[i]->Data[y]->RRSpeed);
                             q->bindValue(":RRPressure", data->Laps[i]->Data[y]->RRPressure);
                             q->bindValue(":RRColdPressure", data->Laps[i]->Data[y]->RRColdPressure);
                             q->bindValue(":RRTempL", data->Laps[i]->Data[y]->RRTempL);
                             q->bindValue(":RRTempM", data->Laps[i]->Data[y]->RRTempM);
                             q->bindValue(":RRTempR", data->Laps[i]->Data[y]->RRTempR);
                             q->bindValue(":RRTempCL", data->Laps[i]->Data[y]->RRTempCL);
                             q->bindValue(":RRTempCM", data->Laps[i]->Data[y]->RRTempCM);
                             q->bindValue(":RRTempCR", data->Laps[i]->Data[y]->RRTempCR);
                             q->bindValue(":RRWearL", data->Laps[i]->Data[y]->RRWearL);
                             q->bindValue(":RRWearM", data->Laps[i]->Data[y]->RRWearM);
                             q->bindValue(":RRWearR", data->Laps[i]->Data[y]->RRWearR);
                             q->bindValue(":LRSpeed", data->Laps[i]->Data[y]->LRSpeed);
                             q->bindValue(":LRPressure", data->Laps[i]->Data[y]->LRPressure);
                             q->bindValue(":LRColdPressure", data->Laps[i]->Data[y]->LRColdPressure);
                             q->bindValue(":LRTempL", data->Laps[i]->Data[y]->LRTempL);
                             q->bindValue(":LRTempM", data->Laps[i]->Data[y]->LRTempM);
                             q->bindValue(":LRTempR", data->Laps[i]->Data[y]->LRTempR);
                             q->bindValue(":LRTempCL", data->Laps[i]->Data[y]->LRTempCL);
                             q->bindValue(":LRTempCM", data->Laps[i]->Data[y]->LRTempCM);
                             q->bindValue(":LRTempCR", data->Laps[i]->Data[y]->LRTempCR);
                             q->bindValue(":LRWearL", data->Laps[i]->Data[y]->LRWearL);
                             q->bindValue(":LRWearM", data->Laps[i]->Data[y]->LRWearM);
                             q->bindValue(":LRWearR", data->Laps[i]->Data[y]->LRWearR);
                             q->bindValue(":RFSpeed", data->Laps[i]->Data[y]->RFSpeed);
                             q->bindValue(":RFPressure", data->Laps[i]->Data[y]->RFPressure);
                             q->bindValue(":RFColdPressure", data->Laps[i]->Data[y]->RFColdPressure);
                             q->bindValue(":RFTempL", data->Laps[i]->Data[y]->RFTempL);
                             q->bindValue(":RFTempM", data->Laps[i]->Data[y]->RFTempM);
                             q->bindValue(":RFTempR", data->Laps[i]->Data[y]->RFTempR);
                             q->bindValue(":RFTempCL", data->Laps[i]->Data[y]->RFTempCL);
                             q->bindValue(":RFTempCM", data->Laps[i]->Data[y]->RFTempCM);
                             q->bindValue(":RFTempCR", data->Laps[i]->Data[y]->RFTempCR);
                             q->bindValue(":RFWearL", data->Laps[i]->Data[y]->RFWearL);
                             q->bindValue(":RFWearM", data->Laps[i]->Data[y]->RFWearM);
                             q->bindValue(":RFWearR", data->Laps[i]->Data[y]->RFWearR);
                             q->bindValue(":LFSpeed", data->Laps[i]->Data[y]->LFSpeed);
                             q->bindValue(":LFPressure", data->Laps[i]->Data[y]->LFPressure);
                             q->bindValue(":LFColdPressure", data->Laps[i]->Data[y]->LFColdPressure);
                             q->bindValue(":LFTempL", data->Laps[i]->Data[y]->LFTempL);
                             q->bindValue(":LFTempM", data->Laps[i]->Data[y]->LFTempM);
                             q->bindValue(":LFTempR", data->Laps[i]->Data[y]->LFTempR);
                             q->bindValue(":LFTempCL", data->Laps[i]->Data[y]->LFTempCL);
                             q->bindValue(":LFTempCM", data->Laps[i]->Data[y]->LFTempCM);
                             q->bindValue(":LFTempCR", data->Laps[i]->Data[y]->LFTempCR);
                             q->bindValue(":LFWearL", data->Laps[i]->Data[y]->LFWearL);
                             q->bindValue(":LFWearM", data->Laps[i]->Data[y]->LFWearM);
                             q->bindValue(":LFWearR", data->Laps[i]->Data[y]->LFWearR);
                             q->bindValue(":LFRideHeight", data->Laps[i]->Data[y]->LFRideHeight);
                             q->bindValue(":RFRideHeight", data->Laps[i]->Data[y]->RFRideHeight);
                             q->bindValue(":LRRideHeight", data->Laps[i]->Data[y]->LRRideHeight);
                             q->bindValue(":RRRideHeight", data->Laps[i]->Data[y]->RRRideHeight);
                             q->bindValue(":CFSRideHeight", data->Laps[i]->Data[y]->CFSRideHeight);
                             q->bindValue(":trackid", data->TrackID);

                             if(!q->exec()){
                               qWarning() << "ERROR: " << q->lastError().text();
                               }

            }
        }
    }
  delete q;
}
