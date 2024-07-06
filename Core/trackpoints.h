#ifndef TRACKPOINTS_H
#define TRACKPOINTS_H

#include <QObject>
#include <QVector>

#include "Core/trackpoint.h"

class TrackPoints : public QObject
{
    Q_OBJECT
public:
    explicit TrackPoints(QObject *parent = nullptr);
    ~TrackPoints();
  QVector<TrackPoint*> trackpoints;

  void reset();



signals:

};

#endif // TRACKPOINTS_H
