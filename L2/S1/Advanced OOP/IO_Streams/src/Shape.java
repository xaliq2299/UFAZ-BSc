import java.awt.*;
import java.io.Serializable;

public abstract class Shape implements Serializable{
    protected int x, y;
    protected int width, height;
    protected Color col;
    protected boolean isMoving;
    protected int mx, my; // store offsets of mouse during dragging
    protected int id; // used in file management, each shape has its own value

    public Shape(int x, int y, int width, int height, Color c, int id) {
        this.x=x; 			this.y=y;
        this.width=width;	this.height=height;
        this.mx = 0;        this.my = 0;
        this.col=c;			this.id=id;
    }

    // implemented in subclasses, draws the object on screen
    public abstract void draw(Graphics g);

    // used to check whether mouse clicked on shape or not
    public abstract boolean containsPoint(int x, int y);

    public void translateTo(int new_x, int new_y) {
        x = new_x;  y = new_y;
    }

    public void setColor(Color col) {
        this.col=col;
    }
}