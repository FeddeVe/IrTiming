#ifndef MASTER_H
#define MASTER_H

#include <QObject>
#include <QThread>
#include <QEventLoop>

#include "SessionInfo/sessionstring.h"
#include "Ir/ir_service.h"
#include "Telemetry/telemetryreader.h"
#include "Data/database.h"
#include "Core/core.h"

QT_FORWARD_DECLARE_CLASS(Database);
QT_FORWARD_DECLARE_CLASS(Core);
QT_FORWARD_DECLARE_CLASS(ir_service);

class Master : public QObject
{
    Q_OBJECT
public:
    explicit Master(QObject *parent = nullptr);

  SessionString *sessionstring;
  ir_service *irsdk;
TelemetryReader *telreader;
Database *database;
Core *core;

  void start();

signals:

private:
  QThread *SessionString_thread;
  QThread *Ir_thread;
  QThread *telemetryreader_thread;
  QThread *Core_Thread;
  QThread *Db_Thread;

};

#endif // MASTER_H
