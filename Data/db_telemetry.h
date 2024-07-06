#ifndef DB_TELEMETRY_H
#define DB_TELEMETRY_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

#include "Telemetry/telemetry_save_data.h"

class db_Telemetry : public QObject
{
  Q_OBJECT
public:
  explicit db_Telemetry(QObject *parent = nullptr);

  void setup_db(QSqlDatabase db);

signals:

public slots:
  void save_telemetry(Telemetry_Save_Data *data, QSqlDatabase db);
};

#endif // DB_TELEMETRY_H
