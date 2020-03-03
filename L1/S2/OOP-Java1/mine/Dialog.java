// Basic input with a dialog box.
import javax.swing.JOptionPane;
public class Dialog
{
	public static void main( String[] args )
	{
		// prompt user to enter name
		String name = JOptionPane.showInputDialog( "What is your name?" );
	// create the message
	String message =
	String.format( "Welcome, %s, to Java Programming!", name );
	// display the message to welcome the user by name
	JOptionPane.showMessageDialog( null, message );
	} // end main
} // end class NameDialog
