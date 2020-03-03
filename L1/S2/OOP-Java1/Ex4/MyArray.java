public class MyArray<E>{
	private int capacity;
	private Object[] array = new Object[capacity];
	private int size;
	
	public MyArray(int capacity){
		this.capacity = capacity;
		this.size = 0;
		this.array = new Object[capacity];		
	}
	
	public int size(){
		return this.size;
	}
	
	public boolean isEmpty(){
		return this.size == 0;
	}
	
	public void add(E e){
		if(this.size < this.capacity)
			this.array[this.size++] = e;
	}
	
	public void remove(int index){
		if(this.size > index){
			for(int i=index;i<this.size;i++)
				this.array[i] = this.array[i+1];
			this.size--;	
		}
		else if(this.size == index)
			this.size--;
	}	
	
	public Object get(int i){
		if(this.size > i)
			return this.array[i];
		return 0;
	}

	public String toString(){
		String string = new String();
		for(int i=0;i<this.size;i++)
			string=string+" "+this.array[i];
	
		return string;
	}	
	
	public static void main(String args[]){
		MyArray< Integer > List = new MyArray< Integer >( 10 );
		List.add(2);
		List.add(3);
		List.add(5);
		List.add(7);
		List.add(8);
		System.out.println(List.isEmpty());
		System.out.println(List.size());
		System.out.println(List.toString());						
		List.remove(1);
		System.out.println(List.toString());
		System.out.println(List.get(1));
	}	
}
