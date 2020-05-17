import java.rmi.registry.LocateRegistry ;
import java.rmi.registry.Registry ;
import java.rmi.server.UnicastRemoteObject ;
import java.util.Arrays ;



public class Serveur {

	public static void main ( String [ ] args ) {
		try {
			
				int port = 1099;
				Message skeleton = (Message) UnicastRemoteObject.exportObject(new MessageImpl () , 0);
				System.out.println ( " Serveur pret " ) ;
				Registry registry = LocateRegistry.getRegistry (port);
				System.out.println ( " Service Message enregistre " ) ;
				if (! Arrays.asList(registry.list()).contains (" Message "))
					registry.bind(" Message ", skeleton );
				else
					registry.rebind (" Message ", skeleton );
		} catch ( Exception ex) {
			ex.printStackTrace ();
			}
	}	  
}

