/*
 *  A drawable ellipse, base class of threads and buffers
 */

import java.awt.*;

public abstract class Ellipse {

    String name;
    int x, y, width, height;
    Color col;

    public Ellipse(String name, int x, int y, int width, int height){
        this.name = name;
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    // draws the ellipse
    public void draw(Graphics g){
        g.setColor(col);
        g.fillOval(x, y, width, height);
        g.setColor(Color.BLACK);
        g.setFont(new Font("Sans Serif", Font.PLAIN, 24));
        g.drawString(name, x+width/2-14, y+height/2+10);
    }


    static void drawDashedLine(Graphics g, int start_x, int start_y, int end_x, int end_y){
        int dist = 6;

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(3));
        g.setColor(Color.DARK_GRAY);

        for (int i = start_x; i <= end_x; i += 2 * dist) g.drawLine(i, start_y, i + dist, end_y);

        g2.setStroke(new BasicStroke(1));
    }

    static void drawArrow(Graphics g, int start_x, int start_y, int end_x, int end_y){
        double alpha;
        int x_len = 10, y_len = 6, length = (int) Math.sqrt((end_x-start_x)*(end_x-start_x) + (end_y-start_y)*(end_y-start_y));

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(3));

        g.drawLine(start_x, start_y, end_x, end_y);

        alpha = Math.atan2((end_y-start_y), (end_x-start_x));
        g2.translate(end_x, end_y);
        g2.rotate(alpha);
        g.drawLine(-x_len, -y_len, 0, 0);
        g.drawLine(-x_len, y_len, 0, 0);
        g2.rotate(-alpha);
        g2.translate(-end_x, -end_y);

        g2.setStroke(new BasicStroke(1));
    }

}
