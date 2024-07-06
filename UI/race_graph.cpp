#include "race_graph.h"
#include "ui_race_graph.h"

Race_Graph::Race_Graph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Race_Graph)
{
    ui->setupUi(this);
}

Race_Graph::~Race_Graph()
{
    delete ui;
}
