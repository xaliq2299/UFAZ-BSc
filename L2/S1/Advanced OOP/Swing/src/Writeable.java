public interface Writeable {

    // needed to check availability before writing
    boolean isAvailable();

    // any implementation must, of course, be able to be messaged
    void writeMessage();
}
