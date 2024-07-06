#ifndef TRACK_H
#define TRACK_H

#include <QObject>
#include <QVector>

#include "Core/trackpoints.h"
#include "SessionInfo/sessionstring.h"
#include "Ir/ir_tel_vars.h"





class Track : public QObject
{
    Q_OBJECT
public:
    explicit Track(QObject *parent = nullptr);


  TrackPoints *pts;
   QVector<float>Sectors;
   int TrackID;
   QString TrackName;
 //  float TrackLength;
   QString TrackDisplayName;
   int TrackNumTurns;
   double Latitude;
   double Longitude;
   int timeoffset;


   int isinsector(float lap_dct);
   float get_sector_end(int sectorno);




signals:
  void new_track(int id);
  void save_timeoffset(int trackid, int timeoffset);
  void new_trackpoints(Track *t);

public slots:
  void track_loaded(TrackPoints* pts);
  void update_from_sessionstring(SessionString *s);
  void update_from_telemetry(ir_tel_vars *vars);
  void new_timeoffset(int offset);
  void set_timeoffset(int offset);
  void reload();

private:





};

#endif // TRACK_H
