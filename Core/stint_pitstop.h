#ifndef STINT_PITSTOP_H
#define STINT_PITSTOP_H

#include <QObject>

class Stint_Pitstop : public QObject
{
  Q_OBJECT
public:
  explicit Stint_Pitstop(QObject *parent = nullptr);

signals:

public slots:
};

#endif // STINT_PITSTOP_H
