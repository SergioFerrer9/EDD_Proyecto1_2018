#include "juego.h"
#include "ui_juego.h"
#include "mainwindow.h"
#include <iostream>
#include "listamatrices.h"
#include "terminado.h"
#include <QMessageBox>
#include "enemigos.h"

ListaMatrices *lista1 = new ListaMatrices();


Hilo *hilo = new Hilo();
Hilo2 *hilo2 = new Hilo2();
Hilo3 *hilo3 = new Hilo3();
using namespace std;
using std::cout;
using std::endl;

///************************APACHE THRIFT..................................................................................
#include "Conectar.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::proyecto1;

class ConectarHandler : virtual public ConectarIf {
 public:
  ConectarHandler() {
    // Your initialization goes here
  }
  Juego *juego = new Juego();

  ///ELIMINAR......................................................................................................
  int32_t Eliminar(const int32_t fila, const int32_t columna) {
    int gano = lista1->Nivel_Gandado();
    int perdio= lista1->Nivel_Perdido();
    if(gano==0 && perdio==0){
        QString emisor =lista1->Eliminacion(fila,columna);
        emit hilo->Emitir_en_Consola(emisor);

        int puntos = lista1->Puntajes();
        emit hilo->Emitir_Puntaje(puntos);

        int fallos= lista1->Fallidos();
        emit hilo->Emitir_Fallidos(fallos);

        QString completo=lista1->Nivel_Completado();
        emit hilo->Emitir_en_Consola(completo);

        return puntos;
    }

   }

  ///PEDIR DIMENSION..............................................................................................
  int32_t Pedir_DimesionT() {
    int d = lista1->Dimension_Actual();
    return d;

  }

  ///AGREGAR USUARIO NUEVO.........................................................................................
  int32_t Agregar_Usuario(const std::string& usuario) {
     char *us = new char[usuario.length()+1]; ///Catear std::string to char*
     std::strcpy(us, usuario.c_str());
     lista1->Insertar(us,1,0,0);
     lista1->Graficar_ABB();
     return 1;
  }

  ///BUSCAR USUARIO.................................................................................................
  int32_t Buscar_Usuario(const std::string& usuario) {
      char *us = new char[usuario.length()+1];
      std::strcpy(us, usuario.c_str());
      if(lista1->buscar(us)!=NULL){

          return 1;
      }else{
          return 0;
      }
  }

  ///CAMBIAR DE NIVEL................................................................................................
  int32_t Cambio_Nivel(const std::string& usuario) {

      if(usuario.compare("arriba")==0){
          cout<<"Arriba"<<endl;
          lista1->Cambio_de_Nivel(1);
          int n = lista1->Nivel_Actual();
          int d = lista1->Dimension_Actual();
          QString Nivel=QString::number(n);
          QString Dime= QString::number(d);
          emit hilo->Emitir_Dim(Nivel+"   "+Dime+"X"+Dime);

      }else if(usuario.compare("abajo")==0){
          cout<<"Abajo"<<endl;
          lista1->Cambio_de_Nivel(2);
          int n = lista1->Nivel_Actual();
          int d = lista1->Dimension_Actual();
          QString Nivel=QString::number(n);
          QString Dime= QString::number(d);
          emit hilo->Emitir_Dim(Nivel+"   "+Dime+"X"+Dime);

      }else if(usuario.compare("jugar")==0){
          cout<<"Jugar"<<endl;
          lista1->Cambio_de_Nivel(3);
          juego->Mostrar_Final();
      }

  }

  ///PAUSA Y CONTINUAR EL JUEGO......................................................................................
  int32_t ON_OFF(const int32_t num) {
      int gano = lista1->Nivel_Gandado();
      int perdio= lista1->Nivel_Perdido();
   if(gano==0 && perdio==0){
      if(num==0){
          juego->Iniciar_Juego();
          lista1->On_OFF(0);
          hilo3->start();
      }else if(num==1){
          lista1->On_OFF(1);
      }
   }
  }

  ///PUNTAJES........................................................................................................
  void Puntajes(std::string& _return, const std::string& usuario) {
    char *Usuar = new char[usuario.length()+1]; ///Catear std::string to char*
    std::strcpy(Usuar, usuario.c_str());
    lista1->Agregar_Datos_Lista_Modificada(Usuar);
  }

};



///******************************************************************

Juego::Juego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Juego)
{
    ui->setupUi(this);
    QObject::connect(hilo,SIGNAL(Emitir_en_Consola(QString)),this,SLOT(Consola(QString)));
    QObject::connect(hilo2,SIGNAL(Emitir_en_Consola(QString)),this,SLOT(ServidorON(QString)));
    QObject::connect(hilo,SIGNAL(Emitir_Puntaje(int)),this,SLOT(Mostrar_Puntaje(int)));
    QObject::connect(hilo3,SIGNAL(Emitir_Tiempo(int)),this,SLOT(Mostrar_Tiempo(int)));
    QObject::connect(hilo,SIGNAL(Emitir_Dim(QString)),this,SLOT(Mostrar_Dim(QString)));
    QObject::connect(hilo,SIGNAL(Emitir_Fallidos(int)),this,SLOT(FALLIDOS(int)));
    QObject::connect(hilo3,SIGNAL(Game_Over(int)),this,SLOT(Mostrar_Over(int)));

}

Juego::~Juego()
{
    delete ui;
}

///Metodos Set........................................................
void Juego::setear(int t){
    this->T=t;
    hilo->setear(this->T);
}

void Hilo::setear(int t){
    this->T=t;
}

