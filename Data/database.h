#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QCoreApplication>
#include <QMutex>
#include <QEventLoop>
#include <QThread>

#include "Data/db_telemetry.h"
#include "master.h"
#include "Telemetry/telemetry_save_data.h"
#include "Data/db_track.h"
#include "Data/db_windows.h"

QT_FORWARD_DECLARE_CLASS(Master);

class Database : public QObject
{
  Q_OBJECT
public:
  explicit Database(QObject *parent = nullptr, Master *refmaster = nullptr);

  void set_connects();

  db_Windows *windows;

signals:
  void telemetry_saved();
  void track_loaded(TrackPoints *pts);
  void new_track_timeoffset(int offset);
  void finished();
  void error(QString err);

public slots:
   void process();
   void save_telemetry(Telemetry_Save_Data *data);
   void load_track(int TrackID);
   void save_track_timeoffset(int trackid, int offset);
   void save_window(int windowid, int x, int y, int width, int height, int state);
   void load_window(int windowid);
   void reset_windows();
private:
  Master *refmaster;

  void setup_db();
  QString db_name;
  QMutex m;
  bool exit;

  db_Telemetry *telemetry;
  DB_Track *track;

};

#endif // DATABASE_H
