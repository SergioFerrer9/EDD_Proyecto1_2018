
package Proyecto1;

public class NodoFila {
    
    int Fila;
    NodoFila arriba;
    NodoFila abajo;
    NodoMatriz primeroM;
    NodoMatriz ultimoM;
    
    public NodoFila(int fila){
        this.Fila=fila;
        this.arriba=null;
        this.abajo=null;
        this.primeroM=null;
        this.ultimoM=null;
    
    }
}
