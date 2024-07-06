#ifndef BLACK_H
#define BLACK_H

#include <QWidget>

namespace Ui {
class black;
}

class black : public QWidget
{
    Q_OBJECT

public:
    explicit black(QWidget *parent = nullptr);
    ~black();

private slots:
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::black *ui;
};

#endif // BLACK_H
