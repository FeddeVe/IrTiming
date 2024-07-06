#ifndef TELEMETRY_SAVE_DATA_LAP_PCT_H
#define TELEMETRY_SAVE_DATA_LAP_PCT_H

#include <QObject>

class Telemetry_Save_Data_Lap_PCT : public QObject
{
  Q_OBJECT
public:
  explicit Telemetry_Save_Data_Lap_PCT(QObject *parent = nullptr);

 bool isset;
 int lap_pct;
 int lap;
 double lat  ;
 double lon  ;
 double alt  ;
 float TrackTemp  ;
 int TrackSurface;
 float throttle  ;
 float brake  ;
 float fuel  ;
 float RRSpeed  ;
 float RRPressure  ;
 float RRColdPressure  ;
 float RRTempL  ;
 float RRTempM  ;
 float RRTempR  ;
 float RRTempCL  ;
 float RRTempCM  ;
 float RRTempCR  ;
 float RRWearL  ;
 float RRWearM  ;
 float RRWearR  ;
 float LRSpeed  ;
 float LRPressure  ;
 float LRColdPressure  ;
 float LRTempL  ;
 float LRTempM  ;
 float LRTempR  ;
 float LRTempCL  ;
 float LRTempCM  ;
 float LRTempCR  ;
 float LRWearL  ;
 float LRWearM  ;
 float LRWearR  ;
 float RFSpeed  ;
 float RFPressure  ;
 float RFColdPressure  ;
 float RFTempL  ;
 float RFTempM  ;
 float RFTempR  ;
 float RFTempCL  ;
 float RFTempCM  ;
 float RFTempCR  ;
 float RFWearL  ;
 float RFWearM  ;
 float RFWearR  ;
 float LFSpeed  ;
 float LFPressure  ;
 float LFColdPressure  ;
 float LFTempL  ;
 float LFTempM  ;
 float LFTempR  ;
 float LFTempCL  ;
 float LFTempCM  ;
 float LFTempCR  ;
 float LFWearL  ;
 float LFWearM  ;
 float LFWearR  ;
 float LFRideHeight  ;
 float RFRideHeight  ;
 float LRRideHeight  ;
 float RRRideHeight  ;
 float CFSRideHeight ;

signals:

public slots:
};

#endif // TELEMETRY_SAVE_DATA_LAP_PCT_H
