#ifndef CUS_GAP_CEL_H
#define CUS_GAP_CEL_H

#include <QObject>
#include <QTableWidgetItem>
#include <qmath.h>
#include "global.h"

class Cus_Gap_Cel : public QTableWidgetItem
{
public:
  explicit Cus_Gap_Cel(QObject *parent = nullptr);
  ~Cus_Gap_Cel();
  void setData(int role, const QVariant &value) override;
  QVariant data(int role) const override;

signals:

public slots:

private:
  float old_gap;
  float gap;
  float avg_gap;
  float avg_gap_arr[60];
int avg_gap_index;
  bool ok;
  bool time_mode;
  int gap_index;
  int red;
  int green;
  bool ismy;
  int practicemode;

  QFont font;
  Global *gl;
};

#endif // CUS_GAP_CEL_H
