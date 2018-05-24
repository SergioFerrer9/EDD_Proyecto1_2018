#include "listamatrices.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>


using namespace std;
using std::cout;
using std::endl;

Hilo *hilo1 = new Hilo();
int correlativo=1;
int correlativo2=1;
ListaMatrices::ListaMatrices(){
    this->raiz=NULL;
    this->raiz2=NULL;
}
typedef struct NodoABB nodoABB;
typedef struct NodoABB2 nodoABB2;
///*******Punteros Primero y Ultimo de la Lista Doble**************
typedef struct NodoDoble NodoD;
NodoD *primeroD;
NodoD *ultimoD;

typedef struct NodoFila NodoF;
typedef struct NodoColumna NodoC;
typedef struct NodoMatriz NodoM;

typedef struct NodoTipo1 NodoT1;
NodoT1 *primeroT1;
NodoT1 *ultimoT1;

typedef struct NodoTipo2 NodoT2;
NodoT2 *primeroT2;
NodoT2 *ultimoT2;

typedef struct NodoTipo3 NodoT3;
NodoT3 *primeroT3;
NodoT3 *ultimoT3;

typedef struct NodoPila NodoP;
NodoP *primeroP;
NodoP *ultimoP;

typedef struct NodoEliminados NodoE;
NodoE *primeroE;
NodoE *ultimoE;

typedef struct NodoLista_Modificada NodoLM;
NodoLM *primeroLM;
NodoLM *ultimoLM;

////******Agrear a la lista Doble********************************
void ListaMatrices::Agregar_Lista_Doble(int Nivel){
    ///Declarar Nodo de la Lista Doble....
    NodoD *nuevoD;
    nuevoD = (NodoD*)malloc(sizeof(struct NodoDoble));
    nuevoD->Nivel=Nivel;
    nuevoD->sig=NULL;
    nuevoD->ant=NULL;
    nuevoD->PrimeroIzquierda=NULL;
    nuevoD->UltimoIzquierda=NULL;
    nuevoD->PrmeroAbajo=NULL;
    nuevoD->UltimoAbajo=NULL;

    if(primeroD==NULL){
        nuevoD->Activo=1;
        nuevoD->sig=NULL;
        nuevoD->ant=NULL;
        primeroD=nuevoD;
        ultimoD=nuevoD;


    }else{
        nuevoD->Activo=0;
        nuevoD->sig=NULL;
        nuevoD->ant=ultimoD;
        ultimoD->sig=nuevoD;
        ultimoD=nuevoD;

    }
}
///Agrear las Dimensiones de los Niveles...............................
void ListaMatrices::Agregar_DimensionT(int T){
    hilo1->DimensionT=T;

    for(int i=1; i<=hilo1->DimensionT; i++){
        Agregar_Lista_Doble(i);
        cout<<"Lista:"<<i<<endl;
    }

    Graficar_Lista_Doble();

}
///Agregar un Nivel mas................................................
void ListaMatrices::Agregar_Nivel(){
    hilo1->DimensionT++;
    Agregar_Lista_Doble(hilo1->DimensionT);
    Graficar_Lista_Doble();

}

///Eliminar Lista Doble de los Niveles................................
void ListaMatrices::Eliminar_Lista_Doble(){
    if(primeroD==ultimoD){
        primeroD=ultimoD=NULL;
    }else{
        ultimoD->ant->sig=NULL;
        ultimoD=ultimoD->ant;
    }

}

///Eliminar un Nivel.................................................
void ListaMatrices::Eliminar_Nivel(){
    hilo1->DimensionT--;
    Eliminar_Lista_Doble();
    Graficar_Lista_Doble();
}


///*********Graficar Lista Doble (Niveles Individual)**********************
void ListaMatrices::Graficar_Lista_Doble(){
    FILE *gra;
    gra=fopen("ListaDoble.dot","wt");
    fputs("digraph g {\n ",gra);
    fputs("node [\n" ,gra);
    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);    
    fputs("style =\"filled, bold\"\n",gra);
    fputs("];\n",gra);

    if(ultimoD!=NULL){
    fputs("\n subgraph cluster_1 {\n",gra);
    fputs("node [style=filled];\n",gra);
    int a=1;
    NodoD *aux=ultimoD;
    while(aux!=NULL){
        fputs("\"",gra);
        fputs("nodoD",gra);
        fprintf(gra,"%d",a);
        fputs("\"",gra);
        fputs("\n[ ",gra);
        fprintf(gra, "label=\" " );
            fputs("Nivel: ",gra);
            fprintf(gra, "%d",aux->Nivel);
            if(aux->Nivel==hilo1->Nivel){
            fputs(" &#92;n ",gra);
            fputs("Usuario ",gra);
            }

            fputs("\",width =\"1.5\",fontcolor=black,shape=square,labelloc = b,",gra);
            if(aux->Activo==1){
                fputs("image=\"si.png\"",gra);
            }else if(aux->Activo==0){
                fputs("image=\"no.png\"",gra);
            }

            fputs(" ];\n",gra);
        a++;
        aux=aux->ant;
    }


    int b =1;
    int c =b+1;
    aux=ultimoD;
    if(ultimoD!=NULL){
         while(aux->ant!=NULL){
            /// nodo1---->nodo2 siguintes
            fputs("\"nodoD",gra);
            fprintf(gra,"%d",b);
            fputs("\"-> \"nodoD",gra);
            fprintf(gra,"%d",c);
            fputs( "\";\n",gra);

            fputs("\"nodoD",gra);
            fprintf(gra,"%d",c);
            fputs("\"-> \"nodoD",gra);
            fprintf(gra,"%d",b);
            fputs( "\";\n",gra);

            b++;
            c++;
            aux=aux->ant;
        }
    }


    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"orange\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("label =\"Niveles\"\n",gra);
    fputs("}\n",gra);

 }else{
     ///La lista esta Vacia...
        fputs("\n subgraph cluster_1 {\n",gra);
        fputs("node [style=filled];\n",gra);

        fputs("\"",gra);
        fputs("nodoD",gra);
        fputs("\"",gra);
        fputs("\n[ ",gra);
        fprintf(gra, "label=\" Niveles" );
        fputs("\"];\n",gra);

        fputs("fontsize = \"10\"\n",gra);
        fputs("shape = \"Mrecord\"\n",gra);
        fputs("color=\"orange\"\n",gra);
        fputs("style =\"filled, bold\"\n",gra);
        fputs("label =\"Niveles\"\n",gra);
        fputs("}\n",gra);

        printf("Lista de la Carretera esta vacia, esta Vacia...");


  }
 fputs("}",gra);
 fclose(gra);
 system("dot -Tpng ListaDoble.dot -o ListaDoble.png");

}

///***********Agregar En Matriz******************************************
bool ListaMatrices::Agregar_En_Matriz(int enemigo, int id, int fila, int columna, int golpes){
    NodoD *actual=primeroD;
    int nivel =hilo1->Nivel;
    int x=0;
    int y=0;
    if(actual!=NULL){   ///Si la Lista Doble no esta vacia...
        while (actual!=NULL) {  ///Mientras la Lista Doble no sea Null...
            if(actual->Nivel==nivel){   ///Si el Nivel Buscado Existe....

                Agregar_Fila(actual, fila);
              //  cout<<"Agrego FIla...\n"<<endl;
                Agregar_Columna(actual, columna);
              //  cout<<"Agrego Columna...\n"<<endl;

                ///Declarar Nodo de la Matriz..........
                NodoM *nuevo;
                nuevo = (NodoM*)malloc(sizeof(struct NodoMatriz));
                nuevo->enemigo=enemigo;
                nuevo->Fila=fila;
                nuevo->Columna=columna;
                nuevo->ID=id;
                nuevo->golpes=golpes;
                nuevo->arriba=NULL;
                nuevo->abajo=NULL;
                nuevo->izq=NULL;
                nuevo->der=NULL;
                nuevo->sig=NULL;

                ///Insertar enlazado con la cabecera de las (Columnas)....................................
                NodoC *actualC=actual->PrimeroIzquierda;
                if(actualC!=NULL){
                    while(actualC!=NULL){
                        if(actualC->Columna==columna){///La columna existe...
                            if(actualC->primeroM==NULL){//Insertar el primero en Columna...

                                nuevo->abajo=NULL;
                                nuevo->arriba=NULL;
                                actualC->primeroM=nuevo;
                                actualC->ultmoM=nuevo;
                                x=1;
                            }else{
                                if(fila<actualC->primeroM->Fila){///Insertar al Inicio....

                                    nuevo->arriba=NULL;
                                    nuevo->abajo=actualC->primeroM;
                                    actualC->primeroM->arriba=nuevo;
                                    actualC->primeroM=nuevo;
                                    x=1;

                                }else if(fila>actualC->ultmoM->Fila){///Insertar al Final....

                                    nuevo->abajo=NULL;
                                    nuevo->arriba=actualC->ultmoM;
                                    actualC->ultmoM->abajo=nuevo;
                                    actualC->ultmoM=nuevo;
                                    x=1;

                                }else{///Insertar entre Dos nodos, de una Columna....
                                    NodoM *actualM=actualC->primeroM;
                                    if(actualM!=NULL){
                                        while(actualM!=NULL){
                                            if(actualM->Fila>fila){

                                                nuevo->abajo=actualM;
                                                nuevo->arriba=actualM->arriba;
                                                actualM->arriba->abajo=nuevo;
                                                actualM->arriba=nuevo;
                                                x=1;
                                                break;

                                            }else if(actualM->Fila==fila){/// Repetido, Agregar a la Pila...
                                              //  cout<<"\n Nodo de la Matriz Repetido.Se agrego a Pila.."<<endl;

                                                if(actualM==actualC->primeroM && actualM==actualC->ultmoM){///Pimero en  Columnas...
                                                    nuevo->sig=actualC->primeroM;
                                                    actualC->primeroM=nuevo;
                                                    actualC->ultmoM=nuevo;
                                                    x=1;

                                                }else if(actualM==actualC->primeroM){
                                                    nuevo->sig=actualC->primeroM;
                                                    nuevo->abajo=actualC->primeroM->abajo;
                                                    actualC->primeroM->abajo->arriba=nuevo;
                                                    actualM->abajo=NULL; //Correcion... actualC->primeroM->abajo=NULL;
                                                    actualC->primeroM=nuevo;
                                                    x=1;

                                                }else if(actualM==actualC->ultmoM){
                                                    nuevo->sig=actualC->ultmoM;
                                                    nuevo->arriba=actualC->ultmoM->arriba;  //Correciones...
                                                    actualC->ultmoM->arriba->abajo=nuevo;
                                                    actualM->arriba=NULL;
                                                    actualC->ultmoM=nuevo;
                                                    x=1;

                                                }else{
                                                    nuevo->sig=actualM;
                                                    actualM->abajo->arriba=nuevo;
                                                    actualM->arriba->abajo=nuevo;
                                                    nuevo->abajo=actualM->abajo;
                                                    nuevo->arriba=actualM->arriba;
                                                    actualM->arriba==NULL;
                                                    actualM->abajo=NULL;
                                                    x=1;

                                                }

                                                break;
                                            }
                                         actualM=actualM->abajo;
                                        }
                                    }

                                }

                            }

                        }
                     actualC=actualC->Izq;
                    }

               //   cout<<"Enlazado a Columna...\n"<<endl;
                }

                ///Insertar Enlazado a la Cabecera de las (Filas)......................................................
                NodoF *actualF=actual->PrmeroAbajo;
                if(actualF!=NULL){
                    while(actualF!=NULL){
                        if(actualF->Fila==fila){///La columna existe...
                            if(actualF->primeroM==NULL){//Insertar el primero en Fila...

                                nuevo->izq=NULL;
                                nuevo->der=NULL;
                                actualF->primeroM=nuevo;
                                actualF->ultmoM=nuevo;
                                y=1;

                            }else{
                                if(columna<actualF->primeroM->Columna){///Insertar al Inicio....

                                    nuevo->der=NULL;
                                    nuevo->izq=actualF->primeroM;
                                    actualF->primeroM->der=nuevo;
                                    actualF->primeroM=nuevo;
                                    y=1;

                                }else if(columna>actualF->ultmoM->Columna){///Insertar al Final....

                                    nuevo->izq=NULL;
                                    nuevo->der=actualF->ultmoM;
                                    actualF->ultmoM->izq=nuevo;
                                    actualF->ultmoM=nuevo;
                                    y=1;

                                }else{///Insertar entre Dos nodos, de una Fila....
                                    NodoM *actualM=actualF->primeroM;
                                    if(actualM!=NULL){
                                        while(actualM!=NULL){
                                            if(actualM->Columna>columna){

                                                nuevo->izq=actualM;
                                                nuevo->der=actualM->der;
                                                actualM->der->izq=nuevo;
                                                actualM->der=nuevo;
                                                y=1;
                                                break;

                                            }else if(actualM->Columna==columna){/// Repetido, Agregar a la Pila...

                                               if(actualM==actualF->primeroM && actualM==actualF->ultmoM){///Pimero en  Filas...
                                                    nuevo->sig=actualF->primeroM;
                                                    actualF->primeroM=nuevo;
                                                    actualF->ultmoM=nuevo;
                                                    y=1;

                                                }else if(actualM==actualF->primeroM){
                                                    nuevo->sig=actualF->primeroM;
                                                    nuevo->izq=actualF->primeroM->izq;
                                                    actualF->primeroM->izq->der=nuevo;
                                                    actualF->primeroM=nuevo;
                                                    actualM->izq=NULL;
                                                    actualM->der=NULL;

                                                    y=1;

                                                }else if(actualM==actualF->ultmoM){
                                                    nuevo->sig=actualF->ultmoM;
                                                    nuevo->der=actualF->ultmoM->der;
                                                    actualF->ultmoM->der->izq=nuevo;
                                                    actualF->ultmoM=nuevo;
                                                    actualM->der=NULL;
                                                    actualM->izq=NULL;



                                                    y=1;
                                                }else{
                                                    nuevo->sig=actualM;
                                                    actualM->izq->der=nuevo;
                                                    actualM->der->izq=nuevo;
                                                    nuevo->izq=actualM->izq;
                                                    nuevo->der=actualM->der;
                                                    actualM->der==NULL;
                                                    actualM->izq=NULL;
                                                    y=1;

                                                }

                                                break;
                                            }
                                         actualM=actualM->izq;
                                        }
                                    }

                                }

                            }


                        }
                     actualF=actualF->Abajo;
                    }

                }

            break;
            }else{
               actual->PrimeroIzquierda=NULL;
               actual->UltimoIzquierda=NULL;
               actual->PrmeroAbajo=NULL;
               actual->UltimoAbajo=NULL;
            }

        actual=actual->sig;
        }

    }else{
        cout<<"La lista de Niveles esta vacia...."<<endl;

    }

    if(x==1 && y==1){
        return true;
    }else{
        return false;
    }


}

