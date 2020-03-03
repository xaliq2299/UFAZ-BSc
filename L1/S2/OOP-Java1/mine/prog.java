// using EOF and math function power
import java.util.Scanner;

public class prog {
	public static void main (String[] args)
	{
		Scanner input = new Scanner (System.in);
		int a=1;
		
		while ( input.hasNext() )
		{
			int num = input.nextInt();
			a+=Math.pow(2, num);
		}
		
		System.out.printf("num=%d\n", a);
	}
}
