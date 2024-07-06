#ifndef TELEMETRYREADER_H
#define TELEMETRYREADER_H

#include <QObject>
#include <QVector>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QThread>
#include <QEventLoop>
#include <QCoreApplication>


#include "Ir/irsdk_diskclient.h"
#include "SessionInfo/sessionstring.h"
#include "telemetry_save_data.h"
#include "telemetry_data.h"
#include "telemetry_save_data_lap.h"
#include "telemetry_save_data_lap_pct.h"


class TelemetryReader : public QObject
{
  Q_OBJECT
public:
  explicit TelemetryReader(QObject *parent = nullptr);

signals:
  void finished();
  void error(QString err);
  void output1(QString);
  void new_telemetrydata(Telemetry_Save_Data *data);
  void new_tyre_wear(float lf, float rf, float lr, float rr, int lap);
  void reading_done();

public slots:
  void on_sessionstringupdate(SessionString *s);
  void process();
  void save_finished();

private:
   QVector<QString>filenames;
   int filenameindex;
   bool fileExists(QString path);
   bool exit;
   bool deletefile;
   Telemetry_Data *data;
   bool save_done;


};

#endif // TELEMETRYREADER_H