///***********Agregar Cabecera Fila***************************************+
void ListaMatrices::Agregar_Fila(NodoDoble *Actual, int fila){
    NodoF *nuevoF;
    nuevoF = (NodoF*)malloc(sizeof(struct NodoFila));
    nuevoF->Fila=fila;
    nuevoF->Abajo=NULL;  //(*sig)->
    nuevoF->Arriba=NULL; //(*ant)<-
    nuevoF->primeroM=NULL;
    nuevoF->ultmoM=NULL;

    if(Actual->PrmeroAbajo==NULL){
        nuevoF->Abajo=NULL;
        nuevoF->Arriba=NULL;
        Actual->PrmeroAbajo=nuevoF;
        Actual->UltimoAbajo=nuevoF;
        nuevoF->primeroM=NULL;

    }else{

        if(fila<Actual->PrmeroAbajo->Fila){
            nuevoF->Arriba=NULL;
            nuevoF->Abajo=Actual->PrmeroAbajo;
            Actual->PrmeroAbajo->Arriba=nuevoF;
            Actual->PrmeroAbajo=nuevoF;
            nuevoF->primeroM=NULL;


        }else if(fila>Actual->UltimoAbajo->Fila){
            nuevoF->Abajo=NULL;
            nuevoF->Arriba=Actual->UltimoAbajo;
            Actual->UltimoAbajo->Abajo=nuevoF;
            Actual->UltimoAbajo=nuevoF;
            nuevoF->primeroM=NULL;

        }else{
            NodoF *aux=Actual->PrmeroAbajo;
            if(aux!=NULL){
                while (aux!=NULL) {
                    if(aux->Fila>fila){
                        nuevoF->Abajo=aux;
                        nuevoF->Arriba=aux->Arriba;
                        aux->Arriba->Abajo=nuevoF;
                        aux->Arriba=nuevoF;
                        nuevoF->primeroM=NULL;
                        break;

                    }else if(fila==aux->Fila){

                        break;
                    }

                 aux=aux->Abajo;
                }

            }


        }


    }


}

///***********Eliminar en la CabeceraFilas********************************
void ListaMatrices::Eliminar_Fila(int fila){
    NodoD *aux=primeroD;
    int Nivel=hilo1->Nivel;
    if(aux!=NULL){
        while(aux!=NULL){
            if(aux->Nivel==Nivel){
                NodoF *auxF=aux->PrmeroAbajo;
                if(auxF!=NULL){
                    while (auxF!=NULL){
                        if(auxF->Fila==fila){
                            ///Eliminar Fila....
                            if(auxF==aux->PrmeroAbajo && auxF==aux->UltimoAbajo){
                                aux->PrmeroAbajo=NULL;
                                aux->UltimoAbajo=NULL;

                            }else if(auxF==aux->PrmeroAbajo){
                                aux->PrmeroAbajo->Abajo->Arriba=NULL;
                                aux->PrmeroAbajo=aux->PrmeroAbajo->Abajo;
                                auxF->Abajo=NULL;
                            }else if(auxF==aux->UltimoAbajo){
                                aux->UltimoAbajo->Arriba->Abajo=NULL;
                                aux->UltimoAbajo=aux->UltimoAbajo->Arriba;
                                auxF->Arriba=NULL;
                            }else{
                                auxF->Arriba->Abajo=auxF->Abajo;
                                auxF->Abajo->Arriba=auxF->Arriba;
                                auxF->Abajo=NULL;
                                auxF->Arriba=NULL;
                            }
                         break;
                        }
                     auxF=auxF->Abajo;
                    }
                }

              break;
            }
         aux=aux->sig;
        }
    }
}

///***********Agregar Cabecera Columna*************************************
void ListaMatrices::Agregar_Columna(NodoDoble *Actual, int columna){
    NodoC *nuevoC;
    nuevoC = (NodoC*)malloc(sizeof(struct NodoColumna));
    nuevoC->Columna=columna;
    nuevoC->Izq=NULL;  //(*sig)<-
    nuevoC->Der=NULL;  //(*ant)->
    nuevoC->primeroM=NULL;
    nuevoC->ultmoM=NULL;

    if(Actual->PrimeroIzquierda==NULL){
        nuevoC->Izq=NULL;
        nuevoC->Der=NULL;
        Actual->PrimeroIzquierda=nuevoC;
        Actual->UltimoIzquierda=nuevoC;
        nuevoC->primeroM=NULL;

    }else{

        if(columna<Actual->PrimeroIzquierda->Columna){
            nuevoC->Der=NULL;
            nuevoC->Izq=Actual->PrimeroIzquierda;
            Actual->PrimeroIzquierda->Der=nuevoC;
            Actual->PrimeroIzquierda=nuevoC;
            nuevoC->primeroM=NULL;


        }else if(columna>Actual->UltimoIzquierda->Columna){
            nuevoC->Izq=NULL;
            nuevoC->Der=Actual->UltimoIzquierda;
            Actual->UltimoIzquierda->Izq=nuevoC;
            Actual->UltimoIzquierda=nuevoC;
            nuevoC->primeroM=NULL;

        }else{
            NodoC *aux=Actual->PrimeroIzquierda;
            if(aux!=NULL){
                while (aux!=NULL) {
                    if(aux->Columna>columna){
                        nuevoC->Izq=aux;
                        nuevoC->Der=aux->Der;
                        aux->Der->Izq=nuevoC;
                        aux->Der=nuevoC;
                        nuevoC->primeroM=NULL;
                        break;

                    }else if(columna==aux->Columna){

                        break;
                    }

                 aux=aux->Izq;
                }

            }


        }


    }

}

///**************Eliminar en Cabecara Columnas*************************
void ListaMatrices::Eliminar_Columna(int columna){
    int Nivel=hilo1->Nivel;
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while(aux!=NULL){
            if(aux->Nivel==Nivel){
                NodoC *auxC=aux->PrimeroIzquierda;
                if(auxC!=NULL){
                    while (auxC!=NULL){
                        if(auxC->Columna==columna){
                            ///Eliminar Columna....
                            if(auxC==aux->PrimeroIzquierda && auxC==aux->UltimoIzquierda){
                                aux->PrimeroIzquierda=NULL;
                                aux->UltimoIzquierda=NULL;

                            }else if(auxC==aux->PrimeroIzquierda){
                                aux->PrimeroIzquierda->Izq->Der=NULL;
                                aux->PrimeroIzquierda=aux->PrimeroIzquierda->Izq;
                                auxC->Izq=NULL;
                            }else if(auxC==aux->UltimoIzquierda){
                                aux->UltimoIzquierda->Der->Izq=NULL;
                                aux->UltimoIzquierda=aux->UltimoIzquierda->Der;
                                auxC->Der=NULL;
                            }else{
                                auxC->Der->Izq=auxC->Izq;
                                auxC->Izq->Der=auxC->Der;
                                auxC->Izq=NULL;
                                auxC->Der=NULL;
                            }
                         break;
                        }
                     auxC=auxC->Izq;
                    }
                }

              break;
            }
         aux=aux->sig;
        }
    }
}

