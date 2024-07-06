#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QDebug>

#include "yaml-cpp/yaml.h"
#include "master.h"

#include "UI/hue.h"
#include "UI/debug_timing.h"
#include "UI/gap_overlay.h"
#include "UI/times.h"
#include "UI/stint_overlay.h"
#include "UI/stint_creator.h"
#include "UI/tires.h"
#include "UI/gap_overlay_2.h"
#include "UI/black.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void set_connects();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

public slots:
    void output1(QString output1);
    void Connection_Changed(bool);

private:
    Ui::MainWindow *ui;
    Master *m;
    Hue *hue;
    Debug_Timing *db_timing;
    Gap_Overlay *gap;
    Gap_Overlay_2 *gap2;
    Times *time_overlay;
    Stint_Overlay *st_overlay;
    Stint_Creator *st_creator;
    Tires *tires;
    black *blck;




};
#endif // MAINWINDOW_H
