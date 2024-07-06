#ifndef TRACKPOINT_H
#define TRACKPOINT_H

#include <QObject>

class TrackPoint : public QObject
{
  Q_OBJECT
public:
  explicit TrackPoint(QObject *parent = nullptr);

  double x;
  double y;
  double z;

signals:

public slots:
};

#endif // TRACKPOINT_H
