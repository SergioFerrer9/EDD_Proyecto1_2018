#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "niveles.h"
#include "juego.h"
#include <QMessageBox>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "resultados.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::setear(int t){
    this->T=t;
}

void MainWindow::on_pushButton_clicked()///Niveles....
{
    Niveles *niveles = new Niveles();
    niveles->show();
    close();

}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::information(this,tr("Datos Generales"),tr("Estructuras de Datos \nSeccion: B \nPrimer Semestre 2018 \nNombre: Sergio Alfonso Ferrer Garcia \nCarne: 200915305\n CUI: 2529952520101"),
                            tr("Continuar"));
}

void MainWindow::on_pushButton_2_clicked()///Juego...
{
    Juego *juego = new Juego();
    juego->setear(this->T);
    juego->show();
    close();
}

void MainWindow::on_pushButton_3_clicked()///Resultados...
{
  Resultados *res = new Resultados();
  res->show();



}
