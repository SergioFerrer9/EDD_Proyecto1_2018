
package Proyecto1;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class Matriz {
    NodoFila primero_abajo;
    NodoFila ultimo_abajo;
    NodoColumna primero_izquierda;
    NodoColumna ultimo_izquierda;
    
    
    public void Insertar_Matriz(int fila, int columna, int id){
        NodoMatriz nuevo = new NodoMatriz(fila, columna, id);
        
        Agregar_Fila(fila);
        Agregar_Columna(columna);
        
        ///Insertar en Matriz enlazado a Columnas.....
        NodoColumna actualC=primero_izquierda;
        
        if(actualC!=null){
            
            while(actualC!=null){
                if(actualC.columna==columna){
                    if(actualC.primeroM==null){
                        
                        nuevo.abajo=null;
                        nuevo.arriba=null;
                        actualC.primeroM=nuevo;
                        actualC.ultimoM=nuevo;
                    }else{
                        if(fila<actualC.primeroM.Fila){
                            
                            nuevo.arriba=null;
                            nuevo.abajo=actualC.primeroM;
                            actualC.primeroM.arriba=nuevo;
                            actualC.primeroM=nuevo;
                            
                        }else if(fila>actualC.ultimoM.Fila){
                            nuevo.abajo=null;
                            nuevo.arriba=actualC.ultimoM;
                            actualC.ultimoM.abajo=nuevo;
                            actualC.ultimoM=nuevo;
                            
                        }else{
                            NodoMatriz actualM=actualC.primeroM;
                            
                            if(actualM!=null){
                                while(actualM!=null){
                                    if(actualM.Fila>fila){
                                        
                                        nuevo.abajo=actualM;
                                        nuevo.arriba=actualM.arriba;
                                        actualM.arriba.abajo=nuevo;
                                        actualM.arriba=nuevo;
                                        break;
                                    }else if(actualM.Fila==fila){
                                        break;
                                    }
                                 actualM=actualM.abajo;   
                                }
                            }
                            
                        }
                        
                    }
                break;    
                }
             actualC=actualC.izq;   
            }
        }
        
        ///Insertar en Matriz enlazado a Filas.....
        
        NodoFila actualF = primero_abajo;
        if(actualF!=null){
            while(actualF!=null){
                if(actualF.Fila==fila){
                        if(actualF.primeroM==null){
                            
                            nuevo.izq=null;
                            nuevo.der=null;
                            actualF.primeroM=nuevo;
                            actualF.ultimoM=nuevo;
                            
                        }else{
                            if(columna<actualF.primeroM.Columna){
                                
                                nuevo.der=null;
                                nuevo.izq=actualF.primeroM;
                                actualF.primeroM.der=nuevo;
                                actualF.primeroM=nuevo;
                                
                            }else if(columna>actualF.ultimoM.Columna){
                                
                                nuevo.izq=null;
                                nuevo.der=actualF.ultimoM;
                                actualF.ultimoM.izq=nuevo;
                                actualF.ultimoM=nuevo;
                                
                            }else{
                                NodoMatriz actualM=actualF.primeroM;
                                if(actualM!=null){
                                    while(actualM!=null){
                                        if(actualM.Columna>columna){
                                            
                                            nuevo.izq=actualM;
                                            nuevo.der=actualM.der;
                                            actualM.der.izq=nuevo;
                                            actualM.der=nuevo;
                                            break;
                                        }else if(actualM.Columna==columna){
                                            break;
                                        }
                                     actualM=actualM.izq;   
                                    }
                                }
                            }
                        }
                 break;   
                }
             actualF=actualF.abajo;
            }
        }
    
    }
    
    public void Agregar_Fila(int fila){
        NodoFila nuevo = new NodoFila(fila);
        if(primero_abajo==null){
            nuevo.abajo=null;
            nuevo.arriba=null;
            primero_abajo=nuevo;
            ultimo_abajo=nuevo;
            nuevo.primeroM=null;
            
        }else{
            if(fila<primero_abajo.Fila){
                nuevo.arriba=null;
                nuevo.abajo=primero_abajo;
                primero_abajo.arriba=nuevo;
                primero_abajo=nuevo;
                nuevo.primeroM=null;
            
            }else if(fila>ultimo_abajo.Fila){
                nuevo.abajo=null;
                nuevo.arriba=ultimo_abajo;
                ultimo_abajo.abajo=nuevo;
                ultimo_abajo=nuevo;
                nuevo.primeroM=null;
               
            }else{
                NodoFila aux = primero_abajo;
                if(aux!=null){
                    while(aux!=null){
                        if(aux.Fila>fila){
                            nuevo.abajo=aux;
                            nuevo.arriba=aux.arriba;
                            aux.arriba.abajo=nuevo;
                            aux.arriba=nuevo;
                            nuevo.primeroM=null;
                            break;
                        }else if(aux.Fila==fila){
                            System.out.println("Ya existe la fila...");
                            break;
                        }
                     aux=aux.abajo;   
                    }
                }
                
            }
        }
    }
    
    public void Agregar_Columna(int columna){
        NodoColumna  nuevo = new NodoColumna(columna);
        
        if(primero_izquierda==null){
            nuevo.izq=null;
            nuevo.der=null;
            primero_izquierda=nuevo;
            ultimo_izquierda=nuevo;
            nuevo.primeroM=null;
            
            
        }else{
            if(columna<primero_izquierda.columna){
                nuevo.der=null;
                nuevo.izq=primero_izquierda;
                primero_izquierda.der=nuevo;
                primero_izquierda=nuevo;
                nuevo.primeroM=null;
                
            }else if(columna>ultimo_izquierda.columna){
                nuevo.izq=null;
                nuevo.der=ultimo_izquierda;
                ultimo_izquierda.izq=nuevo;
                ultimo_izquierda=nuevo;
                nuevo.primeroM=null;                
                
            }else{
                NodoColumna aux = primero_izquierda;
                if(aux!=null){
                    while(aux!=null){
                        if(aux.columna>columna){
                            nuevo.izq=aux;
                            nuevo.der=aux.der;
                            aux.der.izq=nuevo;
                            aux.der=nuevo;
                            nuevo.primeroM=null;
                            break;
                        }else if(aux.columna==columna){
                            System.out.println("Ya existe la Columna...");
                            break;
                        }
                     aux=aux.izq;
                    }
                }
            }
        }
        
    }
    
void Graficar_Matriz() throws IOException{
        int Nivel =1;
        PrintWriter pw = null;
        FileWriter fichero = new FileWriter("./Matriz_Ortogonal.dot");
        pw = new PrintWriter(fichero);
        pw.println("digraph g {");
        pw.println("node [");
        pw.println("fontsize = \"10\"");
        pw.println("shape = \"Mrecord\"");         
        pw.println("];\n");        
        pw.println("subgraph cluster_1 {");
        if(Nivel>0){
        ///Crear Nodo Raiz.........
        pw.print("\"nodoD"+Nivel);
        pw.print("\"[label=\"Nivel"+Nivel);
        pw.print("\",style=filled];\n");
        
        ///Crear Nodos de las cabeceras (Filas)...
        int aa=1;
        NodoFila auxF=primero_abajo;
            if(auxF!=null){
                while(auxF!=null){
                    pw.print("\"nodoF"+aa);
                    pw.println("\"[label=\"Fila"+auxF.Fila+"\",style=filled];");
                    aa++;
                    ///Crear los Nodos de las Matriz Fila x Fila.....
                    NodoMatriz auxM=auxF.primeroM;
                    if(auxM!=null){
                        while(auxM!=null){
                            pw.print("\"nodoM"+auxM.ID);
                            pw.println("\"[label=\""+auxM.Fila+" , "+auxM.Columna+"\",style=filled];");
                            auxM=auxM.izq;   
                        }
                        pw.println("\n");
                    }
                    
                    
                 auxF=auxF.abajo;
                }
            }
        
        ///Crear Nodos de las Cabeceras (Columnas)...
        aa=1;
        NodoColumna auxC=primero_izquierda;
        System.out.println("Texto");
        if(auxC!=null){
            System.out.println("Texto");
            while(auxC!=null){
                    pw.print("\"nodoC"+aa);
                    pw.println("\"[label=\"Columna"+auxC.columna+"\",style=filled];");
                    aa++;
             auxC=auxC.izq;     
            }
            pw.println("\n");
        }
        
        ///Crear los Rank....................................
        ///Rank de las Cabeceras Columnas....
        auxC=ultimo_izquierda;
        if(auxC!=null){
            pw.print("{rank = same;");
            aa=1;
            while(auxC!=null){
                    pw.print("\"nodoC"+aa+"\";");
                   
                    aa++;
             auxC=auxC.der;   
            }
            pw.println("\"nodoD"+Nivel+"\";}");
            
        }
        
        ///Rank de la Matriz por Filas...........................
        auxF=primero_abajo;
        if(auxF!=null){
            int a=1;
            while(auxF!=null){
                pw.print("{rank = same;");
                NodoMatriz auxM=auxF.ultimoM;
                if(auxM!=null){
                    while(auxM!=null){
                        if(auxM!=null){
                        pw.print("\"nodoM"+auxM.ID);
                        pw.print("\";");
                        }
                     auxM=auxM.der;   
                    }
                }
                
                pw.print("\"nodoF"+a);
                pw.println("\";}");
                a++;
             auxF=auxF.abajo;   
            }
        }
        
        ///Crear los Enlaces.................................
       auxC=primero_izquierda;
        if(auxC!=null){
            int b=1;
            int c=b+1;
            while(auxC!=null){
                if(auxC!=ultimo_izquierda){
                    pw.print("\"nodoC"+c);
                    pw.print("\"-> \"nodoC"+b);
                    pw.print("\"[dir=both,color=\"black:blue\"];\n");
                    
                        pw.print("\"nodoC"+b);
                        pw.print("\"-> \"nodoM"+auxC.primeroM.ID);
                        pw.print("\"[dir=both,color=\"black:blue\"];\n");
                
                        NodoMatriz auxM =auxC.primeroM;
                        if(auxM!=null){
                            while(auxM!=null){
                                if(auxM!=auxC.ultimoM){
                                    pw.print("\"nodoM"+auxM.abajo.ID);
                                    pw.print("\"-> \"nodoM"+auxM.ID);
                                    pw.print("\"[dir=both,color=\"black:blue\"];\n");
                                }
                            auxM=auxM.abajo;    
                            }
                        }
                
                b++;
                c++;
                
                }else{
                    pw.print("\"nodoC"+b);
                    pw.print("\"-> \"nodoM"+auxC.primeroM.ID);
                    pw.print("\"[dir=both,color=\"black:blue\"];\n");
                    
                    NodoMatriz auxM =auxC.primeroM;
                        if(auxM!=null){
                            while(auxM!=null){
                                if(auxM!=auxC.ultimoM){
                                    pw.print("\"nodoM"+auxM.ID);
                                    pw.print("\"-> \"nodoM"+auxM.abajo.ID);
                                    pw.print("\"[dir=both,color=\"black:blue\"];\n");
                                }
                            auxM=auxM.abajo;    
                            }
                        }
                
                }
                
             auxC=auxC.izq;    
            }
            
            ///Raiz----->nodoC
            pw.print("\"nodoC"+1);
            pw.print("\"-> \"nodoD"+1);
            pw.print("\"[dir=both,color=\"black:blue\"];\n");
            
        }
      
        pw.println("\n");
        
        /// nodoF---->nodoF
        auxF=primero_abajo;
        if(auxF!=null){
            int b=1;
            int c=b+1;
            while(auxF!=null){
                if(auxF!=ultimo_abajo){
                    pw.print("\"nodoF"+b);
                    pw.print("\"-> \"nodoF"+c);
                    pw.print("\"[dir=both,color=\"black:blue\"];\n");
                    
                        pw.print("\"nodoM"+auxF.primeroM.ID);
                        pw.print("\"-> \"nodoF"+b);
                        pw.print("\"[dir=both,color=\"black:blue\"];\n");
                        
                        ///nodoM-->nodoM
                        NodoMatriz auxM = auxF.primeroM;
                        if(auxM!=null){
                            while(auxM!=null){
                                if(auxM!=auxF.ultimoM){
                                    pw.print("\"nodoM"+auxM.ID);
                                    pw.print("\"-> \"nodoM"+auxM.izq.ID);
                                    pw.print("\"[dir=both,color=\"black:blue\"];\n");
                                }
                             auxM=auxM.izq;   
                            }
                        }
                  
                 b++;
                 c++;
                }else{
                    pw.print("\"nodoF"+b);
                    pw.print("\"-> \"nodoM"+auxF.primeroM.ID);
                    pw.print("\"[dir=both,color=\"black:blue\"];\n");
                    
                    ///nodoM-->nodoM
                    NodoMatriz auxM=auxF.primeroM;
                    if(auxM!=null){
                        while(auxM!=null){
                            if(auxM!=auxF.ultimoM){
                                pw.print("\"nodoM"+auxM.ID);
                                pw.print("\"-> \"nodoM"+auxM.izq.ID);
                                pw.print("\"[dir=both,color=\"black:blue\"];\n");
                            }
                            
                         auxM=auxM.izq;   
                        }
                    }
                
                }
                
            auxF=auxF.abajo;    
            }
            
            ///Raiz-->nodoF
            pw.print("\"nodoD"+1);
            pw.print("\"-> \"nodoF"+1);
            pw.print("\"[dir=both,color=\"black:blue\"];\n");
        }
       
        pw.print("edge [splines=\"true\"];\n");
        pw.print("color=\"orange\"\n");
        pw.print("style =\"filled, bold\"\n");
        pw.print("label =\"Ortogonal\"\n");
        pw.print("}");
        
        }else{
            ///La lista esta vacia....
            pw.print("\n subgraph cluster_1 {\n");
            pw.print("node [style=filled];\n");
            
            pw.print("\"nodoD\"");
            pw.print("[label =\"Matriz\"];");
            pw.print("color=\"orange\"\n");
            
            pw.print("style =\"filled, bold\"\n");
            pw.print("label =\"Matriz Ortogonal\"\n");
            pw.println("}");
        }
        pw.println("}");
        fichero.close();
        
        String cmd = "dot -Tpng Matriz_Ortogonal.dot -o Matriz_Ortogonal.png"; 
      
        try{
        Runtime rt = Runtime.getRuntime();
        rt.exec(cmd);
  
        }catch(Exception e){
            System.out.println("Error..No se pudo graficar...");
        }    
}    
    
}
