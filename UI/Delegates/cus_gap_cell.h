#ifndef CUS_GAP_CELL_H
#define CUS_GAP_CELL_H

#include <QObject>
#include <QTableWidgetItem>
#include <QtMath>

#include "global.h"


class Cus_Gap_Cell : public QTableWidgetItem
{

public:
    explicit Cus_Gap_Cell(QObject *parent = nullptr);
    ~Cus_Gap_Cell();
    void setData(int role, const QVariant &value) override;
    QVariant data(int role) const override;

    float compare_lap;
    float this_lap;
    bool ismy;
    int graylevel;

    Global *gl;

signals:

};

#endif // CUS_GAP_CELL_H