///Iniciar el Juego....................................................
void Juego::Iniciar_Juego(){

    emit hilo->Emitir_en_Consola("Mensaje de 200915305: ****Juego Iniciado****\n");
    int n = lista1->Nivel_Actual();
    int d = lista1->Dimension_Actual();
    QString Nivel=QString::number(n);
    QString Dime= QString::number(d);
    emit hilo->Emitir_Dim(Nivel+"   "+Dime+"X"+Dime);
    int puntos = lista1->Puntajes();
    emit hilo->Emitir_Puntaje(puntos);
    int tiempo = lista1->Tiempo();
    emit hilo3->Emitir_Tiempo(tiempo);
    lista1->On_OFF(0);
    hilo->start();

}

///Boton Iniciar juego.................................................
void Juego::on_pushButton_clicked()
{
    lista1->On_OFF(0);
    Iniciar_Juego();
}



///Boton para regresar al menu principal.............................
void Juego::on_pushButton_2_clicked()
{
    MainWindow *menu = new MainWindow();
    menu->show();
    close();
}


///Boton para pausar el juego.........................................
void Juego::on_pushButton_3_clicked()
{
   lista1->On_OFF(1);

}

void Juego::Pausa_Juego(){

        emit hilo->Emitir_en_Consola("Mensaje de 200915305: ****Pausa****\n");
        lista1->On_OFF(1);

}


///Mostrar en Consola.................................................
void Juego::Consola(QString texto){

        ui->textEdit->append(texto);
        Mostrar_Matriz();

}

void Juego::Mostrar_Matriz(){

    if(lista1->Nivel_Gandado()==1){
        QPixmap pixv("./Completado.png");
        ui->label->setPixmap(pixv);

     }else if(lista1->Nivel_Perdido()==1){
        QPixmap pixp("./gameover.png");
        ui->label->setPixmap(pixp);

    }else{
        QPixmap pixm("./MatrizDispersa.png");
        ui->label->setPixmap(pixm);
    }
}

void Juego::ServidorON(QString texto){
     ui->textEdit->append(texto);
}

void Juego::Mostrar_Puntaje(int puntos){
    QString texto = QString::number(puntos);
    ui->lineEdit_3->setText(texto);

}

void Juego::Mostrar_Final(){
    emit hilo->Emitir_en_Consola("Mensaje de 200915305: ****Nivel Nuevo****\n");
    int n = lista1->Nivel_Actual();
    int d = lista1->Dimension_Actual();
    QString Nivel=QString::number(n);
    QString Dime= QString::number(d);
    emit hilo->Emitir_Dim(Nivel+"   "+Dime+"X"+Dime);
    int puntos = lista1->Puntajes();
    emit hilo->Emitir_Puntaje(puntos);
    int tiempo = lista1->Tiempo();
    emit hilo3->Emitir_Tiempo(tiempo);

}

void Juego::Mostrar_Over(int over){
    lista1->Nivel_Over(1);
    Mostrar_Matriz();
    lista1->On_OFF(1);


 }

void Juego::PUNTAJE(int puntos){


}

void Juego::Mostrar_Dim(QString dim){
    ui->lineEdit_2->setText(dim);
}

void Juego::Mostrar_Tiempo(int tiempo){
    QString texto = QString::number(tiempo);
    ui->lineEdit_6->setText(texto);
}

void Juego::FALLIDOS(int puntos){
    QString texto = QString::number(puntos);
    ui->lineEdit_7->setText(texto);
}



///Hilo de las Funciones del Juego.....................................
void Hilo::run(){

     while(true){
        if(lista1->Terminar()==1){

           break;
        }else{
             try {
                if(hilo->Tiempo>0){
                 QString consola= lista1->Crear_Objetos_en_Matriz();
                 emit Emitir_en_Consola(consola);
                 hilo->sleep(4);
                 consola=lista1->Mover_Objetos_en_Matriz();
                 emit Emitir_en_Consola(consola);
                 hilo->sleep(4);

                }
            } catch (...) {
                cout<<"No se encontro"<<endl;
            }
        }
    }
}

void Hilo::Eliminar_En_Matriz(int fial, int columna){
    lista1->Eliminacion(fial,columna);
}

///Hilo de coneccion con el Cliente en Java........................................................
void Hilo2::run(){

    while(true){

        int port = 9090;
        ::apache::thrift::stdcxx::shared_ptr<ConectarHandler> handler(new ConectarHandler());
        ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new ConectarProcessor(handler));
        ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
        ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
        ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
        TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
        emit Emitir_en_Consola("Mensaje de 200915305: Servidor **ON**.\n");
        server.serve();

    }

}
///Boton Buscar y Mostrar Pila..........................................
void Juego::on_pushButton_4_clicked()
{

    try {
        int X=ui->lineEdit_4->text().toInt();
        int Y=ui->lineEdit_5->text().toInt();
        lista1->Buscar_Pila(X,Y);
        QPixmap pixP("./Pila.png");
        ui->label_2->setPixmap(pixP);
    } catch (...) {
        cout<<"No se encontro"<<endl;
    }

}


///Boton para encender el Servidor.....................................
void Juego::on_pushButton_5_clicked()
{
        cout<<"T......."<<this->T<<endl;
        hilo2->start();

}

///HILO3................................................................
void Hilo3::run(){
    Juego *juego = new Juego();
    int tiempo =hilo->Nivel;

        int i=0;
        if(tiempo==1){
            for(i=lista1->Tiempo(); i>0; i--){
                if(lista1->Terminar()==1){
                    break;
                }

                Emitir_Tiempo(lista1->Tiempo());
                lista1->Tiempor();
                hilo3->sleep(1);

            }
            if(lista1->Tiempo()==0){
                emit Game_Over(1);

            }

        }
}

void Juego::on_pushButton_6_clicked()
{
  Enemigos *enemigo =new Enemigos();
  enemigo->show();
}

void Juego::on_pushButton_7_clicked()
{
    ui->textEdit->clear();
}
