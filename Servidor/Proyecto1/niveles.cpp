#include "niveles.h"
#include "ui_niveles.h"
#include "listamatrices.h"
#include "mainwindow.h"
ListaMatrices *lista = new ListaMatrices();

Niveles::Niveles(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Niveles)
{
    ui->setupUi(this);
}

Niveles::~Niveles()
{
    delete ui;
}

void Niveles::on_pushButton_clicked()///Agregar Dimensiones...
{

    QString texto = ui->lineEdit->text();
    int Dimension = texto.toInt();
    lista->Agregar_DimensionT(Dimension);
    this->T=Dimension;
}

void Niveles::on_pushButton_2_clicked()///Agregar Nivel...
{
    lista->Agregar_Nivel();
}

void Niveles::on_pushButton_3_clicked()///Eliminar Nivel...
{
    lista->Eliminar_Nivel();
}

void Niveles::on_pushButton_4_clicked()///Ver Imagen...
{
    lista->Graficar_Lista_Doble();
    QPixmap pixlista("./ListaDoble.png");
    ui->label->setPixmap(pixlista);
}

void Niveles::on_pushButton_5_clicked()///Regresar a Menu Principal...
{
    MainWindow *mein = new MainWindow();
    mein->setear(this->T);
    mein->show();
    close();
}
