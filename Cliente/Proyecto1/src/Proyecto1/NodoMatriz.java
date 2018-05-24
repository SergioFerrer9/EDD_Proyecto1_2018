
package Proyecto1;


public class NodoMatriz {
    int Fila;
    int Columna;
    int ID;
    NodoMatriz izq;
    NodoMatriz der;
    NodoMatriz arriba;
    NodoMatriz abajo;
    public NodoMatriz(int fila, int columna, int id){
        this.Fila=fila;
        this.Columna=columna;
        this.ID=id;
        this.izq=null;
        this.der=null;
        this.arriba=null;
        this.abajo=null;
    }
    
    
}

