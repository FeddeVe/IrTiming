#ifndef CUS_DEFAULT_CELL_H
#define CUS_DEFAULT_CELL_H

#include <QObject>
#include <QTableWidgetItem>


class Cus_default_Cell : public QTableWidgetItem
{

public:
  explicit Cus_default_Cell(QObject *parent = nullptr);

  void setData(int role, const QVariant &value) override;
  QVariant data(int role) const override;

  QVariant oldvalue;
  QVariant value;
  int gray_level;
  bool ismy;

signals:

public slots:
};

#endif // CUS_DEFAULT_CELL_H
