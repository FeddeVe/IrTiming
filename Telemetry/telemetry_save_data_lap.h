#ifndef TELEMETRY_SAVE_DATA_LAP_H
#define TELEMETRY_SAVE_DATA_LAP_H

#include <QObject>
#include <QVector>

#include "Telemetry/telemetry_data.h"
#include "Telemetry/telemetry_save_data_lap_pct.h"

class Telemetry_Save_Data_Lap : public QObject
{
  Q_OBJECT
public:
  explicit Telemetry_Save_Data_Lap(QObject *parent = nullptr);
  ~Telemetry_Save_Data_Lap();

  QVector<Telemetry_Save_Data_Lap_PCT*>Data;


signals:

public slots:
};

#endif // TELEMETRY_SAVE_DATA_LAP_H
