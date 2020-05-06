public class MyArray<E>
{
	private Object[] array;
	private int capacity, size;
	public MyArray(int capacity)
	{
		this.capacity=capacity;
		size=0;
		array=new Object[capacity];
	}
	public int size()
	{
		return size;
	}
	public boolean isEmpty()
	{
		return (size==0);
	}
	public void add(E e)
	{
		array[size++]=e;
	}
	public void remove(int index)
	{
		if(index<0 || index>=size)
			return;
		for(int i=index; i<size-1; i++)
			array[i]=array[i+1];
		size--;
	}
	public Object get(int i)
	{
		if(i<0 || i>=size)
			return null;
		return array[i];
	}
	public String toString()
	{
		String string="";
		if(size>0)
			string+=array[0].toString();
		for(int i=1; i<size; i++)
			string+=(" "+array[i].toString());
		return string;
	}
}
