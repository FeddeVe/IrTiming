#ifndef DB_WINDOWS_H
#define DB_WINDOWS_H


#include <QObject>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

class db_Windows : public QObject
{
  Q_OBJECT
public:
  explicit db_Windows(QObject *parent = nullptr);

   void setup_db(QSqlDatabase db);
   void save_window(int windowid, int x, int y, int width, int height, int state, QSqlDatabase db);
   void load_window(int windowid, QSqlDatabase db);
   void reset_windows(QSqlDatabase db);
signals:
   void window_loaded(bool okay, int windowid, int x, int y, int width, int height, int state);

public slots:
};

#endif // DB_WINDOWS_H
