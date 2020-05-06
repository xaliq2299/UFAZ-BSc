public class ParanthesisMatching
{
	MyStack<Character> stack;
	String string;
	public ParanthesisMatching(String string)
	{
		this.string=new String(string);
		stack=new MyStack<Character>(string.length());
	}
	public String getString()
	{
		return new String(string);
	}
	public MyStack<Character> getStack()
	{
		return stack;
	}
	public void setString(String string)
	{
		this.string=new String(string);
	}
	public void setStack(MyStack<Character> stack)
	{
		this.stack=stack;
	}
	private static boolean bracketsAreMatching(char c1, char c2)
	{
		if((c1=='(' && c2==')') || (c1==')' && c2=='('))
			return true;
		if((c1=='{' && c2=='}') || (c1=='}' && c2=='{'))
			return true;
		if((c1=='[' && c2==']') || (c1==']' && c2=='['))
			return true;
		return false;
	}
	public boolean parse()
	{
		for(int i=0; i<string.length(); i++)
		{
			if(string.charAt(i)=='(' || string.charAt(i)=='{' || string.charAt(i)=='[')
			{
				try
				{
					stack.push(Character.valueOf(string.charAt(i)));
				}
				catch(MaxCapacityException exception)
				{
					System.out.println(exception);
				}
			}
			else if(string.charAt(i)==')' || string.charAt(i)=='}' || string.charAt(i)==']')
			{
				if(stack.isEmpty())
					return false;
				try
				{
					if(ParanthesisMatching.bracketsAreMatching(string.charAt(i), (char) stack.peek()))
					{
						try
						{
							stack.pop();
						}
						catch(EmptyStackException exception1)
						{
							System.out.println(exception1);
						}
					}
					else
						return false;
				}
				catch(EmptyStackException exception2)
				{
					System.out.println(exception2);
				}
			}
		}
		if(stack.isEmpty())
			return true;
		else
			return false;
	}
}
