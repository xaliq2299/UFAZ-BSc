import javax.swing.*;
import java.awt.*;

/* at a given time a thread is either
    i) free
    ii) sleeping
    iii) transmitting (or holding a message)
*/
enum ThreadState { FREE, SLEEPING, TRANSMITTING }

public class ThreadEllipse extends Ellipse implements Writeable {

    private static final int SLEEP_MAX = 2000;  // max milliseconds a thread can sleep
    private static final int POLL_TIME = 20;    // next thread checking interval if this thread is holding a message

    private static final Color c_free = new Color(184, 176, 160);
    private static final Color c_sleeping = new Color(255, 255, 0);
    private static final Color c_transmitting = new Color(0, 255, 0);

    private ThreadState state;
    private int sleep_time;     // period for which thread sleeps after receiving and passing a message

    public BufferEllipse prev_buffer;     // for reading message
    public ThreadEllipse next_thread;     // thread passes messages (and draws dashed line) to next
    public BufferEllipse next_buffer;     // buffer the message will be written into if next is sleeping

    public ThreadEllipse(String name, int x, int y, int width, int height){
        super(name, x, y, width, height);
        col = c_free;
        state = ThreadState.FREE;
        sleep_time = (int)(Math.random()*SLEEP_MAX);
        next_thread = null;
        next_buffer = null;
    }

    @Override
    public void draw(Graphics g){
        super.draw(g);
        if(next_thread != null)
            Ellipse.drawDashedLine(g,
                x+width,
                y+height/2,
                next_thread.getX(),
                next_thread.getY()+next_thread.getHeight()/2);
    }

    // to check whether this thread is able to receive a message right now
    public boolean isAvailable(){
        return (state == ThreadState.FREE);
    }

    public void setPrevBuffer(BufferEllipse prev){
        this.prev_buffer = prev;
    }

    public void setNextThread(ThreadEllipse next){
        this.next_thread = next;
    }

    public void setNextBuffer(BufferEllipse next){
        this.next_buffer = next;
    }

    // this method is called by the previous thread to pass the message
    public void writeMessage(){

        // just in case
        if(!isAvailable() || next_thread == null) return;

        // thread state is transmitting until it is done sending message (if it can)
        state = ThreadState.TRANSMITTING;
        col = c_transmitting;
        next_thread.writeMessage();

        // timer sets state to free again if thread isn't holding the message after the sleep period
        Timer sleep_timer = new Timer(sleep_time, e -> {

            // if thread is done transmitting and is available now
            if(state != ThreadState.TRANSMITTING){
                state = ThreadState.FREE;
                col = c_free;
                MainWindow.sim.repaint();
            }

            // thread still has the message, regularly check next thread until it is finished
            else{

                // check next thread & next buffer every POLL_TIME milliseconds
                Timer poll_timer = new Timer(POLL_TIME, v -> {

                    // if next thread is available, send message and stop the poll timer
                    if(next_thread.isAvailable()){
                        next_thread.writeMessage();
                        ((Timer)v.getSource()).stop();
                        state = ThreadState.FREE;
                        col = c_free;
                        MainWindow.sim.repaint();
                    }

                });
                poll_timer.start();
            }
        });
        sleep_timer.setRepeats(false);
        sleep_timer.start();

        state = ThreadState.SLEEPING;
        col = c_sleeping;
    }

}
