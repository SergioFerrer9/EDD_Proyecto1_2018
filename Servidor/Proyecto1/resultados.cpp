#include "resultados.h"
#include "ui_resultados.h"
#include "listamatrices.h"
#include "mainwindow.h"


Resultados::Resultados(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Resultados)
{
    ui->setupUi(this);
}

Resultados::~Resultados()
{
    delete ui;
}

void Resultados::on_pushButton_clicked()
{
    ListaMatrices *lista2= new ListaMatrices();
    ///GRAFICAR....
    lista2->Graficar_Lista_Modificada();
    QPixmap pixlista("./ListaM.png");
    ui->label->setPixmap(pixlista);
}

void Resultados::on_pushButton_2_clicked()
{
    ///Regresar....
    MainWindow *menu = new MainWindow();
    menu->show();
    close();

}

void Resultados::on_pushButton_3_clicked()
{   ListaMatrices *lista2= new ListaMatrices();
    ///Arbol...
    char *texto=strdup(ui->lineEdit->text().toUtf8().constData());
    lista2->Recorrer_Lista_Modificada(texto);
    QPixmap pixlista("./ArbolABB2.png");
    ui->label_2->setPixmap(pixlista);


}
