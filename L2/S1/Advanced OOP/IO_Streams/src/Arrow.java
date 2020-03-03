import java.awt.*;

public class Arrow extends Shape{

    public Arrow(int x, int y, int width, int height, Color c, int id) {
        super(x, y, width, height, c, id);
    }

    public void draw(Graphics g) {
        double alpha;
        int x_len = 10, y_len = 6;

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(3));

        g.setColor(col);
        g.drawLine(x, y, x+width, y+height);  // the line

        alpha = Math.atan2((height), (width));   // calculating the angle between horizontal and line
        g2.translate(x+width, y+height);
        g2.rotate(alpha);                        // rotating so that it's easier to draw the head
        g.drawLine(-x_len, -y_len, 0, 0);
        g.drawLine(-x_len, y_len, 0, 0);
        g2.rotate(-alpha);
        g2.translate(-x-width, -y-height);  // setting everything as it was before

        g2.setStroke(new BasicStroke(1));

        g.setColor(Color.GRAY);
        if(isMoving) g.drawRect(x, y, width, height);
    }

    @Override
    public boolean containsPoint(int x, int y){

        float k, b; // parameters of the line

        if(width == 0)
            k = (float)this.height/(this.width+0.01f);
        else
            k = (float)(this.height) / this.width;
        b = (float) this.y - k*this.x;

        // as a line is very thin, we check +-5 pixels distance too
        return (x*k+b >= y-5 && x*k+b <= y+5);
    }

}