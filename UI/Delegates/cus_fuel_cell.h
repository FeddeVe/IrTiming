#ifndef CUS_FUEL_CELL_H
#define CUS_FUEL_CELL_H

#include <QObject>
#include <QTableWidgetItem>
#include <QtMath>

class Cus_Fuel_Cell : public QTableWidgetItem
{

public:
  explicit Cus_Fuel_Cell(QObject *parent = nullptr);

  float fuel;
  float compare_fuel;

  void setData(int role, const QVariant &value) override;
  QVariant data(int role) const override;

signals:

public slots:
};

#endif // CUS_FUEL_CELL_H
