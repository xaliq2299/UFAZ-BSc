import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;

// currently active tool
enum Tool { MOVE, DELETE, FILL, RECT, ELLIPSE, LINE, ARROW }

// TODO serialization and loading back
public class PCanvas extends JPanel implements MouseListener, MouseMotionListener{

    private Color active_col;          // current drawing color
    private Tool active_tool;          // current tool being used
    ArrayList<Shape> shapes;   // all of the shapes on screen

    private boolean is_drawing;        // true if user is drawing a shape right now
    private Shape currently_drawing;   // used when user is drawing a shape


    public PCanvas(){

        setBackground(Color.WHITE);

        this.active_col = Color.RED;
        this.active_tool = Tool.MOVE;
        this.shapes = new ArrayList<>();
        this.is_drawing = false;
        this.currently_drawing = null;

        // PCanvas itself handles all mouse events
        setFocusable(true);
        addMouseListener(this);
        addMouseMotionListener(this);
        this.requestFocus();
    }

    public void paintComponent(Graphics g){

        // anti-aliasing
        ((Graphics2D)g).setRenderingHint(
                RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);

        super.paintComponent(g);

        // draw all shapes
        for(Shape s : shapes) s.draw(g);

        if(is_drawing) currently_drawing.draw(g);

        // to write the name of current tool
        String tool_name;
        switch (active_tool){
            case MOVE:
                tool_name = "move";
                break;
            case DELETE:
                tool_name = "delete";
                break;
            case FILL:
                tool_name = "fill";
                break;
            case RECT:
                tool_name = "rect";
                break;
            case ELLIPSE:
                tool_name = "ellipse";
                break;
            case LINE:
                tool_name = "line";
                break;
            case ARROW:
                tool_name = "arrow";
                break;
            default:
                // shouldn't happen
                tool_name = "unknown";
        }
        g.setColor(Color.BLACK);
        g.setFont(new Font("Sans Serif", Font.BOLD, g.getFont().getSize()));
        g.drawString(":"+tool_name+":", 2, 12);
        g.setFont(new Font("Sans Serif", Font.PLAIN, g.getFont().getSize()));
        g.drawString("shapes: "+shapes.size(), 2, 24);
    }

    public void setActiveColor(Color c){
        this.active_col = c;
    }

    public void setActiveTool(Tool t){
        this.active_tool = t;
    }

    @Override
    public void mousePressed(MouseEvent e){
        int target_id = -1;
        // check all shapes : who did user press on?
        for (int i = shapes.size()-1; i >= 0; i--) {
            if (shapes.get(i).containsPoint(e.getX(), e.getY())){
                target_id = i;
                shapes.get(i).mx = shapes.get(i).x - e.getX();   // prevents "jumping" of shape
                shapes.get(i).my = shapes.get(i).y - e.getY();
                break;
            }
        }

        // do something depending on current tool
        switch (active_tool){
            case MOVE:
                if (target_id != -1) shapes.get(target_id).isMoving = true;
                break;
            case FILL:
                break;
            case DELETE:
                break;
            case RECT:
                currently_drawing = new Rectangle(e.getX(), e.getY(), 1, 1, active_col, shapes.size());
                is_drawing = true;
                shapes.add(currently_drawing);
                break;
            case ELLIPSE:
                currently_drawing = new Ellipse(e.getX(), e.getY(), 1, 1, active_col, shapes.size());
                is_drawing = true;
                shapes.add(currently_drawing);
                break;
            case LINE:
                currently_drawing = new Line(e.getX(), e.getY(), 1, 1, active_col, shapes.size(), 10);
                is_drawing = true;
                shapes.add(currently_drawing);
                break;
            case ARROW:
                currently_drawing = new Arrow(e.getX(), e.getY(), 1, 1, active_col, shapes.size());
                is_drawing = true;
                shapes.add(currently_drawing);
                break;
        }
        repaint();
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        switch (active_tool){
            case MOVE:
                for (int i = shapes.size()-1; i >= 0; i--) {
                    if(shapes.get(i).isMoving){
                        // nothing must move after mouse is released
                        shapes.get(i).isMoving = false;
                        break;
                    }
                }
                break;
            case FILL:
                break;
            case DELETE:
                break;
            default:
                if(is_drawing) {
                    // we don't need (non-line) shapes with negative width or height, dealing with this  is
                    // more difficult, so we just remove the shape from the array, effectively ignoring it
                    if(currently_drawing.width < 0 || currently_drawing.height < 0){
                        if(active_tool != Tool.ARROW && active_tool != Tool.LINE)
                            shapes.remove(shapes.size()-1);
                    }
                    is_drawing = false;
                    currently_drawing = null;
                    repaint();
                }
            break;
        }
    }

    @Override
    public void mouseDragged(MouseEvent e){
        int target_id = -1;
        for (int i = shapes.size()-1; i >= 0; i--) {
            if(shapes.get(i).isMoving){
                target_id = i;
                break;
            }
        }

        switch (active_tool){
            case MOVE:
                // if moving, make the shape that is moved follow the mouse
                if (target_id > 0) shapes.get(target_id).translateTo(e.getX()+shapes.get(target_id).mx, e.getY()+shapes.get(target_id).my);
                break;
            case FILL:
                break;
            case DELETE:
                break;
            default:
                // user is drawing something new : change width and height
                currently_drawing.width = e.getX()-currently_drawing.x;
                currently_drawing.height = e.getY()-currently_drawing.y;
                break;
        }
        repaint();
    }

    @Override
    public void mouseClicked(MouseEvent e){
        int target_id = -1;
        for (int i = shapes.size()-1; i >= 0; i--) {
            if (shapes.get(i).containsPoint(e.getX(), e.getY())) {
                target_id = i;
                break;
            }
        }
        if (target_id == -1) return;

        switch (active_tool) {
        case DELETE:
            shapes.remove(target_id);
            break;
        case FILL:
            shapes.get(target_id).setColor(active_col);
            break;
        default:
            break;
        }

        repaint();
    }

    // don't need these
    public void mouseMoved(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}
}
