#ifndef GAP_H
#define GAP_H

#include <QObject>

class Gap : public QObject
{
  Q_OBJECT
public:
  explicit Gap(QObject *parent = nullptr);

  bool time_mode;
  float gap;
  bool ok;
signals:

public slots:
};

#endif // GAP_H
