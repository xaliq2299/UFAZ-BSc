import java.util.Scanner;

public class Exercise1
{
	public static void main(String[] args)
	{
		MyArray<String> myArray=new MyArray<String>(args.length);
		System.out.println("size "+myArray.size());
		System.out.println("isEmpty "+myArray.isEmpty());
		for(int i=0; i<args.length; i++)
		{
			try
			{
				myArray.add(args[i]);
			}
			catch(MaxCapacityException exception)
			{
				System.out.println(exception);
			}
			System.out.println(myArray.toString());
		}
		try
		{
			myArray.add("Nope");
		}
		catch(MaxCapacityException exception)
		{
			System.out.println(exception);
		}
		for(int i=-1; i<=myArray.size(); i++)
		{
			try
			{
				System.out.println(myArray.get(i));
			}
			catch(InvalidIndexException exception)
			{
				System.out.println(exception);
			}
		}

		String string;
		Scanner input=new Scanner(System.in);
		do
		{
			string=input.next();
			try
			{
				System.out.println(myArray.find(string));
			}
			catch(ElementNotFoundException exception)
			{
				System.out.println(exception);
				continue;
			}
			break;
		}
		while(true);

		while(!myArray.isEmpty())
		{
			try
			{
				myArray.remove(1);
			}
			catch(InvalidIndexException exception1)
			{
				try
				{
					myArray.remove(0);
				}
				catch(InvalidIndexException exception2)
				{
					System.out.println(exception2);
				}
				System.out.println(exception1);
			}
			System.out.println(myArray.toString());
		}
	}
}
