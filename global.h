#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <QCoreApplication>
#include <QBrush>
#include <QTime>

class Global : public QObject
{
  Q_OBJECT
public:
  explicit Global(QObject *parent = nullptr);

  QBrush br_start_lap;
  QBrush br_end_lap;
  QBrush br_pit_lap;
  QBrush br_my_row;
  QBrush br_offtrack;

  QBrush better;
  QBrush worse;

  QString timetostring(float time);
  QString longtimetostring(float time);
  QString shorttimetostring(float time);
  QString gaptostring(float gap);

  int qtimetomilsec(QTime time);
  QTime timemilsectoqtime(float time);

  QColor randomcolor(int caridx);

  int interval_count;

signals:

public slots:
};

#endif // GLOBAL_H
