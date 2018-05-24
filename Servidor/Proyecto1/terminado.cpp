#include "terminado.h"
#include "ui_terminado.h"
#include "enemigos.h"


Terminado::Terminado(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Terminado)
{
    ui->setupUi(this);
}

Terminado::~Terminado()
{
    delete ui;
}

///Bonton NO...
void Terminado::on_pushButton_clicked()
{
    close();
}

///Boton SI...
void Terminado::on_pushButton_2_clicked()
{
    Enemigos *enemigo = new Enemigos();
    enemigo->show();
    close();
}
