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
	public void add(E e) throws MaxCapacityException
	{
		if(size==capacity)
			throw new MaxCapacityException();
		array[size++]=e;
	}
	public void remove(int index) throws InvalidIndexException
	{
		if(index<0 || index>=size)
			throw new InvalidIndexException(index);
		for(int i=index; i<size-1; i++)
			array[i]=array[i+1];
		size--;
	}
	public Object get(int i) throws InvalidIndexException
	{
		if(i<0 || i>=size)
			throw new InvalidIndexException(i);
		return array[i];
	}
	public int find(E e) throws  ElementNotFoundException
	{
		for(int i=0; i<size; i++)
			if(array[i].equals(e))
				return i;
		throw new ElementNotFoundException(e);
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
