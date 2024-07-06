#ifndef IR_SERVICE_H
#define IR_SERVICE_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QCoreApplication>
#include <QVector>
#include <QEventLoop>
#include <QDebug>
#include "Ir/irsdk_utils.h"
#include "Ir/ir_tel_var.h"
#include "Ir/ir_tel_vars.h"
#include "master.h"

QT_FORWARD_DECLARE_CLASS(Master);

class ir_service : public QObject
{
  Q_OBJECT
public:
  explicit ir_service(QObject *parent = nullptr, Master *refmaster = nullptr);

  ir_tel_vars *vars;


private:
  Master *refmaster;
  irsdk_utils *sdk;
  SessionString *s;
  bool firt_run;
  char *m_data;
  int m_nData;
  bool exit;
  bool connected;
  int oldtickcount;
  int oldsessioninfo;
  void write_variables();

  int missing_steps;
  int old_sessiontick;

public slots:
    void process();
    void restart_telemetry();

signals:
    void finished();
    void error(QString err);
    void connection_changed(bool);
    void new_data_ready(ir_tel_vars*);
    void new_sessionstring(QString sessionstring);
    void output1(QString output1);
};

#endif // IR_SERVICE_H
