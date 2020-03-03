// calculating number pi using infinite series
import java.util.Scanner;

public class Pi {
	public static void main (String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		double pi = 0;
		int choice = input.nextInt();
		
		for ( int a=1, check=1; a<=choice; a++, check+=2 )
		{
			if ( a%2 == 0 )
				pi-=(double)(4/check);
			else
				pi+=(double)(4/check);
		}
		
		System.out.println("Pi = " +pi);
	}
}
