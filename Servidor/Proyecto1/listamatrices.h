#ifndef LISTAMATRICES_H
#define LISTAMATRICES_H
#include <QString>
#include "juego.h"

///***************Nodo de la matriz.....
struct NodoMatriz{

    int Fila;
    int Columna;
    int enemigo;
    int ID;
    int golpes;
    struct NodoMatriz *izq;
    struct NodoMatriz *der;
    struct NodoMatriz *arriba;
    struct NodoMatriz *abajo;
    struct NodoMatriz *sig; //Con el sig formamos una pila...

};

///**************Nodo de las Filas de la Matriz...
struct NodoFila
{
    int Fila;
    struct NodoFila *Abajo;  ///  *Sig
    struct NodoFila *Arriba; ///  *Ant
    struct NodoMatriz *primeroM;
    struct NodoMatriz *ultmoM;
};

///**************Nodo de las Columnas de la Matriz...
struct NodoColumna
{
    int Columna;
    struct NodoColumna *Izq; ///  *Sig
    struct NodoColumna *Der; ///  *Ant
    struct NodoMatriz *primeroM;
    struct NodoMatriz *ultmoM;
};


///**************Nodo Pibote de cada Matriz...
struct NodoDoble{
    int Nivel;
    int Activo;
    struct NodoDoble *sig;
    struct NodoDoble *ant;
    struct NodoFila *PrmeroAbajo;
    struct NodoFila *UltimoAbajo;
    struct NodoColumna *PrimeroIzquierda;
    struct NodoColumna *UltimoIzquierda;
};

///**************Dodo de las Listas Circulares...
struct NodoTipo1{
    int tipo;
    int ID;
    struct NodoTipo1 *sig;
    struct NodoTipo1 *ant;

};

struct NodoTipo2{
    int tipo;
    int ID;
    struct NodoTipo2 *sig;
    struct NodoTipo2 *ant;

};

struct NodoTipo3{
    int tipo;
    int ID;
    struct NodoTipo3 *sig;
    struct NodoTipo3 *ant;

};

///**************Nodo Arbol de Usuarios ABB.............
struct NodoABB{
    char *Usuario;
    int Nivel;
    int Tiempo;
    int Puntaje;
    struct NodoABB *izq;
    struct NodoABB *der;
    int contador;
};

struct NodoPila{
    int fila;
    int columna;
    struct NodoPila *sig;
};

///**************Nodo ArBOL De Resultados ABB.............
struct NodoABB2{
    char *Usuario;
    int Nivel;
    int Tiempo;
    int Puntaje;
    struct NodoABB2 *izq;
    struct NodoABB2 *der;
    int contador2;
};



///************Enemigos Eliminados en General............
struct NodoEliminados{
    int Fila;
    int Columna;
    int enemigo;
    int ID;
    int golpes;
    struct NodoEliminados *sig;

};

///**********Lista Modificada***************************
struct NodoLista_Modificada{
    char *Usuario;
    int Nivel;
    int Tiempo;
    int Puntaje;
    struct NodoLista_Modificada *izq;
    struct NodoLista_Modificada *der;
};

///**************Funciones Generales.....................
struct ListaMatrices{
    Juego *juego;


    static int Variable;
    void Agregar_DimensionT(int T);
    void Agregar_Nivel();
    void Eliminar_Nivel();
    void Agregar_Lista_Doble(int Nivel);
    void Eliminar_Lista_Doble();
    void Graficar_Lista_Doble();
    bool Agregar_En_Matriz(int enemigo, int id, int fila, int columna, int golpes);
    bool Eliminar_En_Matriz(int fila, int columna);
    void Agregar_Fila(NodoDoble *Actual, int fila);
    void Eliminar_Fila(int fila);
    void Agregar_Columna(NodoDoble *Actual, int fila);
    void Eliminar_Columna(int columna);
    void Grafica_Matriz_Por_Niveles();
    void Recorridos();
    void Recorridos2();
    QString Eliminacion(int y, int x);

    ///Funciones del Juego...
    QString Crear_Objetos_en_Matriz();
    QString Mover_Objetos_en_Matriz();
    QString Buscar_Pila(int x, int y);


    ///Objetos que estan en la Pila de la Matriz....
    void Agregar_A_Pila(int fila, int columna);
    void Objetos_En_Pila();

    ///Listas Circulares...
    void Agregar_Lista_Tipo1(int tipo, int id);
    void RecorrerT1();
    void Graficar_Lista_Tipo1();

    void Agregar_Lista_Tipo2(int tipo, int id);
    void Graficar_Lista_Tipo2();

    void Agregar_Lista_Tipo3(int tipo, int id);
    void Graficar_Lista_Tipo3();

    ///ArbolABB..............
    NodoABB *buscar(char *usuario);
    NodoABB *buscar(NodoABB *actual, char *usuario);
    void Insertar(char *usuario, int Nivel, int Tiempo, int Puntaje);
    void Graficar_ABB();
    void Graficar_ABB(NodoABB *actual);
    NodoABB *Obtener_Reemplazo(NodoABB *reemp);
    NodoABB *raiz;
    ListaMatrices();
    FILE *grab;

    ///ArbolABB2..............
    NodoABB2 *buscar2(char *usuario);
    NodoABB2 *buscar2(NodoABB2 *actual, char *usuario);
    void Insertar2(char *usuario, int Nivel, int Tiempo, int Puntaje);
    void Graficar_ABB2();
    void Graficar_ABB2(NodoABB2 *actual);
    NodoABB2 *Obtener_Reemplazo2(NodoABB2 *reemp);
    NodoABB2 *raiz2;
    FILE *grab2;

    ///Puntajes................
    int Puntajes();
    int Nivel_Actual();
    int Dimension_Actual();
    int Fallidos();
    int Nivel_Perdido();
    int Nivel_Gandado();
    int Nivel_Over(int over);
    int Nivel_Open(int open);
    QString Nivel_Completado();
    void Subir_Nivel();
    void On_OFF(int on);
    int Terminar();
    int Cambio_de_Nivel(int cambio);
    int Tiempo();
    int Tiempor();
    void Usuario_Actual(char *usuario);

    ///Enemigos Eliminados en General.......
    void Agregar_Enemigos_Eliminados(int enemigo, int id, int fila, int columna);

    ///Lista Modificada....
    void Agregar_Lista_Modificada(char *usuario, int puntos, int nivel , int tiempo);
    void Graficar_Lista_Modificada();
    void Agregar_Datos_Lista_Modificada(char *usuario);

    void Recorrer_Lista_Modificada(char *usuario);


};








#endif // LISTAMATRICES_H
