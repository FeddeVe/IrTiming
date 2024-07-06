#include "master.h"

Master::Master(QObject *parent) : QObject(parent)
{

  this->sessionstring = new SessionString();
  this->irsdk = new ir_service(nullptr, this);
  this->telreader = new TelemetryReader();
  this->database = new Database(nullptr, this);
  this->core = new Core(nullptr, this);

  // Core_Thread = new QThread;
 //  this->core->moveToThread(Core_Thread);
 //  Core_Thread->start();



  this->database->set_connects();
  this->core->set_connects();



   bool ok = connect(this->irsdk, SIGNAL(new_sessionstring(QString)), this->sessionstring, SLOT(set_sessionstring(QString)));
   ok = connect(this->sessionstring, SIGNAL(new_sessionstring(SessionString*)), this->telreader, SLOT(on_sessionstringupdate(SessionString*)));

}

void Master::start(){

  this->Db_Thread = new QThread;
  this->Db_Thread->setObjectName("Database_thread");

  this->database->moveToThread(this->Db_Thread);
  connect(this->database, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
  connect(Db_Thread, SIGNAL(started()), this->database, SLOT(process()));
  connect(Db_Thread, SIGNAL(finished()), Db_Thread, SLOT(quit()));
  connect(Db_Thread, SIGNAL(finished()), this->database, SLOT(deleteLater()));
  connect(Db_Thread, SIGNAL(finished()), Db_Thread, SLOT(deleteLater()));
  Db_Thread->start();

  telemetryreader_thread = new QThread;
  telemetryreader_thread->setObjectName("telemetryreader_thread");

  this->telreader->moveToThread(telemetryreader_thread);
  connect(this->telreader, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
  connect(telemetryreader_thread, SIGNAL(started()), this->telreader, SLOT(process()));
  connect(telemetryreader_thread, SIGNAL(finished()), telemetryreader_thread, SLOT(quit()));
  connect(telemetryreader_thread, SIGNAL(finished()), this->telreader, SLOT(deleteLater()));
  connect(telemetryreader_thread, SIGNAL(finished()), telemetryreader_thread, SLOT(deleteLater()));
  telemetryreader_thread->start();

  qDebug() << "Startin SessionString Thread";
  SessionString_thread = new QThread;
 SessionString_thread->setObjectName("SessionString_thread");
  this->sessionstring->moveToThread(SessionString_thread);
 connect(this->sessionstring, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
  connect(SessionString_thread, SIGNAL(started()), this->sessionstring, SLOT(process()));
  connect(SessionString_thread, SIGNAL(finished()), SessionString_thread, SLOT(quit()));
  connect(SessionString_thread, SIGNAL(finished()), this->sessionstring, SLOT(deleteLater()));
  connect(SessionString_thread, SIGNAL(finished()), SessionString_thread, SLOT(deleteLater()));
  SessionString_thread->start();
  qDebug() << "Startin IRTread";
  Ir_thread = new QThread;
  Ir_thread->setObjectName("IRService_Thread");
  this->irsdk->moveToThread(Ir_thread);
//  this->sessionstring->moveToThread(Ir_thread);
  this->core->moveToThread(Ir_thread);
  connect(this->irsdk, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
  connect(Ir_thread, SIGNAL(started()), this->irsdk, SLOT(process()));
  connect(Ir_thread, SIGNAL(finished()), Ir_thread, SLOT(quit()));
  connect(Ir_thread, SIGNAL(finished()), this->irsdk, SLOT(deleteLater()));
  connect(Ir_thread, SIGNAL(finished()), Ir_thread, SLOT(deleteLater()));
  Ir_thread->start();

}
