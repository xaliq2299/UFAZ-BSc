public class MyStack{
	private int size=10;
	private int[] array = new int[size];
	private int top=0;
	
	//Getters
	public int getSize(){
		return this.size;
	}
	
	public int getTop(){
		return this.top;
	}
	
	//Setters
	public void setSize(int size){
		this.size = size;
	}
	
	public void setTop(int top){
		this.top = top;
	}
	
	//print Stack
	public void print(){
		System.out.println("Our Stack:");
		for(int i=top-1;i>=0;i--)
			System.out.println(this.array[i]);
	}
	
	//basic operation methods
	public void push(int element){
		this.array[top] = element;
		this.top++;
	}
	
	public int peek(){
		return this.array[top-1];
	}
	
	public int pop(){
		int a = this.array[this.top-1];
		this.top-=1;
		return a;
	}
	
	public boolean isEmpty(){
		return this.size == 0;
	}

	public static void main(String args[]){
		MyStack stack = new MyStack();
		System.out.println( stack.getSize() );
		System.out.println( stack.getTop() );
		stack.push(5);
		stack.push(11);
		stack.push(7);
		stack.push(9);
		stack.print();
		System.out.println("Peek: "+stack.peek());
		System.out.println(stack.pop());		
		System.out.println(stack.isEmpty());
	}
}
