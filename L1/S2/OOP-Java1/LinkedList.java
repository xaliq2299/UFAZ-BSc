public class LinkedList {
  private static class Node {
    private String data;
    private Node next;
    static private int size = 0;

    // Constructor for NODE
   public Node(String data, Node next) {
      this.data = data;
      this.next = next; // references the next node
      this.size++;
    }
  } // end of Node definition

  private Node first = null;

	//myCode starts
  public static void main(String[] args){
  	LinkedList myLL = new LinkedList();
  	System.out.println( myLL.isEmpty() );
  	myLL.add("GO");
    System.out.println( myLL.toString() );
    myLL.add("CS:");
    System.out.println( myLL.toString() );
  }
 	//myCode ends
  
  public boolean isEmpty(){
    return this.first == null;
  }

  public void add(String data) {
    Node n = new Node(data, this.first);
    this.first = n;
  }

  public String toString() {
    String s = ""; // String s = new String();
    Node n = this.first;
    s += "List size: " + Node.size + " ";
    while (n != null) {
      s += n.data + " ";
      n = n.next;
    }
    return s;
  }
}
