public class Stack
{
	int[] array;
	int top, capacity;
	public Stack(int capacity)
	{
		array=new int[capacity];
		this.capacity=capacity;
		top=-1;
	}
	public int getElement(int i)
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
	public void setElement(int value, int i)
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
	public void push(int element)
	{
		array[++top]=element;
	}
	public int peek()
	{
		return array[top];
	}
	public int pop()
	{
		return array[top--];
	}
	public boolean isEmpty()
	{
		return (top==-1);
	}
}
