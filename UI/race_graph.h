#ifndef RACE_GRAPH_H
#define RACE_GRAPH_H

#include <QWidget>

namespace Ui {
class Race_Graph;
}

class Race_Graph : public QWidget
{
    Q_OBJECT

public:
    explicit Race_Graph(QWidget *parent = nullptr);
    ~Race_Graph();

private:
    Ui::Race_Graph *ui;
};

#endif // RACE_GRAPH_H
