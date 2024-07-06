#include "db_windows.h"

db_Windows::db_Windows(QObject *parent) : QObject(parent)
{

}

void db_Windows::setup_db(QSqlDatabase db){
  QSqlQuery *q = new QSqlQuery(db);
  q->prepare("CREATE TABLE IF NOT EXISTS WindowPositions(id INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,WindowID INTEGER,X integer, Y integer, Width integer, Height integer, State integer)");

  if(!q->exec()){
    qWarning() << "ERROR: " << q->lastError().text();
    }

  delete q;
}

void db_Windows::save_window(int windowid, int x, int y, int width, int height, int state, QSqlDatabase db){
  QSqlQuery *q = new QSqlQuery(db);
  q->prepare("Select id FROM WindowPositions WHERE windowid == :windowid");
  q->bindValue(":windowid", windowid);
  int id = -1;
  if(!q->exec()){
    qWarning() << "ERROR: " << q->lastError().text();
    }else{
  while(q->next()){
      id = q->value(0).toInt();
    }
    }
  if(id == -1){
      q->prepare("INSERT INTO WindowPositions (WindowID, X, Y, Width, Height, State) VALUES(:windowid, :x, :y, :width, :height, :state)");
      q->bindValue(":windowid", windowid);
      q->bindValue(":x", x);
      q->bindValue(":y", y);
      q->bindValue("width", width);
      q->bindValue(":height", height);
      q->bindValue(":state", state);
      if(!q->exec()){
        qWarning() << "ERROR: " << q->lastError().text();
        }
    }else{
      q->prepare("Update WindowPositions set X = :x, Y = :y, Width = :width, Height =:height, State = :state WHERE id = :id");
      q->bindValue(":x", x);
      q->bindValue(":y", y);
      q->bindValue(":width", width);
      q->bindValue(":height", height);
      q->bindValue(":state", state);
      q->bindValue(":id", id);
      if(!q->exec()){
        qWarning() << "ERROR: " << q->lastError().text();
        }
    }
  delete q;
}

void db_Windows::load_window(int windowid, QSqlDatabase db){
  QSqlQuery *q = new QSqlQuery(db);
  q->prepare("SELECT X,Y,Width, Height, State FROM WindowPositions WHERE WindowID=:id");
  q->bindValue(":id", windowid);
  if(!q->exec()){
    qWarning() << "ERROR: " << q->lastError().text();
    emit this->window_loaded(false, windowid, 0,0,0,0,0);
    }else{
      int x = 0;
      int y = 0;
      int width = 1;
      int height = 1;
      int state = 0;
      bool ok = false;
      while(q->next()){
          x = q->value(0).toInt();
          y = q->value(1).toInt();
          width = q->value(2).toInt();
          height = q->value(3).toInt();
          state = q->value(4).toInt();
          if((width > 50) && (height >50)){
          ok = true;
          }
        }
      emit this->window_loaded(ok, windowid, x, y, width, height, state);
    }
 delete q;
}


void db_Windows::reset_windows(QSqlDatabase db){
    QSqlQuery *q = new QSqlQuery(db);
    q->prepare("DELETE  FROM WindowPositions");
    if(!q->exec()){
      qWarning() << "ERROR: " << q->lastError().text();
    }
    this->load_window(1, db);
    this->load_window(2, db);
    this->load_window(3, db);

    delete q;
}



