#ifndef TELEMETRYOPTIONS_H
#define TELEMETRYOPTIONS_H

#include <QObject>
#include <QDebug>

class TelemetryOptions : public QObject
{
    Q_OBJECT
public:
    explicit TelemetryOptions(QObject *parent = nullptr);

  void set_value(QString key, QString value);

  QString get_TelemetryDiskFile();

signals:

private:
  QString TelemetryDiskFile;

};

#endif // TELEMETRYOPTIONS_H
