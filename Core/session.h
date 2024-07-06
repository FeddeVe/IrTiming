#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QDateTime>
#include <QTime>

#include "Ir/irsdk_defines.h"
#include "Ir/ir_tel_vars.h"
#include "SessionInfo/sessionstring.h"
#include "Core/core.h"

QT_FORWARD_DECLARE_CLASS(Core);

class Session : public QObject
{
    Q_OBJECT
public:
    explicit Session(QObject *parent = nullptr, Core *refcore = nullptr);

  int SessionID;
  int SubSessionID;
  int SeriesID;
  int SeasonID;
  bool Official;

  double SessionTime;
  int SessionNum;
  int SessionState;
  int SessionFlags;
  double SessionTimeRemain;
  int SessionLapsRemain; // using the ex version
  QTime SessionTimeOfDay;
  QDate SessionDate;
  QDateTime Session_DateTime;


signals:

    void reset_all();
    void on_update(Session*);

public slots:
    void on_telemetry_update(ir_tel_vars *vars);
    void on_sessionstring_update(SessionString *s);

private:
    Core *refcore;



};

#endif // SESSION_H