///***************Grafica de la Matriz Dispersa************************
void ListaMatrices::Grafica_Matriz_Por_Niveles(){
    int Nivel=hilo1->Nivel;
    FILE *gra;
    gra=fopen("MatrizDispersa.dot","wt");
    fputs("digraph g {\n ",gra);

    int vacio=0;
    if(primeroD!=NULL){
        NodoD *aux=primeroD;
        while(aux!=NULL){
            if(aux->Nivel==Nivel){

    fputs("\n subgraph cluster_1 {\n",gra);

    int a=1;
    NodoD *aux=primeroD;
    if(aux!=NULL){
    while(aux!=NULL){
        if(aux->Nivel==Nivel){
            ///Crear Nodo Raiz.........
            fputs("\"nodoD",gra);
            fprintf(gra,"%d",Nivel);
            fputs("\"[label=\"",gra);
            fputs("Nivel: ",gra);
            fprintf(gra, "%d",Nivel);
            fputs("\",style=filled,shape=square];\n",gra);
            fputs("\n",gra);
            ///Crear Nodos de las Cabeceras (Filas).........
            int aa=1;
            NodoF *auxF=aux->PrmeroAbajo;
            if(auxF!=NULL){
                while (auxF!=NULL) {
                    fputs("\"nodoF",gra);
                    fprintf(gra,"%d",aa);
                    fputs("\"[label=\"",gra);
                    fputs("Y: ",gra);
                    fprintf(gra, "%d",auxF->Fila);
                    fputs("\",style=filled,shape=square];\n",gra);
                    aa++;

                    ///Crear los Nodos de la Matriz Fila x Fila..................
                    NodoM *actualM=auxF->primeroM;

                    if(actualM!=NULL){
                        while(actualM!=NULL){
                            fputs("\"nodoM",gra);
                            fprintf(gra,"%d",actualM->ID);
                            fputs("\"[label=\"",gra);
                            fprintf(gra, "%d",actualM->ID);
                            fputs("\",width =\"0.7\",style=filled,fontcolor=black,shape=square,labelloc = b,",gra);
                            if(actualM->enemigo==1){
                                fputs("image=\"enemigo1.png\"",gra);
                            }else if(actualM->enemigo==2){
                                fputs("image=\"enemigo2.png\"",gra);
                            }else{
                                fputs("image=\"enemigo3.png\"",gra);
                            }
                            fputs(" ];\n",gra);
                         actualM=actualM->izq;
                        }
                        fputs("\n",gra);
                    }

                auxF=auxF->Abajo;
                }

            }
           // cout<<"FILAS CREADAS..."<<endl;
            ///Crear Nodos de las Cabeceras (Columnas).........
            aa=1;
            NodoC *auxC=aux->PrimeroIzquierda;
            if(auxC!=NULL){
                while (auxC!=NULL) {
                    fputs("\"nodoC",gra);
                    fprintf(gra,"%d",aa);
                    fputs("\"[label=\"",gra);
                    fputs("X: ",gra);
                    fprintf(gra, "%d",auxC->Columna);
                    fputs("\",style=filled,shape=square];\n",gra);
                    aa++;
                auxC=auxC->Izq;
                }

            }

        break;
        }
        a++;
        aux=aux->sig;
    }
   }
    ///Crear los Rank.............................................................................
    ///Rank de las Cabecera de Columnas....

    if(primeroD!=NULL){
        aux=primeroD;
         a=1;
         while(aux!=NULL){
             if(aux->Nivel==Nivel){


                 NodoC *auxC=aux->UltimoIzquierda;
                 int aa=1;
                 if(auxC!=NULL){
                     fputs("{rank = same; ",gra);
                     while (auxC!=NULL){
                         fputs("\"",gra);
                         fputs("nodoC",gra);
                         fprintf(gra,"%d",aa);
                         fputs("\"",gra);
                         fputs(";",gra);
                         aa++;
                      auxC=auxC->Der;
                     }
                     fputs("\"",gra);
                     fputs("nodoD",gra);
                     fprintf(gra,"%d",Nivel);
                     fputs("\"",gra);
                     fputs(";",gra);
                     fputs("}\n",gra);
                  }

                 ///Rank de la Matriz por filas........

                 NodoF *auxF=aux->PrmeroAbajo;
                 if(auxF!=NULL){
                     int a =1;
                     while(auxF!=NULL){
                          fputs("{rank = same; ",gra);
                                NodoM *auxM=auxF->ultmoM;
                                if(auxM!=NULL){
                                   while(auxM!=NULL){
                                       if(auxM!=NULL){
                                        fputs("\"",gra);
                                        fputs("nodoM",gra);
                                        fprintf(gra,"%d",auxM->ID);
                                        fputs("\"",gra);
                                        fputs(";",gra);
                                        auxM=auxM->der;
                                       }
                                    }
                                }

                          fputs("\"",gra);
                          fputs("nodoF",gra);
                          fprintf(gra,"%d",a);
                          fputs("\"",gra);
                          fputs(";",gra);
                          fputs("}\n",gra);
                      a++;
                      auxF=auxF->Abajo;
                     }
                 }
              break;
             }

          a++;
          aux=aux->sig;
        }
    }
  //  cout<<"RANK CREADAS..."<<endl;

    ////Crear los Enlaces.........................................................................
    if(primeroD!=NULL){
        aux=primeroD;
         while(aux!=NULL){
            if(aux->Nivel==Nivel){
            int bb =1;
            int cc =bb+1;
                /// nodoC---->nodoC
                NodoC *auxC=aux->PrimeroIzquierda;
                if(auxC!=NULL){
                    while(auxC!=NULL){
                        if(auxC!=aux->UltimoIzquierda){


                        fputs("\"nodoC",gra);
                        fprintf(gra,"%d",cc);
                        fputs("\"-> \"nodoC",gra);
                        fprintf(gra,"%d",bb);
                        fputs( "\"[dir=both,color=\"black:blue\"];\n",gra);

                                    fputs("\"nodoC",gra);
                                    fprintf(gra,"%d",bb);
                                    fputs("\"-> \"nodoM",gra);
                                    fprintf(gra,"%d",auxC->primeroM->ID);
                                    fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);


                                NodoM *auxM=auxC->primeroM;
                                if(auxM!=NULL){
                                    while(auxM!=NULL){
                                        if(auxM!=auxC->ultmoM){
                                            fputs("\"nodoM",gra);
                                            fprintf(gra,"%d",auxM->abajo->ID);
                                            fputs("\"-> \"nodoM",gra);
                                            fprintf(gra,"%d",auxM->ID);
                                            fputs( "\"[dir=both,color=\"black:blue\"];\n",gra);

                                        }

                                    auxM=auxM->abajo;
                                    }
                                }




                        bb++;
                        cc++;
                        }else{

                            fputs("\"nodoC",gra);
                            fprintf(gra,"%d",bb);
                            fputs("\"-> \"nodoM",gra);
                            fprintf(gra,"%d",auxC->primeroM->ID);
                            fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);

                            NodoM *auxM=auxC->primeroM;
                            if(auxM!=NULL){
                                while(auxM!=NULL){
                                    if(auxM!=auxC->ultmoM){                                      
                                        fputs("\"nodoM",gra);
                                        fprintf(gra,"%d",auxM->ID);
                                        fputs("\"-> \"nodoM",gra);
                                        fprintf(gra,"%d",auxM->abajo->ID);
                                        fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);

                                    }
                                auxM=auxM->abajo;
                                }
                            }


                        }
                    auxC=auxC->Izq;
                    }

                    /// Raiz---->nodoC
                    fputs("\"nodoC",gra);
                    fprintf(gra,"%d",1);
                    fputs("\"-> \"nodoD",gra);
                    fprintf(gra,"%d",Nivel);
                    fputs( "\"[dir=both,color=\"black:blue\"];\n",gra);



                }

                fputs("\n",gra);

                /// nodoF---->nodoF
                NodoF *auxF=aux->PrmeroAbajo;                
                auxF=aux->PrmeroAbajo;
                if(auxF!=NULL){
                    int b=1;
                    int c=b+1;
                    while(auxF!=NULL){
                        if(auxF!=aux->UltimoAbajo){
                        fputs("\"nodoF",gra);
                        fprintf(gra,"%d",b);
                        fputs("\"-> \"nodoF",gra);
                        fprintf(gra,"%d",c);
                        fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);




                                fputs("\"nodoM",gra);
                                fprintf(gra,"%d",auxF->primeroM->ID);
                                fputs("\"-> \"nodoF",gra);
                                fprintf(gra,"%d",b);
                                fputs( "\"[dir=both,color=\"black:blue\"];\n",gra);



                                ///nodoM->nodoM
                                NodoM *auxM=auxF->primeroM;
                                if(auxM!=NULL){
                                    while(auxM!=NULL){
                                        if(auxM!=auxF->ultmoM){
                                              /// FILAS.................................
                                            if(auxM!=auxF->ultmoM){
                                            fputs("\"nodoM",gra);
                                            fprintf(gra,"%d",auxM->ID);
                                            fputs("\"-> \"nodoM",gra);
                                            fprintf(gra,"%d",auxM->izq->ID);
                                            fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);
                                            }

                                        }

                                    auxM=auxM->izq;
                                    }

                                }




                        b++;
                        c++;
                        }else{

                            fputs("\"nodoF",gra);
                            fprintf(gra,"%d",b);
                            fputs("\"-> \"nodoM",gra);
                            fprintf(gra,"%d",auxF->primeroM->ID);
                            fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);

                            ///nodoM->nodoM
                            NodoM *auxM=auxF->primeroM;
                            if(auxM!=NULL){
                                while(auxM!=NULL){
                                    if(auxM!=auxF->ultmoM){

                                        fputs("\"nodoM",gra);
                                        fprintf(gra,"%d",auxM->ID);
                                        fputs("\"-> \"nodoM",gra);
                                        fprintf(gra,"%d",auxM->izq->ID);
                                        fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);
                                    }

                                auxM=auxM->izq;
                                }

                            }


                        }

                     auxF=auxF->Abajo;
                    }

                    /// Raiz---->nodoF


                    fputs("\"nodoD",gra);
                    fprintf(gra,"%d",Nivel);
                    fputs("\"-> \"nodoF",gra);
                    fprintf(gra,"%d",1);
                    fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);
                }



             break;
            }
         aux=aux->sig;
        }


    }



            fputs("color=\"orange\"\n",gra);

            fputs("style =\"filled, bold\"\n",gra);
            fputs("label =\"Matriz Dispersa\"\n",gra);
            fputs("}\n",gra);
            vacio=0;
            break;
            }else{
                vacio=1;

            }
        aux=aux->sig;
      }

 }else{

        ///La lista esta Vacia...
        fputs("\n subgraph cluster_1 {\n",gra);
        fputs("node [style=filled];\n",gra);

        fputs("\"",gra);
        fputs("nodoD",gra);
        fputs("\"",gra);
        fputs("\n[ ",gra);
        fprintf(gra, "label=\" Niveles" );
        fputs("\"];\n",gra);

        fputs("color=\"orange\"\n",gra);
        fputs("style =\"filled, bold\"\n",gra);
        fputs("label =\"Matriz Dispersa\"\n",gra);
        fputs("}\n",gra);




  }

    if(vacio==1){
        ///La lista esta Vacia...
        fputs("\n subgraph cluster_1 {\n",gra);
        fputs("node [style=filled];\n",gra);

        fputs("\"",gra);
        fputs("nodoD",gra);
        fputs("\"",gra);
        fputs("\n[ ",gra);
        fprintf(gra, "label=\" Niveles" );
        fputs("\"];\n",gra);

        fputs("color=\"orange\"\n",gra);
        fputs("style =\"filled, bold\"\n",gra);
        fputs("label =\"Matriz Dispersa\"\n",gra);
        fputs("}\n",gra);


    }

 fputs("}",gra);
 fclose(gra);
 system("dot -Tpng MatrizDispersa.dot -o MatrizDispersa.png");
// system("kfmclient exec MatrizDispersa.png");


}







///*************Funciones del Juego************+*******************************************

///Crear objetos en la Matriz aleatoriamente..............................
QString ListaMatrices::Crear_Objetos_en_Matriz(){
    srand(time(NULL));
    int T=hilo1->DimensionT;//Tamaño T.
    int N=hilo1->Nivel;//Nivel Actual.
    int ID=hilo1->ID_enemgo;//ID de los enemigos.
    QString consola;
    int x=0;//Posicion X.
    int y=0;//Posicion Y.
    int e=0;//Tipo de Enemigo.
    int g=1;//Cantidad de vidas..
    if(T>0){
        x=1+rand()%(T);
        y=1+rand()%(T);
        e=1+rand()%(3);

        if(e==1){
            g=1;
        }else if(e==2){
            g=3;
        }else if(e==3){
            g=5;
        }


       if(Agregar_En_Matriz(e,ID,y,x,g)==true){
           hilo1->ID_enemgo++;
           Grafica_Matriz_Por_Niveles();

         //  cout<<"GRAFICA..."<<x<<","<<y<<" ID"<<ID<<endl;
           consola = QString("Mensaje de 200915305: Se agrego enemigo Tipo:%1, ID:%2 Posicion:(Y:%3,X:%4)\n").arg(e).arg(ID).arg(y).arg(x);
       }else{
           consola = QString("Mensaje de 200915305: x: %1, y: %2\n").arg(x).arg(y);
       }



    }else {
        return "Mensaje de 200915305: No se a Asignado un Tamaño T a la Matriz...\n";
    }

    return consola;
}

