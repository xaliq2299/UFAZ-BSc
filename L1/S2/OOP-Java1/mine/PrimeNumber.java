import java.util.Scanner;

public class PrimeNumber {
	
	public static void main(String[] args)
	{
		Scanner input = new Scanner (System.in);
		int num;
		
		System.out.print("Enter any integer: ");
		num = input.nextInt();
			
		if (check(num) == 1 )
			System.out.println(num+ " is prime");
		else
			System.out.println(num+ " is not prime");
	}
	
	public static int check (int n)
	{
		for ( int a=2; a<=n/2; a++ )	
		{
			if ( n%a == 0 )
				return 0;
		}
		
		return 1;
	}
}
