#ifndef WEEKENDOPTIONS_H
#define WEEKENDOPTIONS_H

#include <QObject>
#include <QDebug>

class WeekendOptions : public QObject
{
    Q_OBJECT
public:
    explicit WeekendOptions(QObject *parent = nullptr);

     void set_value(QString key, QString value);

     QString get_NumStarters();
     QString get_StartingGrid();
     QString get_QualifyScoring();
     QString get_CourseCautions();
     QString get_StandingStart();
     QString get_ShortParadeLap();
     QString get_Restarts();
     QString get_WeatherType();
     QString get_Skies();
     QString get_WindDirection();
     QString get_WindSpeed();
     QString get_WeatherTemp();
     QString get_RelativeHumidity();
     QString get_FogLevel();
     QString get_TimeOfDay();
     QString get_Date();
     QString get_EarthRotationSpeedupFactor();
     QString get_Unofficial();
     QString get_CommercialMode();
     QString get_NightMode();
     QString get_IsFixedSetup();
     QString get_StrictLapsChecking();
     QString get_HasOpenRegistration();
     QString get_HardcoreLevel();
     QString get_NumJokerLaps();
     QString get_IncidentLimit();
     QString get_FastRepairsLimit();
     QString get_GreenWhiteCheckeredLimit();



signals:

private:
    QString NumStarters;
    QString StartingGrid;
    QString QualifyScoring;
    QString CourseCautions;
    QString StandingStart;
    QString ShortParadeLap;
    QString Restarts;
    QString WeatherType;
    QString Skies;
    QString WindDirection;
    QString WindSpeed;
    QString WeatherTemp;
    QString RelativeHumidity;
    QString FogLevel;
    QString TimeOfDay;
    QString Date;
    QString EarthRotationSpeedupFactor;
    QString Unofficial;
    QString CommercialMode;
    QString NightMode;
    QString IsFixedSetup;
    QString StrictLapsChecking;
    QString HasOpenRegistration;
    QString HardcoreLevel;
    QString NumJokerLaps;
    QString IncidentLimit;
    QString FastRepairsLimit;
    QString GreenWhiteCheckeredLimit;



};

#endif // WEEKENDOPTIONS_H
