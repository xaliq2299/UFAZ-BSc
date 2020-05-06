public class Exercise2
{
	public static void main(String[] args)
	{
		MyArray<String> myArray=new MyArray<String>(args.length);
		System.out.println("size "+myArray.size());
		System.out.println("isEmpty "+myArray.isEmpty());
		for(int i=0; i<args.length; i++)
		{
			myArray.add(args[i]);
			System.out.println(myArray.toString());
		}
		for(int i=0; i<myArray.size(); i++)
			System.out.println(myArray.get(i));
		while(!myArray.isEmpty())
		{
			myArray.remove(0);
			System.out.println(myArray.toString());
		}
	}
}
