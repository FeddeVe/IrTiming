#ifndef SESSIONINFO_RESULTPOSITION_H
#define SESSIONINFO_RESULTPOSITION_H

#include <QObject>
#include <QDebug>

class SessionInfo_ResultPosition : public QObject
{
    Q_OBJECT
public:
    explicit SessionInfo_ResultPosition(QObject *parent = nullptr);

    void set_value(QString key, QString value);

    QString get_Position();
    QString get_ClassPosition();
    QString get_CarIdx();
    QString get_Lap();
    QString get_Time();
    QString get_FastestLap();
    QString get_FastestTime();
    QString get_LastTime();
    QString get_LapsLed();
    QString get_LapsComplete();
    QString get_JokerLapsComplete();
    QString get_LapsDriven();
    QString get_Incidents();
    QString get_ReasonOutId();
    QString get_ReasonOutStr();

signals:

private:
    QString Position;
    QString ClassPosition;
    QString CarIdx;
    QString Lap;
    QString Time;
    QString FastestLap;
    QString FastestTime;
    QString LastTime;
    QString LapsLed;
    QString LapsComplete;
    QString JokerLapsComplete;
    QString LapsDriven;
    QString Incidents;
    QString ReasonOutId;
    QString ReasonOutStr;


};

#endif // SESSIONINFO_RESULTPOSITION_H
