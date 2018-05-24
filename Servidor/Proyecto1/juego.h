#ifndef JUEGO_H
#define JUEGO_H
#include <QThread>
#include <QMainWindow>
#include <QObject>
#include "terminado.h"

namespace Ui {
class Juego;
}

class Juego : public QMainWindow
{
    Q_OBJECT

public:
    explicit Juego(QWidget *parent = 0);
    ~Juego();
    int estado=0;
    void Iniciar_Juego();
    void Pausa_Juego();
    void Mostrar_Matriz();
    int T;
    void setear(int t);
    Terminado *terminado = new Terminado();




private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();


    void on_pushButton_7_clicked();

public slots:
    void Consola(QString texto);
    void ServidorON(QString texto);
    void Mostrar_Puntaje(int texto);
    void Mostrar_Tiempo(int tiempo);
    void Mostrar_Dim(QString dim);
    void PUNTAJE(int puntos);
    void FALLIDOS(int puntos);
    void Mostrar_Final();
    void Mostrar_Over(int over);


private:
    Ui::Juego *ui;

};

class Hilo : public QThread
{
    Q_OBJECT

private:
    void run();
public:
    int terminar=0;
    int puntaje=0;
    int DimensionT=1;
    int Nivel=1;
    int ID_enemgo=1;
    int T;
    int Tiempo=60;
    int Ataques_Fallidos=0;
    int Nivel_Terminado=0;
    int Nivel_Perdido=0;
    char *Usuario_Actual;

    void setear(int t);
    void Eliminar_En_Matriz(int fial , int columna);


signals:
    void Emitir_en_Consola(QString texto);
    void Emitir_Puntaje(int puntos);
    void Emitir_Dim(QString dim);
    void Emitir_Fallidos(int fallos);

};

class Hilo2 : public QThread
{
    Q_OBJECT

public:
    void run();

signals:
    void Emitir_en_Consola(QString texto);


};


class Hilo3 : public QThread
{
    Q_OBJECT

private:
    void run();

signals:
    void Emitir_Tiempo(int texto);
    void Game_Over(int texto);


};



#endif // JUEGO_H













