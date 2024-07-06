#ifndef LAP_SECTOR_H
#define LAP_SECTOR_H

#include <QObject>

class lap_sector : public QObject
{
    Q_OBJECT
public:
    explicit lap_sector(QObject *parent = nullptr);
    float enter_time;
    float exit_time;
    float raw_sector_time;
    float sectortime;
    float sector_percentage;


    void  update_sector(float sesiontime);


signals:

private:


};

#endif // LAP_SECTOR_H
