#include "enemigos.h"
#include "ui_enemigos.h"

Enemigos::Enemigos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Enemigos)
{
    ui->setupUi(this);
}

Enemigos::~Enemigos()
{
    delete ui;



}

void Enemigos::on_pushButton_2_clicked() ///Graficas...
{
    QPixmap pix1("./ListaT1.png");
    ui->label->setPixmap(pix1);

    QPixmap pix2("./ListaT2.png");
    ui->label_2->setPixmap(pix2);

    QPixmap pix3("./ListaT3.png");
    ui->label_3->setPixmap(pix3);
}

void Enemigos::on_pushButton_clicked() ///Regresar....
{
    close();
}
