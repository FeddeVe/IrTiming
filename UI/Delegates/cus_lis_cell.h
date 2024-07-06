#ifndef CUS_LIS_CELL_H
#define CUS_LIS_CELL_H

#include <QObject>
#include <QTableWidgetItem>

class Cus_lis_cell : public QTableWidgetItem
{

public:
    explicit Cus_lis_cell(QObject *parent = nullptr);

    void setData(int role, const QVariant &value) override;
    QVariant data(int role) const override;

    int laps_in_stint;
    QColor clr;
    bool ismy;

signals:

};

#endif // CUS_LIS_CELL_H
