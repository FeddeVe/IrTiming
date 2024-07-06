#ifndef CUS_STATE_CELL_H
#define CUS_STATE_CELL_H

#include <QObject>
#include <QTableWidgetItem>

#include "Core/lap.h"

class Cus_state_cell : public QTableWidgetItem
{

public:
  explicit Cus_state_cell(QObject *parent = nullptr);

  void setData(int role, const QVariant &value) override;
  QVariant data(int role) const override;

  int lap_type;
  int color_value_1;
  int color_value_2;


signals:

public slots:
};

#endif // CUS_STATE_CELL_H
