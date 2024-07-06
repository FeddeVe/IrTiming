#ifndef CUS_LAPTIME_CELL_H
#define CUS_LAPTIME_CELL_H

#include <QObject>
#include <QTableWidgetItem>
#include "global.h"

class cus_laptime_cell : public QTableWidgetItem
{

public:
    explicit cus_laptime_cell(QObject *parent = nullptr);
    ~cus_laptime_cell();

    void setData(int role, const QVariant &value) override;
    QVariant data(int role) const override;

    float laptime;
    int graylevel;
    bool ismy;

    Global *gl;


signals:

};

#endif // CUS_LAPTIME_CELL_H