///Movimientos de los Objetos.........................................................
///
QString ListaMatrices::Mover_Objetos_en_Matriz(){
    srand(time(NULL));
    int T=hilo1->DimensionT;//Tamaño T.
    int N=hilo1->Nivel;//Nivel Actual.
    QString texto="";
    QString texto1="";
    Objetos_En_Pila();

     NodoP *auxP=primeroP;
    if(auxP!=NULL){
        while(auxP!=NULL){

            NodoD *aux=primeroD;
            if(aux!=NULL){
                while(aux!=NULL){
                    if(aux->Nivel=N){
                        NodoF *auxF=aux->PrmeroAbajo;
                        if(auxF!=NULL){
                            while(auxF!=NULL){
                                if(auxF->Fila==auxP->fila){
                                    NodoM *auxM=auxF->primeroM;
                                    if(auxM!=NULL){
                                        int Rrandom=1;
                                        while (auxM!=NULL) {
                                            if(auxM->Columna==auxP->columna){

                                                Rrandom=1+rand()%(4);

                                                if(Rrandom==1){
                                                    if(auxM->Fila!=1){
                                                        //Arribal..
                                                        Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila-1,auxM->Columna,auxM->golpes);
                                                        Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                        texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila-1);
                                                        texto.append(texto1);
                                                        cout<<"Entro....1"<<endl;

                                                     }else if(auxM->Columna!=1){
                                                        //Izquierda..
                                                             Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila,auxM->Columna-1,auxM->golpes);
                                                             Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                             texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna-1).arg(auxM->Fila);
                                                             texto.append(texto1);
                                                             cout<<"Entro....2"<<endl;

                                                      }else if(auxM->Fila!=T){
                                                        //Abajo...
                                                        Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila+1,auxM->Columna,auxM->golpes);
                                                        Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                        texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila+1);
                                                        texto.append(texto1);
                                                        cout<<"Entro....3"<<endl;

                                                     }else if(auxM->Fila!=T){
                                                        //Abajo...
                                                        Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila+1,auxM->Columna,auxM->golpes);
                                                        Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                        texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila+1);
                                                        texto.append(texto1);
                                                        cout<<"Entro....3"<<endl;
                                                       }

                                                }else if(Rrandom==2){
                                                    if(auxM->Columna!=1){
                                                    //Izquierda..
                                                         Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila,auxM->Columna-1,auxM->golpes);
                                                         Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                         texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna-1).arg(auxM->Fila);
                                                         texto.append(texto1);
                                                         cout<<"Entro....2"<<endl;
                                                   }else if(auxM->Fila!=1){
                                                        //Arribal..
                                                        Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila-1,auxM->Columna,auxM->golpes);
                                                        Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                        texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila-1);
                                                        texto.append(texto1);
                                                        cout<<"Entro....1"<<endl;

                                                    }else if(auxM->Fila!=T){
                                                    //Abajo...
                                                    Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila+1,auxM->Columna,auxM->golpes);
                                                    Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                    texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila+1);
                                                    texto.append(texto1);
                                                    cout<<"Entro....3"<<endl;

                                                 }else if(auxM->Fila!=T){
                                                    //Abajo...
                                                    Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila+1,auxM->Columna,auxM->golpes);
                                                    Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                    texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila+1);
                                                    texto.append(texto1);
                                                    cout<<"Entro....3"<<endl;
                                                   }

                                                }else if(Rrandom==3){
                                                    if(auxM->Fila!=T){
                                                      //Abajo...
                                                      Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila+1,auxM->Columna,auxM->golpes);
                                                      Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                      texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila+1);
                                                      texto.append(texto1);
                                                      cout<<"Entro....3"<<endl;
                                                   }else if(auxM->Fila!=1){
                                                        //Arribal..
                                                        Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila-1,auxM->Columna,auxM->golpes);
                                                        Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                        texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila-1);
                                                        texto.append(texto1);
                                                        cout<<"Entro....1"<<endl;

                                                     }else if(auxM->Columna!=1){
                                                        //Izquierda..
                                                             Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila,auxM->Columna-1,auxM->golpes);
                                                             Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                             texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna-1).arg(auxM->Fila);
                                                             texto.append(texto1);
                                                             cout<<"Entro....2"<<endl;

                                                      }else if(auxM->Fila!=T){
                                                        //Abajo...
                                                        Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila+1,auxM->Columna,auxM->golpes);
                                                        Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                        texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila+1);
                                                        texto.append(texto1);
                                                        cout<<"Entro....3"<<endl;
                                                       }

                                                }else if(Rrandom==4){
                                                    if(auxM->Fila!=T){
                                                      //Abajo...
                                                      Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila+1,auxM->Columna,auxM->golpes);
                                                      Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                      texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila+1);
                                                      texto.append(texto1);
                                                      cout<<"Entro....3"<<endl;
                                                     }else if(auxM->Fila!=1){
                                                        //Arribal..
                                                        Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila-1,auxM->Columna,auxM->golpes);
                                                        Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                        texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila-1);
                                                        texto.append(texto1);
                                                        cout<<"Entro....1"<<endl;

                                                     }else if(auxM->Columna!=1){
                                                        //Izquierda..
                                                             Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila,auxM->Columna-1,auxM->golpes);
                                                             Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                             texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna-1).arg(auxM->Fila);
                                                             texto.append(texto1);
                                                             cout<<"Entro....2"<<endl;

                                                      }else if(auxM->Fila!=T){
                                                        //Abajo...
                                                        Agregar_En_Matriz(auxM->enemigo,auxM->ID,auxM->Fila+1,auxM->Columna,auxM->golpes);
                                                        Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                        texto1= QString("Mensaje de 200915305: MOVIMIENTO enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila+1);
                                                        texto.append(texto1);
                                                        cout<<"Entro....3"<<endl;

                                                     }
                                                }



                                             break;
                                            }
                                         auxM=auxM->izq;
                                        }
                                    }
                                 break;
                                }
                             auxF=auxF->Abajo;
                            }
                        }
                    break;
                    }
                 aux=aux->sig;
                }
            }

         auxP=auxP->sig;
        }
        primeroP=NULL;
    }



     Grafica_Matriz_Por_Niveles();

    return texto;
}

///Objetos en Pila en cada nodo de la matriz.....................................................................
void ListaMatrices::Agregar_A_Pila(int fila, int columna){
    NodoP *nuevo;
    nuevo=(NodoP*)malloc(sizeof(struct NodoPila));
    nuevo->fila=fila;
    nuevo->columna=columna;
    nuevo->sig=NULL;

    if(primeroP==NULL){
        nuevo->sig=NULL;
        primeroP=nuevo;
    }else{
        nuevo->sig=primeroP;
        primeroP=nuevo;
    }

}

///Agregar a Pila de enemigos eliminados en general...............................................................
void ListaMatrices::Agregar_Enemigos_Eliminados(int enemigo, int id, int fila, int columna){
    NodoE *nuevo;
    nuevo=(NodoE*)malloc(sizeof(struct NodoEliminados));
    nuevo->Fila=fila;
    nuevo->Columna=columna;
    nuevo->ID=id;
    nuevo->enemigo=enemigo;
    nuevo->sig=NULL;

    if(primeroE==NULL){
        nuevo->sig=NULL;
        primeroE=nuevo;
    }else{
        nuevo->sig=primeroE;
        primeroE=nuevo;
    }

}

void ListaMatrices::Objetos_En_Pila(){
    int N=hilo1->Nivel;//Nivel Actual.
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while(aux!=NULL){
            if(aux->Nivel==N){
                 cout<<"Movimeinto.********\n"<<endl;
                NodoF *auxF=aux->PrmeroAbajo;
                if(auxF!=NULL){
                    while(auxF!=NULL){
                            NodoM *auxM=auxF->primeroM;
                            cout<<"Fila........"<<auxF->Fila<<endl;
                            if(auxM!=NULL){

                                while(auxM!=NULL){
                                      Agregar_A_Pila(auxM->Fila,auxM->Columna);
                                      auxM=auxM->izq;
                                }
                            }
                     auxF=auxF->Abajo;
                    }
                }
            break;
            }
         aux=aux->sig;
        }
    }
}


