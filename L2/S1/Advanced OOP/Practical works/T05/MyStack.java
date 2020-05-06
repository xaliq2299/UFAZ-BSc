public class MyStack<E>
{
	private Object[] array;
	private int top, capacity;
	public MyStack(int capacity)
	{
		this.array=new Object[capacity];
		this.capacity=capacity;
		this.top=-1;
	}
	public Object getElement(int i)
	{
		return array[i];
	}
	public int getTop()
	{
		return top;
	}
	public int getCapacity()
	{
		return capacity;
	}
	public void setElement(E value, int i)
	{
		array[i]=value;
	}
	public void setTop(int top)
	{
		this.top=top;
	}
	public void setCapacity(int capacity)
	{
		this.capacity=capacity;
	}
	public void push(E element) throws MaxCapacityException
	{
		if(top+1==capacity)
			throw new MaxCapacityException();
		top++;
		array[top]=element;
	}
	public Object peek() throws EmptyStackException
	{
		if(this.isEmpty())
			throw new EmptyStackException();
		return array[top];
	}
	public Object pop() throws EmptyStackException
	{
		if(this.isEmpty())
			throw new EmptyStackException();
		return array[top--];
	}
	public boolean isEmpty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
	public String toString()
	{
		String string="";
		if(!this.isEmpty())
			string+=array[0].toString();
		for(int i=1; i<=top; i++)
			string+=(" "+array[i].toString());
		return string;
	}
}
