import javax.swing.*;
import java.awt.*;

public class Simulation extends JPanel {

    private int t_b_gap = 35;

    private int threads_start_x = 40;
    private int threads_y = 150;
    private int thread_w = 100;
    private int thread_h = 80;
    private int threads_gap = thread_w*3/2;

    private int buffers_start_x = threads_start_x + thread_w*2/3;
    private int buffers_y = threads_y + thread_h + t_b_gap;
    private int buffer_w = 100;
    private int buffer_h = 80;
    private int buffers_gap = threads_gap;

    void setMessageFlow(ThreadEllipse t1, BufferEllipse b, ThreadEllipse t2){
        if(t2 != null) t1.setNextThread(t2);
        if(b != null) t1.setNextBuffer(b);

        if(t1 != null) b.setPrevThread(t1);
        if(t2 != null) b.setNextThread(t2);

        if(b != null) t2.setPrevBuffer(b);
    }

    private ThreadEllipse[] threads = new ThreadEllipse[5];
    private BufferEllipse[] buffers = new BufferEllipse[4];


    public Simulation(){
        // set double buffering on
        super(true);

        // initializing threads
        threads[0] = new ThreadEllipse("ST", threads_start_x, threads_y, thread_w, thread_h);
        for(int i=1;i<threads.length-1;i++)
            threads[i] = new ThreadEllipse("T"+i,threads_start_x+i*threads_gap,threads_y,thread_w,thread_h);
        threads[4] = new ThreadEllipse("WT", threads_start_x+4*threads_gap, threads_y, thread_w, thread_h);

        // initializing buffers
        for(int i=0; i<buffers.length; i++)
            buffers[i] = new BufferEllipse("B"+(i+1), buffers_start_x+i*buffers_gap, buffers_y, buffer_w, buffer_h);

        for(int i=0; i<threads.length-1; i++)
            setMessageFlow(threads[i], buffers[i], threads[i+1]);

        for(int i=0; i<threads.length; i++) System.out.println("next of "+i+": "+threads[i].next_thread);

        threads[0].writeMessage();
    }

    @Override
    public void paintComponent(Graphics g){

        // anti-aliasing
        Graphics2D g2d = (Graphics2D) g;
        g2d.setRenderingHint(
                RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);

        for (ThreadEllipse t : threads)
            t.draw(g);

        for (BufferEllipse b : buffers)
            b.draw(g);
    }
}