#ifndef DRIVERINFO_H
#define DRIVERINFO_H

#include <QObject>
#include <QDebug>
#include <QVector>

#include "SessionInfo/driverinfo_drivers.h"

class DriverInfo : public QObject
{
    Q_OBJECT
public:
    explicit DriverInfo(QObject *parent = nullptr);

    void set_value(QString key, QString value);
    void set_driver_value(int driverindex, QString key, QString value);


    void clear();
    DriverInfo_Drivers *get_driver(int index);
    DriverInfo_Drivers *get_driver_caridx(int CarIDX);

    QString get_DriverCarIdx();
    QString get_DriverUserID();
    QString get_PaceCarIdx();
    QString get_DriverHeadPosX();
    QString get_DriverHeadPosY();
    QString get_DriverHeadPosZ();
    QString get_DriverCarIdleRPM();
    QString get_DriverCarRedLine();
    QString get_DriverCarEngCylinderCount();
    QString get_DriverCarFuelKgPerLtr();
    QString get_DriverCarFuelMaxLtr();
    QString get_DriverCarMaxFuelPct();
    QString get_DriverCarSLFirstRPM();
    QString get_DriverCarSLShiftRPM();
    QString get_DriverCarSLLastRPM();
    QString get_DriverCarSLBlinkRPM();
    QString get_DriverCarVersion();
    QString get_DriverPitTrkPct();
    QString get_DriverCarEstLapTime();
    QString get_DriverSetupName();
    QString get_DriverSetupIsModified();
    QString get_DriverSetupLoadTypeName();
    QString get_DriverSetupPassedTech();
    QString get_DriverIncidentCount();

signals:

private:
    QString DriverCarIdx;
    QString DriverUserID;
    QString PaceCarIdx;
    QString DriverHeadPosX;
    QString DriverHeadPosY;
    QString DriverHeadPosZ;
    QString DriverCarIdleRPM;
    QString DriverCarRedLine;
    QString DriverCarEngCylinderCount;
    QString DriverCarFuelKgPerLtr;
    QString DriverCarFuelMaxLtr;
    QString DriverCarMaxFuelPct;
    QString DriverCarSLFirstRPM;
    QString DriverCarSLShiftRPM;
    QString DriverCarSLLastRPM;
    QString DriverCarSLBlinkRPM;
    QString DriverCarVersion;
    QString DriverPitTrkPct;
    QString DriverCarEstLapTime;
    QString DriverSetupName;
    QString DriverSetupIsModified;
    QString DriverSetupLoadTypeName;
    QString DriverSetupPassedTech;
    QString DriverIncidentCount;

    QVector<DriverInfo_Drivers*>drivers;


};

#endif // DRIVERINFO_H
