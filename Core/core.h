#ifndef CORE_H
#define CORE_H

#include <QObject>

#include "Core/track.h"
#include "Core/session.h"
#include "Core/teams.h"
#include "Core/weather.h"
#include "master.h"

QT_FORWARD_DECLARE_CLASS(Master);
QT_FORWARD_DECLARE_CLASS(Session);

class Core : public QObject
{
  Q_OBJECT
public:
  explicit Core(QObject *parent = nullptr, Master *refmaster = nullptr);

  Track *track;
  Session *session;
  Teams *teams;
  Weather *wheater;

  void set_connects();


signals:
  void on_update(Core *c);

public slots:
  void telemetry_update(ir_tel_vars *v);
  void sessionstring_update(SessionString *s);
  void reset_core();

private:
  Master *refmaster;
  bool reset;
};

#endif // CORE_H
