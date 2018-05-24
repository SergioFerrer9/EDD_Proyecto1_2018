#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QMainWindow>

namespace Ui {
class Enemigos;
}

class Enemigos : public QMainWindow
{
    Q_OBJECT

public:
    explicit Enemigos(QWidget *parent = 0);
    ~Enemigos();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Enemigos *ui;
};

#endif // ENEMIGOS_H
