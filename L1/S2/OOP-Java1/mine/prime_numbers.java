import java.util.Scanner;

public class primeNumbers {

	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int num, divisor;
		num = in.nextInt();
		System.out.printf("%d=", num);
	
		while(num!=1)
		{
			divisor=get_prime(num);
			
			if(num/divisor!=1)		
				System.out.printf("%d*", divisor );
			else
				System.out.printf("%d\n", divisor);
			
			num/=divisor;		
		}
	}	
	

	static int get_prime(int num)
	{
		int check, a, b;
	
		for(a=2;;a++)
		{
			check=0;
			for(b=1;b<=a;b++)
			{
				if(a%b==0)
				check++;
			}
	
			if(check == 2 && num%a==0)
			return a;
		}
	}
}
