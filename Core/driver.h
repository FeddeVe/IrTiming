#ifndef DRIVER_H
#define DRIVER_H

#include <QObject>
#include <QColor>

class Driver : public QObject
{
    Q_OBJECT
public:
    explicit Driver(QObject *parent = nullptr);

  QString UserName;
  QString AbbrevName;
  QString Initials;
  int UserID;
  int Irating;
  QString LicString;
  QColor LicColor;
  QString ClubName;
  QString DivisionName;
  int total_laps_driven;
  int continues_laps_driven;


signals:

};

#endif // DRIVER_H
