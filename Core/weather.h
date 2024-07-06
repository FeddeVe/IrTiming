#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>

#include "Ir/ir_tel_vars.h"
#include "SessionInfo/sessionstring.h"

class Weather : public QObject
{
    Q_OBJECT
public:
    explicit Weather(QObject *parent = nullptr);

  float track_temperature;
  float air_temperature;

public slots:
  void on_telemetry_update(ir_tel_vars *vars);
  void on_sessionstring_update(SessionString *s);

signals:

};

#endif // WEATHER_H
