#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->m = new Master(this);
   this->hue = new Hue(nullptr, this->m->core);
   hue->show();
 // this->db_timing = new Debug_Timing();
 // this->db_timing->show();
   this->gap = new Gap_Overlay(nullptr, this->m->core);
     this->gap->setWindowFlag(Qt::WindowStaysOnTopHint);
   this->gap->show();

  this->time_overlay = new Times();
  this->time_overlay->show();

 this->st_overlay = new Stint_Overlay();
this->st_overlay->show();

 this->st_creator = new Stint_Creator();

 this->gap2 = new Gap_Overlay_2();
this->gap2->show();
   this->blck = new black();
   this->blck->show();
 //this->tires = new Tires();
//  this->tires->show();

    ui->setupUi(this);

   this->set_connects();
    this->m->start();


}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_connects(){
  bool ok = false;
  ok = connect(this->m->irsdk, SIGNAL(connection_changed(bool)), this, SLOT(Connection_Changed(bool)));
  ok = connect(this->m->telreader, SIGNAL(output1(QString)), this, SLOT(output1(QString)));
 ok = connect(this->m->core, SIGNAL(on_update(Core*)),this->hue, SLOT(core_update(Core*)));
  ok = connect(this->hue, SIGNAL(save_timeoffset(int)), this->m->core->track, SLOT(set_timeoffset(int)));
   ok = connect(this->m->core, SIGNAL(on_update(Core*)), this->gap, SLOT(on_core_update(Core*)));
   ok = connect(this->m->database->windows, SIGNAL(window_loaded(bool, int, int, int, int, int, int)), this->gap, SLOT(window_loaded(bool, int, int, int, int, int, int)));
  ok = connect(this->gap, SIGNAL(save_window(int, int, int, int, int, int)), this->m->database, SLOT(save_window(int, int, int, int, int, int)));
  ok = connect(this->gap, SIGNAL(load_window(int)), this->m->database, SLOT(load_window(int)));
   ok = connect(this->m->core, SIGNAL(on_update(Core*)), this->time_overlay, SLOT(on_core_update(Core*)));
   ok = connect(this->m->database->windows, SIGNAL(window_loaded(bool, int, int, int, int, int, int)), this->time_overlay, SLOT(window_loaded(bool, int, int, int, int, int, int)));
  ok = connect(this->time_overlay, SIGNAL(save_window(int, int, int, int, int, int)), this->m->database, SLOT(save_window(int, int, int, int, int, int)));
   ok = connect(this->time_overlay, SIGNAL(load_window(int)), this->m->database, SLOT(load_window(int)));
   ok = connect(this->m->core, SIGNAL(on_update(Core*)), this->st_overlay, SLOT(on_core_update(Core*)));
    ok = connect(this->m->database->windows, SIGNAL(window_loaded(bool, int, int, int, int, int, int)), this->st_overlay, SLOT(window_loaded(bool, int, int, int, int, int, int)));
   ok = connect(this->st_overlay, SIGNAL(save_window(int, int, int, int, int, int)), this->m->database, SLOT(save_window(int, int, int, int, int, int)));
  ok = connect(this->st_overlay, SIGNAL(load_window(int)), this->m->database, SLOT(load_window(int)));
   ok = connect(this->m->core, SIGNAL(on_update(Core*)), this->gap2, SLOT(on_core_update(Core*)));
  ok = connect(this->m->database->windows, SIGNAL(window_loaded(bool, int, int, int, int, int, int)), this->gap2, SLOT(window_loaded(bool, int, int, int, int, int, int)));
  ok = connect(this->gap2, SIGNAL(save_window(int, int, int, int, int, int)), this->m->database, SLOT(save_window(int, int, int, int, int, int)));
  ok = connect(this->gap2, SIGNAL(load_window(int)), this->m->database, SLOT(load_window(int)));
   ok = connect(this->gap, SIGNAL(mode_changed(int)), this->gap2, SLOT(set_mode(int)));
  ok = false;
}

void MainWindow::output1(QString output){

}

void MainWindow::Connection_Changed(bool state){


}


void MainWindow::on_pushButton_clicked()
{
  // Stint Creator
     this->st_creator->show();

}



void MainWindow::on_pushButton_2_clicked()
{
    this->m->database->reset_windows();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->gap->show();

}

void MainWindow::on_pushButton_4_clicked()
{
    this->time_overlay->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    this->st_overlay->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    this->gap2->show();
}
