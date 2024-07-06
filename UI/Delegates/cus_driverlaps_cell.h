#ifndef CUS_DRIVERLAPS_CELL_H
#define CUS_DRIVERLAPS_CELL_H

#include <QObject>
#include <QTableWidgetItem>

class Cus_DriverLaps_Cell : public QTableWidgetItem
{

public:
  explicit Cus_DriverLaps_Cell(QObject *parent = nullptr);

  void setData(int role, const QVariant &value) override;
  QVariant data(int role) const override;

  int laps_driven;
  bool ismy;
  int gray_level;

signals:

public slots:
};

#endif // CUS_DRIVERLAPS_CELL_H
