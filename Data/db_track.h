#ifndef DB_TRACK_H
#define DB_TRACK_H

#include <QObject>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

#include "Core/trackpoints.h"
#include "Ir/irsdk_defines.h"

class DB_Track : public QObject
{
  Q_OBJECT
public:
  explicit DB_Track(QObject *parent = nullptr);

  void setup_db(QSqlDatabase db);

  void set_timezone_offset(QSqlDatabase db, int offset, int trackid);
  int load_timezone_offset(QSqlDatabase db, int trackid);
  void reset_windows();
  TrackPoints *pts;

  TrackPoints *get_trackpoints(QSqlDatabase db,int TrackID);



signals:

public slots:


};

#endif // DB_TRACK_H