bool ListaMatrices::Eliminar_En_Matriz(int fila, int columna){
    int N=hilo1->Nivel;//Nivel Actual.
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while(aux!=NULL){
            if(aux->Nivel==N){

                ///Eliminar elaces de Filas......
                NodoF *auxF=aux->PrmeroAbajo;
                if(auxF!=NULL){
                    while(auxF!=NULL){
                        if(auxF->Fila==fila){
                            NodoM *auxM=auxF->primeroM;
                            if(auxM!=NULL){
                                while(auxM!=NULL){
                                    if(auxM->Columna==columna){//Nodo Encontrado...
                                        if(auxM==auxF->primeroM && auxM==auxF->ultmoM){
                                            if(auxM->sig==NULL){
                                                auxF->primeroM=NULL;
                                                auxF->ultmoM=NULL;
                                                auxM->izq=NULL;
                                                auxM->der=NULL;
                                                Eliminar_Fila(fila);
                                            }else{
                                                auxF->primeroM=auxF->primeroM->sig;
                                                auxF->ultmoM=auxF->ultmoM->sig;
                                                auxM->izq=NULL;
                                                auxM->der=NULL;

                                            }

                                        }else if(auxM==auxF->primeroM){
                                            if(auxM->sig==NULL){
                                                auxF->primeroM->izq->der=NULL;
                                                auxF->primeroM=auxF->primeroM->izq;
                                                auxM->der=NULL;
                                                auxM->izq=NULL;
                                            }else{
                                                auxF->primeroM->izq->der=auxF->primeroM->sig;
                                                auxF->primeroM->sig->izq=auxF->primeroM->izq;
                                                auxF->primeroM=auxF->primeroM->sig;
                                                auxM->der=NULL;
                                                auxM->izq=NULL;

                                            }
                                        }else if(auxM==auxF->ultmoM){
                                            if(auxM->sig==NULL){
                                                auxF->ultmoM->der->izq=NULL;
                                                auxF->ultmoM=auxF->ultmoM->der;
                                                auxM->der=NULL;
                                            }else{
                                                auxF->ultmoM->der->izq=auxF->ultmoM->sig;
                                                auxF->ultmoM->sig->der=auxF->ultmoM->der;
                                                auxF->ultmoM=auxF->ultmoM->sig;
                                                auxM->der=NULL;
                                                auxM->izq=NULL;

                                            }
                                        }else{
                                            if(auxM->sig==NULL){
                                                auxM->izq->der=auxM->der;
                                                auxM->der->izq=auxM->izq;
                                                auxM->der=NULL;
                                                auxM->izq=NULL;
                                            }else{
                                                auxM->izq->der=auxM->sig;
                                                auxM->der->izq=auxM->sig;
                                                auxM->sig->izq=auxM->izq;
                                                auxM->sig->der=auxM->der;
                                                auxM->izq=NULL;
                                                auxM->der=NULL;

                                            }
                                        }


                                     break;
                                    }
                                 auxM=auxM->izq;
                                }
                            }
                         break;
                        }
                     auxF=auxF->Abajo;
                    }
                }

                ///Eliminar elaces de Columna......
                NodoC *auxC=aux->PrimeroIzquierda;
                if(auxC!=NULL){
                    while(auxC!=NULL){
                        if(auxC->Columna==columna){
                            NodoM *auxM=auxC->primeroM;
                            if(auxM!=NULL){
                                while(auxM!=NULL){
                                    if(auxM->Fila==fila){//Nodo Encontrado...
                                        if(auxM==auxC->primeroM && auxM==auxC->ultmoM){
                                            if(auxM->sig==NULL){
                                                auxC->primeroM=NULL;
                                                auxC->ultmoM=NULL;
                                                auxM->arriba=NULL;
                                                auxM->abajo=NULL;
                                                Eliminar_Columna(columna);
                                            }else{
                                                auxC->primeroM=auxC->primeroM->sig;
                                                auxC->ultmoM=auxC->ultmoM->sig;
                                                auxM->arriba=NULL;
                                                auxM->abajo=NULL;
                                                auxM->sig=NULL;
                                            }

                                        }else if(auxM==auxC->primeroM){
                                            if(auxM->sig==NULL){
                                                auxC->primeroM->abajo->arriba=NULL;
                                                auxC->primeroM=auxC->primeroM->abajo;
                                                auxM->abajo=NULL;
                                                auxM->arriba=NULL;
                                                auxM->abajo=NULL;
                                            }else{
                                                auxC->primeroM->abajo->arriba=auxC->primeroM->sig;
                                                auxC->primeroM->sig->abajo=auxC->primeroM->abajo;
                                                auxC->primeroM=auxC->primeroM->sig;
                                                auxM->arriba=NULL;
                                                auxM->abajo=NULL;
                                                auxM->sig=NULL;
                                            }
                                        }else if(auxM==auxC->ultmoM){
                                            if(auxM->sig==NULL){
                                                auxC->ultmoM->arriba->abajo=NULL;
                                                auxC->ultmoM=auxC->ultmoM->arriba;
                                                auxM->arriba=NULL;
                                            }else{
                                                auxC->ultmoM->arriba->abajo=auxC->ultmoM->sig;
                                                auxC->ultmoM->sig->arriba=auxC->ultmoM->arriba;
                                                auxC->ultmoM=auxC->ultmoM->sig;
                                                auxM->arriba=NULL;
                                                auxM->abajo=NULL;
                                                auxM->sig=NULL;
                                            }
                                        }else{
                                            if(auxM->sig==NULL){
                                                auxM->abajo->arriba=auxM->arriba;
                                                auxM->arriba->abajo=auxM->abajo;
                                                auxM->arriba=NULL;
                                                auxM->abajo=NULL;
                                            }else{
                                                auxM->abajo->arriba=auxM->sig;
                                                auxM->arriba->abajo=auxM->sig;
                                                auxM->sig->abajo=auxM->abajo;
                                                auxM->sig->arriba=auxM->arriba;
                                                auxM->abajo=NULL;
                                                auxM->arriba=NULL;
                                                auxM->sig=NULL;
                                            }
                                        }


                                     break;
                                    }
                                 auxM=auxM->abajo;
                                }
                            }
                         break;
                        }
                     auxC=auxC->Izq;
                    }
                }




             break;
            }
         aux=aux->sig;
        }

    }

    return true;
}

///****************BUSCAR PILA********************************************
QString ListaMatrices::Buscar_Pila(int x, int y){
    cout<<"Buscar en PIla..."<<endl;
    int N=hilo1->Nivel;//Nivel Actual.
    FILE *gra;
    gra=fopen("Pila.dot","wt");
    fputs("digraph g {\n ",gra);
    fputs("node [\n" ,gra);
    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("];\n",gra);

    if(primeroD!=NULL){
    fputs("\n subgraph cluster_1 {\n",gra);
    fputs("node [style=filled];\n",gra);
    NodoD *aux=primeroD;
    while(primeroD!=NULL){
        if(aux->Nivel==N){
            NodoF *auxF=aux->PrmeroAbajo;
            if(auxF!=NULL){
                while(auxF!=NULL){
                    if(auxF->Fila==y){
                        NodoM *auxM=auxF->primeroM;
                        if(auxM!=NULL){
                            while(auxM!=NULL){
                                if(auxM->Columna==x){///Nodo Encontrado
                                    NodoM *pila=auxM;
                                    if(pila!=NULL){
                                        while(pila!=NULL){
                                            fputs("\"nodoP",gra);
                                            fprintf(gra, "%d",pila->ID);
                                            fputs("\"[label=\"",gra);
                                            fprintf(gra, "%d",pila->ID);
                                            fputs("\",width =\"0.7\",fontcolor=black,shape=square,labelloc = b,",gra);
                                            if(pila->enemigo==1){
                                                fputs("image=\"enemigo1.png\"",gra);
                                            }else if(pila->enemigo==2){
                                                fputs("image=\"enemigo2.png\"",gra);
                                            }else{
                                                fputs("image=\"enemigo3.png\"",gra);
                                            }
                                            fputs(" ];\n",gra);
                                         pila=pila->sig;
                                        }

                                       pila=auxM;
                                       while(pila!=NULL){
                                           if(pila->sig!=NULL){
                                               fputs("\"nodoP",gra);
                                               fprintf(gra,"%d",pila->ID);
                                               fputs("\"-> \"nodoP",gra);
                                               fprintf(gra,"%d",pila->sig->ID);
                                               fputs( "\";\n",gra);

                                           }
                                        pila =pila->sig;
                                       }

                                    }
                                  break;
                                }
                             auxM=auxM->izq;
                            }

                        }

                     break;
                    }
                 auxF=auxF->Abajo;
                }
            }

         break;
        }
     aux=aux->sig;
    }




    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"orange\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("label =\"Pila\"\n",gra);
    fputs("}\n",gra);

 }else{
     ///La lista esta Vacia...
        fputs("\n subgraph cluster_1 {\n",gra);
        fputs("node [style=filled];\n",gra);

        fputs("\"",gra);
        fputs("nodoD",gra);
        fputs("\"",gra);
        fputs("\n[ ",gra);
        fprintf(gra, "label=\" Pila" );
        fputs("\"];\n",gra);

        fputs("fontsize = \"10\"\n",gra);
        fputs("shape = \"Mrecord\"\n",gra);
        fputs("color=\"orange\"\n",gra);
        fputs("style =\"filled, bold\"\n",gra);
        fputs("label =\"Pila\"\n",gra);
        fputs("}\n",gra);

        printf("La Pila, esta Vacia...");


  }
 fputs("}",gra);
 fclose(gra);
 system("dot -Tpng Pila.dot -o Pila.png");

 return "Pila...";
}

///********************Listas Doble Circulares*************************************

///************Lista Circular Tipo 1 ********************************
void ListaMatrices::Agregar_Lista_Tipo1(int tipo, int id){
    NodoT1 *nuevo;
    nuevo=(NodoT1*)malloc(sizeof(struct NodoTipo1));
    nuevo->tipo=tipo;
    nuevo->ID=id;
    nuevo->sig=NULL;
    nuevo->ant=NULL;

    if(primeroT1==NULL){
       nuevo->sig=NULL;
       nuevo->ant=NULL;
       primeroT1=nuevo;
       ultimoT1=nuevo;

    }else if(id<primeroT1->ID){
            nuevo->ant=NULL;
            nuevo->sig=primeroT1;
            primeroT1->ant=nuevo;
            primeroT1=nuevo;

    }else if(id>ultimoT1->ID){
            nuevo->sig=NULL;
            nuevo->ant=ultimoT1;
            ultimoT1->sig=nuevo;
            ultimoT1=nuevo;

    }else{

            NodoT1 *aux=primeroT1;
            if(aux!=NULL){
                while(aux!=NULL){
                     if(aux->ID>id){
                        nuevo->sig=aux;
                        nuevo->ant=aux->ant;
                        aux->ant->sig=nuevo;
                        aux->ant=nuevo;
                        break;
                     }else{
                         cout<<"No se agrega Repetido..."<<endl;
                     }
                  aux=aux->sig;
                }
            }

        }

    }


///************Lista Circular Tipo 2 ********************************
void ListaMatrices::Agregar_Lista_Tipo2(int tipo, int id){
    NodoT2 *nuevo;
    nuevo=(NodoT2*)malloc(sizeof(struct NodoTipo2));
    nuevo->tipo=tipo;
    nuevo->ID=id;
    nuevo->sig=NULL;
    nuevo->ant=NULL;

    if(primeroT2==NULL){
       nuevo->sig=NULL;
       nuevo->ant=NULL;
       primeroT2=nuevo;
       ultimoT2=nuevo;

    }else if(id<primeroT2->ID){
            nuevo->ant=NULL;
            nuevo->sig=primeroT2;
            primeroT2->ant=nuevo;
            primeroT2=nuevo;

    }else if(id>ultimoT2->ID){
            nuevo->sig=NULL;
            nuevo->ant=ultimoT2;
            ultimoT2->sig=nuevo;
            ultimoT2=nuevo;

    }else{

            NodoT2 *aux=primeroT2;
            if(aux!=NULL){
                while(aux!=NULL){
                     if(aux->ID>id){
                        nuevo->sig=aux;
                        nuevo->ant=aux->ant;
                        aux->ant->sig=nuevo;
                        aux->ant=nuevo;
                     break;
                     }else{
                         cout<<"No se agrega Repetido..."<<endl;
                     }
                  aux=aux->sig;
                }
            }

        }

    }

///************Lista Circular Tipo 3 ********************************
void ListaMatrices::Agregar_Lista_Tipo3(int tipo, int id){
    NodoT3 *nuevo;
    nuevo=(NodoT3*)malloc(sizeof(struct NodoTipo3));
    nuevo->tipo=tipo;
    nuevo->ID=id;
    nuevo->sig=NULL;
    nuevo->ant=NULL;

    if(primeroT3==NULL){
       nuevo->sig=NULL;
       nuevo->ant=NULL;
       primeroT3=nuevo;
       ultimoT3=nuevo;

    }else if(id<primeroT3->ID){
            nuevo->ant=NULL;
            nuevo->sig=primeroT3;
            primeroT3->ant=nuevo;
            primeroT3=nuevo;

    }else if(id>ultimoT3->ID){
            nuevo->sig=NULL;
            nuevo->ant=ultimoT3;
            ultimoT3->sig=nuevo;
            ultimoT3=nuevo;

    }else{

            NodoT3 *aux=primeroT3;
            if(aux!=NULL){
                while(aux!=NULL){
                     if(aux->ID>id){
                        nuevo->sig=aux;
                        nuevo->ant=aux->ant;
                        aux->ant->sig=nuevo;
                        aux->ant=nuevo;
                     break;
                     }else{
                         cout<<"No se agrega Repetido..."<<endl;
                     }
                  aux=aux->sig;
                }
            }

        }

    }




