#ifndef TERMINADO_H
#define TERMINADO_H

#include <QMainWindow>

namespace Ui {
class Terminado;
}

class Terminado : public QMainWindow
{
    Q_OBJECT

public:
    explicit Terminado(QWidget *parent = 0);
    ~Terminado();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Terminado *ui;
};

#endif // TERMINADO_H
