import javax.swing.*;

public class MainWindow {

    static final String title    = "Thread Simulation";   // name of our program
    static final int    WIDTH    = 800;
    static final int    HEIGHT   = 400;
    public static Simulation sim;

    public static void main(String[] args){

        // preparing the window
        JFrame f = new JFrame(title);
        f.setSize(WIDTH, HEIGHT);                             // size of the window
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);     // exit when the x button is clicked
        f.setResizable(false);                                // user does not need to resize the window

        // this will draw the graphics
        sim = new Simulation();

        f.getContentPane().add(sim);

        f.setVisible(true);

    }

}
