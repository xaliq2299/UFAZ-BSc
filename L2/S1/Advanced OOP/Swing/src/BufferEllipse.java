import java.awt.*;

public class BufferEllipse extends Ellipse implements Writeable {

    private static final Color c_empty = new Color(100, 100, 100);
    private static final Color c_full = new Color(255, 51, 153);

    private boolean is_empty;  // buffer availability

    // references to adjacent threads (each buffer draws its own arrows)
    public ThreadEllipse prev_thread;
    public ThreadEllipse next_thread;

    public BufferEllipse(String name, int x, int y, int width, int height){
        super(name, x, y, width, height);
        col = c_empty;
        is_empty = true;
        prev_thread = null;
        next_thread = null;
    }

    @Override
    public void draw(Graphics g) {
        super.draw(g);

        // arrow from prev_thread to this
        if(prev_thread != null)
            Ellipse.drawArrow(g,
                    prev_thread.getX()+prev_thread.getWidth()/2+10,
                    prev_thread.getY()+prev_thread.getHeight()-3,
                    x+width/2-15,
                    y+3);

        // arrow from this to next_thread
        if(next_thread != null)
            Ellipse.drawArrow(g,
                    x+width/2+10,
                    y+3,
                    next_thread.getX()+next_thread.getWidth()/2-10,
                    next_thread.getY()+next_thread.getHeight()-3);
    }

    public boolean isAvailable(){
        return is_empty;
    }

    public void writeMessage(){
        is_empty = false;
        col = c_full;
    }

    public void readMessage(){
        is_empty = true;
        col = c_empty;
    }

    public void setPrevThread(ThreadEllipse prev_thread) {
        this.prev_thread = prev_thread;
    }

    public void setNextThread(ThreadEllipse next_thread) {
        this.next_thread = next_thread;
    }
}
