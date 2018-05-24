
package Proyecto1;

import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import org.apache.thrift.protocol.TBinaryProtocol;
import org.apache.thrift.protocol.TProtocol;
import org.apache.thrift.transport.TSocket;
import org.apache.thrift.transport.TTransportException;
import proyecto1.Conectar;


public class Proyecto1 {

  
    public static void main(String[] args) {
        try {
            TSocket transport = new TSocket("localhost",9090);
            transport.open();
            TProtocol protocolo = new TBinaryProtocol(transport);
            Conectar.Client cliente = new Conectar.Client(protocolo);
            VentanaPrincipal ventana = new VentanaPrincipal();
            ventana.setear(cliente);
            ventana.setVisible(true);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null,"El Servidor no esta Funcionando" , "Error", JOptionPane.INFORMATION_MESSAGE);
        }                
                
    }
    
}
