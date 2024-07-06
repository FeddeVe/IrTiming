#ifndef IR_TEL_VAR_H
#define IR_TEL_VAR_H

#include <QObject>
#include <QVariant>

#include "Ir/irsdk_defines.h"

class ir_tel_var : public QObject
{
  Q_OBJECT
public:
  explicit ir_tel_var(QObject *parent = nullptr, QString name = "");

  void set_var_hdr(const irsdk_varHeader *v);

  void set_raw_data(char *m_data);

  int type;
  QString name;
  int idx_addres;
  QVariant value[64];
  int count;
  bool isinit;

private:


signals:

public slots:
};

#endif // IR_TEL_VAR_H
