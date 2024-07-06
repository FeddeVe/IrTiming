#include "black.h"
#include "ui_black.h"

black::black(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::black)
{
    ui->setupUi(this);
}

black::~black()
{
    delete ui;
}

void black::on_checkBox_stateChanged(int arg1)
{
    int state = 0;
    if(arg1 == 0){
        this->setWindowFlags(Qt::Window);
        this->show();
      }else{
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
        state = 1;
        this->show();
      }
}
