import java.awt.*;

public class Ellipse extends Shape{

    public Ellipse(int x, int y, int width, int height, Color c, int id) {
        super(x, y, width, height, c, id);
    }

    public void draw(Graphics g){
        g.setColor(col);
        g.fillOval(x, y, width, height);
        g.setColor(Color.GRAY);
        if(isMoving) g.drawRect(x, y, width, height);
    }

    @Override
    public boolean containsPoint(int x, int y){

        // some math: ellipse is defined as set of all points that have
        // a fixed sum of distances to the 2 foci.

        float dx = x - (this.x + this.width/2), dy = y - (this.y + this.height/2);

        return dx * dx / (this.width*this.width/4) + dy * dy / (this.height*this.height/4) <= 1;
    }
}