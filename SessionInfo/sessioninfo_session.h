#ifndef SESSIONINFO_SESSION_H
#define SESSIONINFO_SESSION_H

#include <QObject>
#include <QDebug>
#include <QVector>

#include "SessionInfo/sessioninfo_resultposition.h"


class SessionInfo_Session : public QObject
{
    Q_OBJECT
public:
    explicit SessionInfo_Session(QObject *parent = nullptr);

    void set_value(QString key, QString value);
    void set_resultposition_value(int index, QString key, QString value);
    void clear();
    SessionInfo_ResultPosition *get_resultposition(int CarIDX);


    QString get_SessionNum();
    QString get_SessionLaps();
    QString get_SessionTime();
    QString get_SessionNumLapsToAvg();
    QString get_SessionType();
    QString get_SessionTrackRubberState();
    QString get_SessionName();
    QString get_SessionSubType();
    QString get_SessionSkipped();
    QString get_SessionRunGroupsUsed();
    QString get_ResultsAverageLapTime();
    QString get_ResultsNumCautionFlags();
    QString get_ResultsNumCautionLaps();
    QString get_ResultsNumLeadChanges();
    QString get_ResultsLapsComplete();
    QString get_ResultsOfficial();


signals:

private:
    QString SessionNum;
    QString SessionLaps;
    QString SessionTime;
    QString SessionNumLapsToAvg;
    QString SessionType;
    QString SessionTrackRubberState;
    QString SessionName;
    QString SessionSubType;
    QString SessionSkipped;
    QString SessionRunGroupsUsed;
    QString ResultsAverageLapTime;
    QString ResultsNumCautionFlags;
    QString ResultsNumCautionLaps;
    QString ResultsNumLeadChanges;
    QString ResultsLapsComplete;
    QString ResultsOfficial;

    QVector<SessionInfo_ResultPosition*>resultpositions;


};

#endif // SESSIONINFO_SESSION_H
