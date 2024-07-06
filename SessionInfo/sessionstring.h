#ifndef SESSIONSTRING_H
#define SESSIONSTRING_H

#include <QObject>
#include <QThread>
#include <QEventLoop>

#include "yaml-cpp/yaml.h"

#include "SessionInfo/weekendinfo.h"
#include "SessionInfo/weekendoptions.h"
#include "SessionInfo/telemetryoptions.h"
#include "SessionInfo/sessioninfo.h"
#include "SessionInfo/driverinfo.h"
#include "SessionInfo/splittimeinfo.h"

using namespace std;

class SessionString : public QObject
{
  Q_OBJECT
public:
  explicit SessionString(QObject *parent = nullptr);


  WeekendInfo *weekendinfo;
  WeekendOptions *weekendoptions;
  TelemetryOptions *telemetryoptions;
  SessionInfo *sessioninfo;
  DriverInfo *driverinfo;
  SplitTimeInfo *splittimeinfo;

  void singleshot();

signals:
  void new_sessionstring(SessionString*);

public slots:
  void process();
  void set_sessionstring(QString);

private:

  QString str_SessionString;
  bool changed;
  bool exit;

  void process_weekendinfo(YAML::Node n);
  void process_weekendoptions(YAML::Node n);
  void process_telemetryoptions(YAML::Node n);
  void process_sessioninfo(YAML::Node n);
  void process_sessioninfo_resultposition(int sessionindex, YAML::Node n);
  void process_driverinfo(YAML::Node n);
  void process_splittimeinfo(YAML::Node n);

};

#endif // SESSIONSTRING_H