///**********Graficar Lista Circular Tipo 1**************************
void ListaMatrices::Graficar_Lista_Tipo1(){

    FILE *gra;
    gra=fopen("ListaT1.dot","wt");
    fputs("digraph g {\n ",gra);
    fputs("node [\n" ,gra);
    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"darkslateblue\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("];\n",gra);

    if(primeroT1!=NULL){
    fputs("\n subgraph cluster_1 {\n",gra);
    fputs("node [style=filled];\n",gra);
    NodoT1 *aux=primeroT1;
    if(aux!=NULL){
        while(aux!=NULL){
            if(aux!=NULL){
            fputs("\"nodoT1",gra);
            fprintf(gra, "%d",aux->ID);
            fputs("\"[label=\"",gra);
            fprintf(gra, "%d",aux->ID);
            fputs("\",width =\"0.7\",fontcolor=black,shape=square,labelloc = b,",gra);
            if(aux->tipo==1){
                fputs("image=\"enemigo1.png\"",gra);
            }else if(aux->tipo==2){
                fputs("image=\"enemigo2.png\"",gra);
            }else{
                fputs("image=\"enemigo3.png\"",gra);
            }
            fputs(" ];\n",gra);
           }
         aux=aux->sig;
        }

        aux=primeroT1;
        while(aux!=NULL){
            if(aux->sig!=NULL){
                fputs("\"nodoT1",gra);
                fprintf(gra,"%d",aux->ID);
                fputs("\"-> \"nodoT1",gra);
                fprintf(gra,"%d",aux->sig->ID);
                fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);
           }
         aux=aux->sig;
        }
        fputs("\"nodoT1",gra);
        fprintf(gra,"%d",ultimoT1->ID);
        fputs("\"-> \"nodoT1",gra);
        fprintf(gra,"%d",primeroT1->ID);
        fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);

    }

    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"orange\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("label =\"Lista Tipo 1\"\n",gra);
    fputs("}\n",gra);


 }else{
     ///La lista esta Vacia...
        fputs("\n subgraph cluster_1 {\n",gra);
        fputs("node [style=filled];\n",gra);

        fputs("\"",gra);
        fputs("nodoD",gra);
        fputs("\"",gra);
        fputs("\n[ ",gra);
        fprintf(gra, "label=\" Lista Tipo 2" );
        fputs("\"];\n",gra);

        fputs("fontsize = \"10\"\n",gra);
        fputs("shape = \"Mrecord\"\n",gra);
        fputs("color=\"orange\"\n",gra);
        fputs("style =\"filled, bold\"\n",gra);
        fputs("label =\"Lista Tipo1\"\n",gra);
        fputs("}\n",gra);

  }
 fputs("}",gra);
 fclose(gra);
 system("dot -Tpng ListaT1.dot -o ListaT1.png");


}


///**********Graficar Lista Circular Tipo 2**************************
void ListaMatrices::Graficar_Lista_Tipo2(){

    FILE *gra;
    gra=fopen("ListaT2.dot","wt");
    fputs("digraph g {\n ",gra);
    fputs("node [\n" ,gra);
    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"darkslateblue\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("];\n",gra);

    if(primeroT2!=NULL){
    fputs("\n subgraph cluster_1 {\n",gra);
    fputs("node [style=filled];\n",gra);
    NodoT2 *aux=primeroT2;
    if(aux!=NULL){
        while(aux!=NULL){
            if(aux!=NULL){
            fputs("\"nodoT2",gra);
            fprintf(gra, "%d",aux->ID);
            fputs("\"[label=\"",gra);
            fputs("ID: ",gra);
            fprintf(gra, "%d",aux->ID);
            fputs("\",width =\"0.7\",fontcolor=black,shape=square,labelloc = b,",gra);
            if(aux->tipo==1){
                fputs("image=\"enemigo1.png\"",gra);
            }else if(aux->tipo==2){
                fputs("image=\"enemigo2.png\"",gra);
            }else{
                fputs("image=\"enemigo3.png\"",gra);
            }
            fputs(" ];\n",gra);
           }
         aux=aux->sig;
        }

        aux=primeroT2;
        while(aux!=NULL){
            if(aux->sig!=NULL){
                fputs("\"nodoT2",gra);
                fprintf(gra,"%d",aux->ID);
                fputs("\"-> \"nodoT2",gra);
                fprintf(gra,"%d",aux->sig->ID);
                fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);
           }
         aux=aux->sig;
        }
        fputs("\"nodoT2",gra);
        fprintf(gra,"%d",ultimoT2->ID);
        fputs("\"-> \"nodoT2",gra);
        fprintf(gra,"%d",primeroT2->ID);
        fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);

    }

    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"orange\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("label =\"Lista Tipo 2\"\n",gra);
    fputs("}\n",gra);



 }else{
     ///La lista esta Vacia...
        fputs("\n subgraph cluster_1 {\n",gra);
        fputs("node [style=filled];\n",gra);

        fputs("\"",gra);
        fputs("nodoD",gra);
        fputs("\"",gra);
        fputs("\n[ ",gra);
        fprintf(gra, "label=\" Lista Tipo 2" );
        fputs("\"];\n",gra);

        fputs("fontsize = \"10\"\n",gra);
        fputs("shape = \"Mrecord\"\n",gra);
        fputs("color=\"orange\"\n",gra);
        fputs("style =\"filled, bold\"\n",gra);
        fputs("label =\"Lista Tipo2\"\n",gra);
        fputs("}\n",gra);

  }
 fputs("}",gra);
 fclose(gra);
 system("dot -Tpng ListaT2.dot -o ListaT2.png");


}

///**********Graficar Lista Circular Tipo 3**************************
void ListaMatrices::Graficar_Lista_Tipo3(){

    FILE *gra;
    gra=fopen("ListaT3.dot","wt");
    fputs("digraph g {\n ",gra);
    fputs("node [\n" ,gra);
    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"darkslateblue\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("];\n",gra);

    if(primeroT3!=NULL){
    fputs("\n subgraph cluster_1 {\n",gra);
    fputs("node [style=filled];\n",gra);
    NodoT3 *aux=primeroT3;
    if(aux!=NULL){
        while(aux!=NULL){
            if(aux!=NULL){
            fputs("\"nodoT3",gra);
            fprintf(gra, "%d",aux->ID);
            fputs("\"[label=\"",gra);
            fputs("ID: ",gra);
            fprintf(gra, "%d",aux->ID);
            fputs("\",width =\"0.7\",fontcolor=black,shape=square,labelloc = b,",gra);
            if(aux->tipo==1){
                fputs("image=\"enemigo1.png\"",gra);
            }else if(aux->tipo==2){
                fputs("image=\"enemigo2.png\"",gra);
            }else{
                fputs("image=\"enemigo3.png\"",gra);
            }
            fputs(" ];\n",gra);
           }
         aux=aux->sig;
        }

        aux=primeroT3;
        while(aux!=NULL){
            if(aux->sig!=NULL){
                fputs("\"nodoT3",gra);
                fprintf(gra,"%d",aux->ID);
                fputs("\"-> \"nodoT3",gra);
                fprintf(gra,"%d",aux->sig->ID);
                fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);
           }
         aux=aux->sig;
        }
        fputs("\"nodoT3",gra);
        fprintf(gra,"%d",ultimoT3->ID);
        fputs("\"-> \"nodoT3",gra);
        fprintf(gra,"%d",primeroT3->ID);
        fputs( "\"[dir=both,color=\"blue:black\"];\n",gra);

    }

    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"orange\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("label =\"Lista Tipo 3\"\n",gra);
    fputs("}\n",gra);


 }else{
     ///La lista esta Vacia...
        fputs("\n subgraph cluster_1 {\n",gra);
        fputs("node [style=filled];\n",gra);

        fputs("\"",gra);
        fputs("nodoD",gra);
        fputs("\"",gra);
        fputs("\n[ ",gra);
        fprintf(gra, "label=\" Lista Tipo 3" );
        fputs("\"];\n",gra);

        fputs("fontsize = \"10\"\n",gra);
        fputs("shape = \"Mrecord\"\n",gra);
        fputs("color=\"orange\"\n",gra);
        fputs("style =\"filled, bold\"\n",gra);
        fputs("label =\"Lista Tipo3\"\n",gra);
        fputs("}\n",gra);

  }
 fputs("}",gra);
 fclose(gra);
 system("dot -Tpng ListaT3.dot -o ListaT3.png");


}

///*********Arbol ABB de Usuario.................................................................................

///************BUSCAR SI EL NODO YA EXISTE EN EL ARBOL ABB*******
NodoABB *ListaMatrices::buscar(char *usuario){
    return buscar(this->raiz, usuario);
}

NodoABB *ListaMatrices::buscar(NodoABB *actual, char *usuario){
    if(actual==NULL){
        return NULL;
    }

    int comparacion = strcmp(usuario, actual->Usuario);
    if(comparacion==0){
        return actual;
    }else{
        return buscar(comparacion <0 ? actual->izq : actual->der, usuario);
    }
}



///***********INSERTAR UN NUEVO NODO EL EL ARBOL ABB***************
void ListaMatrices::Insertar(char *usuario, int nivel, int tiempo, int puntaje){
    nodoABB *nuevo;
    nuevo=(nodoABB*)malloc(sizeof(struct NodoABB));
    nuevo->Usuario=usuario;
    nuevo->Nivel=nivel;
    nuevo->Tiempo=tiempo;
    nuevo->Puntaje=puntaje;
    nuevo->izq=NULL;
    nuevo->der=NULL;
    nuevo->contador=correlativo++;


    if(raiz==NULL){
        raiz=nuevo;
    }else{
        nodoABB *actual=raiz;
        if(buscar(usuario)==NULL){
                while(true){
                        if(strcmp(usuario,actual->Usuario)<0){
                            if(actual->izq==NULL){
                                actual->izq=nuevo;
                                return;
                            }else{
                                actual=actual->izq;
                            }

                    }else{
                            if(actual->der==NULL){
                                actual->der=nuevo;
                                return;
                            }else{
                                actual=actual->der;
                            }
                    }
                }//FIN WHILE
        }
        return;
    }

}

///********METODO PARA OBTENER EL NODO REEMPLAZO****************
NodoABB *ListaMatrices::Obtener_Reemplazo(NodoABB *reemp){
    nodoABB *reemplazarPadre=reemp;
    nodoABB *reemplazo=reemp;
    nodoABB *auxiliar=reemp->der;
    while(auxiliar!=NULL){
        reemplazarPadre=reemplazo;
        reemplazo=auxiliar;
        auxiliar=auxiliar->izq;
    }
    if(reemplazo!=reemp->der){
        reemplazarPadre->izq=reemplazo->der;
        reemplazo->der=reemp->der;
    }
    cout<<"El Nodo Reemplazo es "<<reemplazo->Usuario<<endl;
    return reemplazo;
}

///*********GRAFICAR ARBOL ABB***********************************
void ListaMatrices::Graficar_ABB(){
    grab=fopen("ArbolABB.dot","wt");
    fputs("digraph grafica{\n ",grab);
    fputs("rankdir=TB;\n",grab);
    fputs("node [\n" ,grab);
    fputs("shape =record, ",grab);
    fputs("fillcolor=seashell2, ",grab);
    fputs("style =filled, ",grab);
    fputs("];\n",grab);

    cout << endl;
    cout << "*****Graficar Arbol ABB*****" << endl;

     Graficar_ABB(raiz);

    fputs("}",grab);
    fclose(grab);
    system("dot -Tpng ArbolABB.dot -o ArbolABB.png");
    cout << "*****Fin Graficar InOrden*****" << endl;

}

