import javax.swing.*;
import javax.swing.event.ChangeEvent;
import java.awt.*;
import java.io.*;
import java.util.ArrayList;

public class MainWindow {

    static final String title    = "IOStreams Mini-Project";   // name of our program
    static final int    WIDTH    = 800;
    static final int    HEIGHT   = 600;

    static PCanvas canvas;


    public static void saveShapesToFile(ArrayList<Shape> al, File f) {
        try{
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(f));
            oos.writeObject(al);
            oos.flush();
            oos.close();
        }
        catch (Exception e){
            System.out.println("An exception occurred while trying to save canvas to a file:");
            System.out.println(e.getMessage());
        }
    }

    public static ArrayList<Shape> loadShapesFromFile(File f){
        try{
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream(f));
            ArrayList<Shape> al = (ArrayList<Shape>) ois.readObject();
            ois.close();
            return al;
        }
        catch (Exception e){
            System.out.println("An exception occurred while trying to save canvas to a file:");
            System.out.println(e.getMessage());
            return null;
        }
    }


    public static void main(String[] args){

        // preparing the window
        JFrame frame = new JFrame(title);
        frame.setSize(WIDTH, HEIGHT);                             // size of the window
        frame.setMinimumSize(new Dimension(400, 300));
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);     // exit when the x button is clicked
        frame.setLayout(new BorderLayout());


        // menu bar for file operations
        Menubar menu = new Menubar();


        // this will draw the graphics
        canvas = new PCanvas();


         /*
            toolbar contains tools:
              * move
              * delete
              * fill
              * create rectangle
              * create circle
              * create dashed line
              * create arrow
         */
        JToolBar toolbar = new JToolBar("Toolbar");
        toolbar.setLayout(new GridLayout(7, 1));
        toolbar.setFloatable(false);  // no need for fancy stuff
        JButton move_b = new JButton("move"),
                delete_b = new JButton("delete"),
                fill_b = new JButton("fill"),
                rect_b = new JButton("rect"),
                ellipse_b = new JButton("ellipse"),
                line_b = new JButton("line"),
                arrow_b = new JButton("arrow");

        // each button changes active tool to its own
        move_b.addActionListener(   a -> { canvas.setActiveTool(Tool.MOVE); canvas.repaint();});
        delete_b.addActionListener( a -> { canvas.setActiveTool(Tool.DELETE); canvas.repaint();});
        fill_b.addActionListener(   a -> { canvas.setActiveTool(Tool.FILL); canvas.repaint();});
        rect_b.addActionListener(   a -> { canvas.setActiveTool(Tool.RECT); canvas.repaint();});
        ellipse_b.addActionListener(a -> { canvas.setActiveTool(Tool.ELLIPSE); canvas.repaint();});
        line_b.addActionListener(   a -> { canvas.setActiveTool(Tool.LINE); canvas.repaint();});
        arrow_b.addActionListener(  a -> { canvas.setActiveTool(Tool.ARROW); canvas.repaint();});

        toolbar.add(move_b);
        toolbar.add(delete_b);
        toolbar.add(fill_b);
        toolbar.add(rect_b);
        toolbar.add(ellipse_b);
        toolbar.add(line_b);
        toolbar.add(arrow_b);


        // color chooser
        JColorChooser cc = new JColorChooser();
        cc.getSelectionModel().addChangeListener( (ChangeEvent e) -> {
            canvas.setActiveColor(cc.getColor());
//            canvas.repaint();
        });
        cc.setPreviewPanel(new JPanel());  // removing the preview pane


        // side panel contains toolbar and color chooser
        JPanel side = new JPanel();
        side.setPreferredSize(new Dimension(360, 400));
        side.setLayout(new GridLayout(2, 1));
        side.add(toolbar);
        side.add(cc);


        // main frame contains menu bar, toolbar, and color chooser
        frame.setJMenuBar(menu);
        frame.getContentPane().add(side, BorderLayout.LINE_START);
        frame.getContentPane().add(canvas, BorderLayout.CENTER);

        frame.setVisible(true);
    }

}
