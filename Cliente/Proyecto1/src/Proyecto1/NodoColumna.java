
package Proyecto1;

public class NodoColumna {
    int columna;
    NodoColumna izq;
    NodoColumna der;
    NodoMatriz primeroM;
    NodoMatriz ultimoM;
    
    public NodoColumna(int columna){
        this.columna=columna;
        this.izq=null;
        this.der=null;
        this.primeroM=null;
        this.ultimoM=null;
    
    }
}
