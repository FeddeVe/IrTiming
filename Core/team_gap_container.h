#ifndef TEAM_GAP_CONTAINER_H
#define TEAM_GAP_CONTAINER_H

#include <QObject>
#include "Ir/irsdk_defines.h"

class Team_Gap_Container : public QObject
{
    Q_OBJECT
public:
    explicit Team_Gap_Container(QObject *parent = nullptr);

    void set_sessiontime(float sessiontime);
    void set_tracktype(int tracktype);

    float sessiontime;
    int tracklok;
signals:

};

#endif // TEAM_GAP_CONTAINER_H
