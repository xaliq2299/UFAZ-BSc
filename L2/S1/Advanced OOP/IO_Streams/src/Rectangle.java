
import java.awt.*;

public class Rectangle extends Shape{

    public Rectangle(int x, int y, int width, int height, Color c, int id) {
        super(x, y, width, height, c, id);
    }
    public void draw(Graphics g){
        g.setColor(col);
        g.fillRect(x, y, width, height);
        g.setColor(Color.GRAY);
        if(isMoving) g.drawRect(x, y, width, height);
    }

    @Override
    public boolean containsPoint(int x, int y) {
        // simplest shape to check for containing a point
        return (this.x <= x && x <= this.x+this.width && this.y <= y && y <= this.y+this.height);
    }
}