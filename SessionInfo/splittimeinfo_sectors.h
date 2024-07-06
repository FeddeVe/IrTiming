#ifndef SPLITTIMEINFO_SECTORS_H
#define SPLITTIMEINFO_SECTORS_H

#include <QObject>
#include <QDebug>

class SplitTimeInfo_Sectors : public QObject
{
  Q_OBJECT
public:
  explicit SplitTimeInfo_Sectors(QObject *parent = nullptr);

  void set_value(QString key, QString value);

  QString get_SectorNum();
  QString get_SectorStartPct();

signals:

public slots:

private:
  QString SectorNum;
  QString SectorStartPct;

};

#endif // SPLITTIMEINFO_SECTORS_H