void ListaMatrices::Graficar_ABB(NodoABB *actual){
    if(actual != NULL)
    {

        if(actual->izq ==NULL && actual->der==NULL){
            fputs("\"",grab);
            fputs("nodo",grab);
            fprintf(grab,"%d",actual->contador);
            fputs("\"",grab);
            fputs("\n[ ",grab);
            fprintf(grab, "label=\" " );
            fprintf(grab, "%s",actual->Usuario);
            fputs(" &#92;n ",grab);
            fputs("Nivel: ",grab);
            fprintf(grab, "%d",actual->Nivel);
            fputs(" &#92;n ",grab);
            fputs("Tiempo: ",grab);
            fprintf(grab, "%d",actual->Tiempo);
            fputs(" &#92;n ",grab);
            fputs("Puntaje: ",grab);
            fprintf(grab, "%d",actual->Puntaje);
            fputs("\"];\n",grab);

        }else{
            fputs("\"",grab);
            fputs("nodo",grab);
            fprintf(grab,"%d",actual->contador);
            fputs("\"",grab);
            fputs("\n[ ",grab);
            fprintf(grab, "label=\"<C0>| " );
            fprintf(grab, "%s",actual->Usuario);
            fputs(" &#92;n ",grab);
            fputs("Nivel: ",grab);
            fprintf(grab, "%d",actual->Nivel);
            fputs(" &#92;n ",grab);
            fputs("Tiempo: ",grab);
            fprintf(grab, "%d",actual->Tiempo);
            fputs(" &#92;n ",grab);
            fputs("Puntaje: ",grab);
            fprintf(grab, "%d",actual->Puntaje);
            fputs("|<C1>\"];\n",grab);

        }
        if(actual->izq!=NULL){
            Graficar_ABB(actual->izq);
            fputs("nodo",grab);
            fprintf(grab,"%d",actual->contador);
            fputs(":C0->nodo",grab);
            fprintf(grab,"%d",actual->izq->contador);
            fputs("\n",grab);

        }
        if(actual->der!=NULL){
            Graficar_ABB(actual->der);
            fputs("nodo",grab);
            fprintf(grab,"%d",actual->contador);
            fputs(":C1->nodo",grab);
            fprintf(grab,"%d",actual->der->contador);
            fputs("\n",grab);
        }


    }


}


