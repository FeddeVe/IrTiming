#ifndef SPLITTIMEINFO_H
#define SPLITTIMEINFO_H

#include <QObject>
#include <QVector>

#include "SessionInfo/splittimeinfo_sectors.h"

class SplitTimeInfo : public QObject
{
  Q_OBJECT
public:
  explicit SplitTimeInfo(QObject *parent = nullptr);

  void set_sector(int sectorindex, QString key, QString value);

    QVector<SplitTimeInfo_Sectors*>sectors;

  void clear();

signals:

public slots:

private:

};

#endif // SPLITTIMEINFO_H
