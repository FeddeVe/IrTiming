#ifndef TELEMETRY_SAVE_DATA_H
#define TELEMETRY_SAVE_DATA_H

#include <QObject>

#include <QVector>

#include "Telemetry/telemetry_save_data_lap.h"

class Telemetry_Save_Data : public QObject
{
  Q_OBJECT
public:
  explicit Telemetry_Save_Data(QObject *parent = nullptr);

  ~Telemetry_Save_Data();

  int userid;
  int sessionid;
  int subsessionid;
  int SessionNo;
  QString SessionType;
  int TrackID;
  int CarID;

  QVector<Telemetry_Save_Data_Lap*>Laps;

signals:

public slots:
};

#endif // TELEMETRY_SAVE_DATA_H
