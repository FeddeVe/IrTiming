#ifndef SESSIONINFO_H
#define SESSIONINFO_H

#include <QObject>
#include <QVector>

#include "SessionInfo/sessioninfo_session.h"

class SessionInfo : public QObject
{
    Q_OBJECT
public:
    explicit SessionInfo(QObject *parent = nullptr);

    SessionInfo_Session *Get_Session(int sessionnum);
    void Put_From_Yaml(int sessionindex, QString key, QString value);
    void Put_resultposition_from_yaml(int sessionindex, int resultpositionindex, QString key, QString value);

    void clear();
private:
    QVector<SessionInfo_Session*>Sessions;

signals:

};

#endif // SESSIONINFO_H
