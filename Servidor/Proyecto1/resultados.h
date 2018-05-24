#ifndef RESULTADOS_H
#define RESULTADOS_H

#include <QMainWindow>

namespace Ui {
class Resultados;
}

class Resultados : public QMainWindow
{
    Q_OBJECT

public:
    explicit Resultados(QWidget *parent = 0);
    ~Resultados();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Resultados *ui;
};

#endif // RESULTADOS_H
