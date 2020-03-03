import java.awt.*;

public class Line extends Shape{

    private int dash_interval; //this is used for the case of drawing dashed line, if it's 0 then we draw a simple line

    public Line(int x, int y, int width, int height, Color c, int id, int dash_interval){
        super(x, y, width, height, c, id);
        this.dash_interval=dash_interval;
    }

    public void draw(Graphics g){
        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(3));
        g.setColor(col);
        g.drawLine(x, y, x+width, y+height);
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

        return (x*k+b >= y-5 && x*k+b <= y+5);
    }

}