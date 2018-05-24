#ifndef NIVELES_H
#define NIVELES_H

#include <QMainWindow>

namespace Ui {
class Niveles;
}

class Niveles : public QMainWindow
{
    Q_OBJECT

public:
    explicit Niveles(QWidget *parent = 0);
    ~Niveles();
    int T;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Niveles *ui;
};

#endif // NIVELES_H