////Eliminacion en la Matriz desde el Cliente.............................................
QString ListaMatrices::Eliminacion(int y, int x){
    QString texto="";
    QString texto1="";
    int acierto=0;
    int Nivel=hilo1->Nivel;
    NodoD *aux=primeroD;
    if(aux!=NULL){

        while(aux!=NULL){
            if(aux->Nivel==Nivel){

                NodoF *auxF=aux->PrmeroAbajo;
                if(auxF!=NULL){

                    while(auxF!=NULL){
                        if(auxF->Fila==y){
                            NodoM *auxM=auxF->primeroM;
                            if(auxM!=NULL){
                                while(auxM!=NULL){
                                    if(auxM->Columna==x){
                                        acierto=1;
                                        ///El nodo existe, Eliminar...
                                        if(auxM->golpes>1){
                                           auxM->golpes--;
                                           texto1= QString("Mensaje de 200915305: ATAQUE a enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila);
                                           texto.append(texto1);
                                        }else{
                                            if(auxM->enemigo==1){
                                                Agregar_Lista_Tipo1(1,auxM->ID);
                                                Eliminar_En_Matriz(y,x);
                                                Graficar_Lista_Tipo1();
                                                Graficar_Lista_Tipo2();
                                                Graficar_Lista_Tipo3();
                                                Grafica_Matriz_Por_Niveles();

                                                hilo1->puntaje+=10;
                                                texto1= QString("Mensaje de 200915305: ELIMINACION de enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila);
                                                texto.append(texto1);
                                                Agregar_Enemigos_Eliminados(auxM->enemigo,auxM->ID,auxM->Fila,auxM->Columna);
                                            }else if(auxM->enemigo==2){
                                                Agregar_Lista_Tipo2(2,auxM->ID);
                                                Eliminar_En_Matriz(y,x);
                                                Graficar_Lista_Tipo1();
                                                Graficar_Lista_Tipo2();
                                                Graficar_Lista_Tipo3();
                                                Grafica_Matriz_Por_Niveles();
                                                hilo1->puntaje+=20;
                                                texto1= QString("Mensaje de 200915305: ELIMINACION de enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila);
                                                texto.append(texto1);
                                                Agregar_Enemigos_Eliminados(auxM->enemigo,auxM->ID,auxM->Fila,auxM->Columna);
                                            }else if(auxM->enemigo==3){
                                                Agregar_Lista_Tipo3(3,auxM->ID);
                                                Eliminar_En_Matriz(auxM->Fila,auxM->Columna);
                                                Graficar_Lista_Tipo1();
                                                Graficar_Lista_Tipo2();
                                                Graficar_Lista_Tipo3();
                                                Grafica_Matriz_Por_Niveles();
                                                hilo1->puntaje+=40;
                                                texto1= QString("Mensaje de 200915305: ELIMINACION de enemigo ID:%1 a la posicion X:%2 Y:%3\n").arg(auxM->ID).arg(auxM->Columna).arg(auxM->Fila);
                                                texto.append(texto1);
                                                Agregar_Enemigos_Eliminados(auxM->enemigo,auxM->ID,auxM->Fila,auxM->Columna);
                                            }

                                        }

                                     break;
                                    }
                                 auxM=auxM->izq;
                                }
                            }
                         break;
                        }
                     auxF=auxF->Abajo;
                    }
                }

             break;
            }
         aux=aux->sig;
        }
    }

    if(acierto==1){
         return texto;
    }else{
        texto1= QString("Mensaje de 200915305: ATAQUE FALLIDO en posicion X:%1 Y:%2\n").arg(x).arg(y);
        texto.append(texto1);
        hilo1->Ataques_Fallidos++;
        ///Agregar
        if(hilo1->Ataques_Fallidos==5){
            NodoE *auxE =primeroE;
            if(auxE!=NULL){
                int tipo=auxE->enemigo;
                int golpes=1;
                if(tipo==1){
                    golpes=1;
                }else if(tipo==2){
                    golpes=3;
                }else if(tipo==3){
                    golpes=5;
                }

                cout<<"ATAQUES FALLIDOS..."<<hilo1->Ataques_Fallidos<<endl;
                Agregar_En_Matriz(auxE->enemigo,auxE->ID,auxE->Fila,auxE->Columna,golpes);
                texto1= QString("Mensaje de 200915305: ERROR-404 enemigo resucitado en  ID:%1 a la posicion X:%2 Y:%3\n").arg(auxE->ID).arg(auxE->Columna).arg(auxE->Fila);
                texto.append(texto1);
                Grafica_Matriz_Por_Niveles();
                if(hilo1->puntaje>100){
                    hilo1->puntaje-=100;
                }else{
                    hilo1->puntaje=0;
                }
                  primeroE=primeroE->sig;
                  hilo1->Ataques_Fallidos=0;
            }else{
                texto1= QString("Mensaje de 200915305: NO HAY ENEMIGOS PARA RESUCITAR\n");
                texto.append(texto1);
                return texto;
            }
        }

      return texto;
    }


}


///Puntajes..........................................................
int ListaMatrices::Puntajes(){
    int puntos=hilo1->puntaje;
    return puntos;
}

int ListaMatrices::Nivel_Actual(){

   int nivel = hilo1->Nivel;
   return nivel;
}

int ListaMatrices::Dimension_Actual(){
    int dim=hilo1->DimensionT;
    return dim;
}

int ListaMatrices::Fallidos(){
    int fallos=hilo1->Ataques_Fallidos;
    if(fallos>5){
        hilo1->Ataques_Fallidos=0;
    }
    return fallos;
}

QString ListaMatrices::Nivel_Completado(){
    QString texto="";
    QString texto1="";

    if(hilo1->Nivel==1 && hilo1->puntaje>=80){
        texto1= QString("Mensaje de 200915305: !!!FELICIDADES!!! Completaste el Nivel 1\n");
        texto.append(texto1);
        texto1= QString("Mensaje de 200915305: ***SE DESBLOQUE EL NIVEL SUPERIOR***\n");
        texto.append(texto1);
        hilo1->terminar=1;
        hilo1->Nivel_Terminado=1;
        Subir_Nivel();

    }else if(hilo1->Nivel==2 && hilo1->puntaje>=100){
        texto1= QString("Mensaje de 200915305: !!!FELICIDADES!!! Completaste el Nivel 2\n");
        texto.append(texto1);
        texto1= QString("Mensaje de 200915305: ***SE DESBLOQUE EL NIVEL SUPERIOR***\n");
        texto.append(texto1);
        hilo1->terminar=1;
        hilo1->Nivel_Terminado=1;
        Subir_Nivel();

    }else if(hilo1->Nivel==3 && hilo1->puntaje>=120){
        texto1= QString("Mensaje de 200915305: !!!FELICIDADES!!! Completaste el Nivel 3\n");
        texto.append(texto1);
        texto1= QString("Mensaje de 200915305: ***SE DESBLOQUE EL NIVEL SUPERIOR***\n");
        texto.append(texto1);
        hilo1->terminar=1;
        hilo1->Nivel_Terminado=1;
        Subir_Nivel();

    }else if(hilo1->Nivel==4 && hilo1->puntaje>=140){
        texto1= QString("Mensaje de 200915305: !!!FELICIDADES!!! Completaste el Nivel 4\n");
        texto.append(texto1);
        texto1= QString("Mensaje de 200915305: ***SE DESBLOQUE EL NIVEL SUPERIOR***\n");
        texto.append(texto1);
        hilo1->terminar=1;
        hilo1->Nivel_Terminado=1;
        Subir_Nivel();

    }else if(hilo1->Nivel==5 && hilo1->puntaje>=160){
        texto1= QString("Mensaje de 200915305: !!!FELICIDADES!!! Completaste el Nivel 5\n");
        texto.append(texto1);
        texto1= QString("Mensaje de 200915305: ***SE DESBLOQUE EL NIVEL SUPERIOR***\n");
        texto.append(texto1);
        hilo1->terminar=1;
        hilo1->Nivel_Terminado=1;
        Subir_Nivel();

    }else if(hilo1->Nivel==6 && hilo1->puntaje>=180){
        texto1= QString("Mensaje de 200915305: !!!FELICIDADES!!! Completaste el Nivel 6\n");
        texto.append(texto1);
        texto1= QString("Mensaje de 200915305: ***SE DESBLOQUE EL NIVEL SUPERIOR***\n");
        texto.append(texto1);
        hilo1->terminar=1;
        hilo1->Nivel_Terminado=1;
        Subir_Nivel();

    }


 return texto;
}

void ListaMatrices::Subir_Nivel(){
    int arriba = hilo1->Nivel;
    arriba++;
    NodoD *aux=primeroD;
    if(aux!=NULL){
        while(aux!=NULL){
            if(aux->Nivel==arriba){
                aux->Activo=1;
             break;
            }else{
                aux->Activo=0;
            }
         aux=aux->sig;
        }
    }

}


int ListaMatrices::Nivel_Over(int over){

    hilo1->Nivel_Perdido=over;
    return over;
}

void ListaMatrices::Agregar_Datos_Lista_Modificada(char *usuario){
   Agregar_Lista_Modificada(usuario,hilo1->puntaje,hilo1->Nivel,hilo1->Tiempo);
}

int ListaMatrices::Nivel_Open(int open){
    hilo1->Nivel_Terminado=open;
    return open;
}

int ListaMatrices::Nivel_Perdido(){
    return hilo1->Nivel_Perdido;
}

int ListaMatrices::Nivel_Gandado(){
    return hilo1->Nivel_Terminado;
}

void ListaMatrices::On_OFF(int on){
    hilo1->terminar=on;

}

int ListaMatrices::Terminar(){
    return hilo1->terminar;
}

int ListaMatrices::Tiempo(){
    return hilo1->Tiempo;
}

int ListaMatrices::Tiempor(){
    if(hilo1->Tiempo>0){
    hilo1->Tiempo--;
    }
    return hilo1->Tiempo;
}



int ListaMatrices::Cambio_de_Nivel(int cambio){
    if(cambio==1){//Arriba....
        int arriba=hilo1->Nivel+1;
        NodoD *aux=primeroD;
        if(aux!=NULL){
            while (aux!=NULL) {
                if(aux->Nivel==arriba && aux->Activo==1){
                     hilo1->Nivel++;
                 break;
                }
             aux=aux->sig;
            }
        }


    }else if(cambio==2){//Abajo...
        hilo1->Nivel--;
    }else if(cambio==3){//Jugar...
        hilo1->puntaje=0;
        hilo1->Ataques_Fallidos=0;
        hilo1->Nivel_Perdido=0;
        hilo1->Nivel_Terminado=0;
        hilo1->ID_enemgo=1;
        primeroP=NULL;
        ultimoP=NULL;
        primeroE=NULL;
        ultimoE=NULL;
        primeroT1=NULL;
        primeroT2=NULL;
        primeroT3=NULL;
        ultimoT1=NULL;
        ultimoT2=NULL;
        ultimoT3=NULL;

        NodoD *aux=primeroD;
        if(aux!=NULL){
            while(aux!=NULL){

                    aux->PrimeroIzquierda=NULL;
                    aux->UltimoIzquierda=NULL;
                    aux->PrmeroAbajo=NULL;
                    aux->UltimoAbajo=NULL;

            aux=aux->sig;
            }
        }

        if(hilo1->Nivel==1 || hilo1->Nivel==2){
            hilo1->Tiempo=60;

        }else if(hilo1->Nivel==3 || hilo1->Nivel==4){
            hilo1->Tiempo=90;

        }else if(hilo1->Nivel==5 || hilo1->Nivel==6){
            hilo1->Tiempo=120;

        }else if(hilo1->Nivel>=7){
             hilo1->Tiempo=180;
        }

        cout<<"Puntaje:"<<hilo1->puntaje<<endl;
        cout<<"ID:"<<hilo1->ID_enemgo<<endl;
        if(primeroP==NULL && ultimoP==NULL){
            cout<<"PriemorP null"<<endl;
        }
        if(primeroE==NULL && ultimoE==NULL){
            cout<<"primeroP null:"<<endl;
        }

    }


}

///*************AGREGAR LISTA MODIFICADA************************************
void ListaMatrices::Agregar_Lista_Modificada(char *usuario, int puntos, int nivel, int tiempo){
    NodoLM *nuevo;
    nuevo=(NodoLM*)malloc(sizeof(struct NodoLista_Modificada));
    nuevo->Usuario=usuario;
    nuevo->Puntaje=puntos;
    nuevo->Nivel=nivel;
    nuevo->Tiempo=tiempo;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    if(primeroLM==NULL){
        nuevo->der=NULL;
        nuevo->izq=NULL;
        primeroLM=nuevo;
        ultimoLM=nuevo;

    }else{
       nuevo->der=NULL;
       nuevo->izq=primeroLM;
       primeroLM->der=nuevo;
       primeroLM=nuevo;
    }
}

void ListaMatrices::Graficar_Lista_Modificada(){

    FILE *gra;
    gra=fopen("ListaM.dot","wt");
    fputs("digraph g {\n ",gra);
   fputs("rankdir= \"LR\"",gra);
    fputs("node [\n" ,gra);
    fputs("fontsize = \"10\"\n",gra);

    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"darkslateblue\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("];\n",gra);

    if(primeroLM!=NULL){
    fputs("\n subgraph cluster_1 {\n",gra);
    fputs("node [style=filled];\n",gra);
    NodoLM *aux=ultimoLM;
    if(aux!=NULL){
        int a=1;
        while(aux!=NULL){
            if(aux!=NULL){
            fputs("\"nodoM",gra);
            fprintf(gra, "%d",a);
            fputs("\"[label=\"",gra);
            fputs("Usuario: ",gra);
            fprintf(gra, "%s",aux->Usuario);
            fputs(" &#92;n ",gra);
            fputs("Nivel: ",gra);
            fprintf(gra, "%d",aux->Nivel);
            fputs(" &#92;n ",gra);
            fputs("Puntos ",gra);
            fprintf(gra, "%d",aux->Puntaje);
            fputs(" &#92;n ",gra);
            fputs("Tiempo: ",gra);
            fprintf(gra, "%d",aux->Tiempo);
            fputs("\",width =\"0.7\",fontcolor=black,shape=square,labelloc = b",gra);
            fputs(" ];\n",gra);
           }
            a++;
         aux=aux->der;
        }

        aux=ultimoLM;
        int b=1;
        int c=b+1;
        while(aux!=NULL){
            if(aux!=primeroLM){
                fputs("\"nodoM",gra);
                fprintf(gra,"%d",b);
                fputs("\"-> \"nodoM",gra);
                fprintf(gra,"%d",c);
                fputs( "\"[dir=back];\n",gra);
           }
            b++;
            c++;
         aux=aux->der;
        }


    }

    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"orange\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("label =\"Lista Modificada\"\n",gra);
    fputs("}\n",gra);


 }else{
     ///La lista esta Vacia...
        fputs("\n subgraph cluster_1 {\n",gra);
        fputs("node [style=filled];\n",gra);

        fputs("\"",gra);
        fputs("nodoD",gra);
        fputs("\"",gra);
        fputs("\n[ ",gra);
        fprintf(gra, "label=\" Lista Modificada" );
        fputs("\"];\n",gra);

        fputs("fontsize = \"10\"\n",gra);
        fputs("shape = \"Mrecord\"\n",gra);
        fputs("color=\"orange\"\n",gra);
        fputs("style =\"filled, bold\"\n",gra);
        fputs("label =\"Lista Modificada\"\n",gra);
        fputs("}\n",gra);

  }
 fputs("}",gra);
 fclose(gra);
 system("dot -Tpng ListaM.dot -o ListaM.png");
}


////***************************+ARBOL ABB DE RESULTADOS..........................................................
NodoABB2 *ListaMatrices::buscar2(char *usuario){
    return buscar2(this->raiz2, usuario);
}

NodoABB2 *ListaMatrices::buscar2(NodoABB2 *actual, char *usuario){
    if(actual==NULL){
        return NULL;
    }

    int comparacion = strcmp(usuario, actual->Usuario);
    if(comparacion==0){
        return actual;
    }else{
        return buscar2(comparacion <0 ? actual->izq : actual->der, usuario);
    }
}



///***********INSERTAR UN NUEVO NODO EL EL ARBOL ABB***************
void ListaMatrices::Insertar2(char *usuario, int nivel, int tiempo, int puntaje){
    nodoABB2 *nuevo2;
    nuevo2=(nodoABB2*)malloc(sizeof(struct NodoABB2));
    nuevo2->Usuario=usuario;
    nuevo2->Nivel=nivel;
    nuevo2->Tiempo=tiempo;
    nuevo2->Puntaje=puntaje;
    nuevo2->izq=NULL;
    nuevo2->der=NULL;
    nuevo2->contador2=correlativo2++;


    if(raiz2==NULL){
        raiz2=nuevo2;
    }else{
        nodoABB2 *actual=raiz2;
       // if(buscar2(usuario)==NULL){
                while(true){
                        if(puntaje<actual->Puntaje){
                            if(actual->izq==NULL){
                                actual->izq=nuevo2;
                                return;
                            }else{
                                actual=actual->izq;
                            }

                    }else{
                            if(actual->der==NULL){
                                actual->der=nuevo2;
                                return;
                            }else{
                                actual=actual->der;
                            }
                    }
                }//FIN WHILE
       // }
        return;
    }

}

///********METODO PARA OBTENER EL NODO REEMPLAZO****************
NodoABB2 *ListaMatrices::Obtener_Reemplazo2(NodoABB2 *reemp){
    nodoABB2 *reemplazarPadre=reemp;
    nodoABB2 *reemplazo=reemp;
    nodoABB2 *auxiliar=reemp->der;
    while(auxiliar!=NULL){
        reemplazarPadre=reemplazo;
        reemplazo=auxiliar;
        auxiliar=auxiliar->izq;
    }
    if(reemplazo!=reemp->der){
        reemplazarPadre->izq=reemplazo->der;
        reemplazo->der=reemp->der;
    }
    cout<<"El Nodo Reemplazo es "<<reemplazo->Usuario<<endl;
    return reemplazo;
}

///*********GRAFICAR ARBOL ABB***********************************
void ListaMatrices::Graficar_ABB2(){
    grab2=fopen("ArbolABB2.dot","wt");
    fputs("digraph grafica{\n ",grab2);
    fputs("rankdir=TB;\n",grab2);
    fputs("node [\n" ,grab2);
    fputs("shape =record, ",grab2);
    fputs("fillcolor=seashell2, ",grab2);
    fputs("style =filled, ",grab2);
    fputs("];\n",grab2);

    cout << endl;
    cout << "*****Graficar Arbol ABB*****" << endl;

     Graficar_ABB2(raiz2);

    fputs("}",grab2);
    fclose(grab2);
    system("dot -Tpng ArbolABB2.dot -o ArbolABB2.png");
    cout << "*****Fin Graficar InOrden*****" << endl;

}

void ListaMatrices::Graficar_ABB2(NodoABB2 *actual){
    if(actual != NULL)
    {

        if(actual->izq ==NULL && actual->der==NULL){
            fputs("\"",grab2);
            fputs("nodo",grab2);
            fprintf(grab2,"%d",actual->contador2);
            fputs("\"",grab2);
            fputs("\n[ ",grab2);
            fprintf(grab2, "label=\" " );
            fprintf(grab2, "%s",actual->Usuario);
            fputs(" &#92;n ",grab2);
            fputs("Nivel: ",grab2);
            fprintf(grab2, "%d",actual->Nivel);
            fputs(" &#92;n ",grab2);
            fputs("Tiempo: ",grab2);
            fprintf(grab2, "%d",actual->Tiempo);
            fputs(" &#92;n ",grab2);
            fputs("Puntaje: ",grab2);
            fprintf(grab2, "%d",actual->Puntaje);
            fputs("\"];\n",grab2);

        }else{
            fputs("\"",grab2);
            fputs("nodo",grab2);
            fprintf(grab2,"%d",actual->contador2);
            fputs("\"",grab2);
            fputs("\n[ ",grab2);
            fprintf(grab2, "label=\"<C0>| " );
            fprintf(grab2, "%s",actual->Usuario);
            fputs(" &#92;n ",grab2);
            fputs("Nivel: ",grab2);
            fprintf(grab2, "%d",actual->Nivel);
            fputs(" &#92;n ",grab2);
            fputs("Tiempo: ",grab2);
            fprintf(grab2, "%d",actual->Tiempo);
            fputs(" &#92;n ",grab2);
            fputs("Puntaje: ",grab2);
            fprintf(grab2, "%d",actual->Puntaje);
            fputs("|<C1>\"];\n",grab2);

        }
        if(actual->izq!=NULL){
            Graficar_ABB2(actual->izq);
            fputs("nodo",grab2);
            fprintf(grab2,"%d",actual->contador2);
            fputs(":C0->nodo",grab2);
            fprintf(grab2,"%d",actual->izq->contador2);
            fputs("\n",grab2);

        }
        if(actual->der!=NULL){
            Graficar_ABB2(actual->der);
            fputs("nodo",grab2);
            fprintf(grab2,"%d",actual->contador2);
            fputs(":C1->nodo",grab2);
            fprintf(grab2,"%d",actual->der->contador2);
            fputs("\n",grab2);
        }


    }


}


///**************************Recorrer Lista Modificada**********************************************+
void ListaMatrices::Recorrer_Lista_Modificada(char *usuario){
    NodoLM *aux=ultimoLM;
    if(aux!=NULL){
        while(aux!=NULL){
            if(strcmp(usuario,aux->Usuario)==0){
                Insertar2(aux->Usuario,aux->Nivel,aux->Tiempo,aux->Puntaje);
            }
         aux=aux->der;
        }
    }
    Graficar_ABB2();
    raiz2=NULL;
}



