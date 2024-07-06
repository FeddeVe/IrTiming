#ifndef WEEKENDINFO_H
#define WEEKENDINFO_H

#include <QObject>
#include <QDebug>

class WeekendInfo : public QObject
{
    Q_OBJECT
public:
    explicit WeekendInfo(QObject *parent = nullptr);

    void set_value(QString key, QString value);

    QString get_TrackName();
    QString get_TrackID();
    QString get_TrackLength();
    QString get_TrackDisplayName();
    QString get_TrackDisplayShortName();
    QString get_TrackConfigName();
    QString get_TrackCity();
    QString get_TrackCountry();
    QString get_TrackAltitude();
    QString get_TrackLatitude();
    QString get_TrackLongitude();
    QString get_TrackNorthOffset();
    QString get_TrackNumTurns();
    QString get_TrackPitSpeedLimit();
    QString get_TrackType();
    QString get_TrackDirection();
    QString get_TrackWeatherType();
    QString get_TrackSkies();
    QString get_TrackSurfaceTemp();
    QString get_TrackAirTemp();
    QString get_TrackAirPressure();
    QString get_TrackWindVel();
    QString get_TrackWindDir();
    QString get_TrackRelativeHumidity();
    QString get_TrackFogLevel();
    QString get_TrackCleanup();
    QString get_TrackDynamicTrack();
    QString get_TrackVersion();
    QString get_SeriesID();
    QString get_SeasonID();
    QString get_SessionID();
    QString get_SubSessionID();
    QString get_LeagueID();
    QString get_Official();
    QString get_RaceWeek();
    QString get_EventType();
    QString get_Category();
    QString get_SimMode();
    QString get_TeamRacing();
    QString get_MinDrivers();
    QString get_MaxDrivers();
    QString get_DCRuleSet();
    QString get_QualifierMustStartRace();
    QString get_NumCarClasses();
    QString get_NumCarTypes();
    QString get_HeatRacing();
    QString get_BuildType();
    QString get_BuildTarget();
    QString get_BuildVersion();




private:
    QString TrackName;
    QString TrackID;
    QString TrackLength;
    QString TrackDisplayName;
    QString TrackDisplayShortName;
    QString TrackConfigName;
    QString TrackCity;
    QString TrackCountry;
    QString TrackAltitude;
    QString TrackLatitude;
    QString TrackLongitude;
    QString TrackNorthOffset;
    QString TrackNumTurns;
    QString TrackPitSpeedLimit;
    QString TrackType;
    QString TrackDirection;
    QString TrackWeatherType;
    QString TrackSkies;
    QString TrackSurfaceTemp;
    QString TrackAirTemp;
    QString TrackAirPressure;
    QString TrackWindVel;
    QString TrackWindDir;
    QString TrackRelativeHumidity;
    QString TrackFogLevel;
    QString TrackCleanup;
    QString TrackDynamicTrack;
    QString TrackVersion;
    QString SeriesID;
    QString SeasonID;
    QString SessionID;
    QString SubSessionID;
    QString LeagueID;
    QString Official;
    QString RaceWeek;
    QString EventType;
    QString Category;
    QString SimMode;
    QString TeamRacing;
    QString MinDrivers;
    QString MaxDrivers;
    QString DCRuleSet;
    QString QualifierMustStartRace;
    QString NumCarClasses;
    QString NumCarTypes;
    QString HeatRacing;
    QString BuildType;
    QString BuildTarget;
    QString BuildVersion;



signals:
    void new_track_id();

};

#endif // WEEKENDINFO_H
