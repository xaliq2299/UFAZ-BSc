import java.util.Scanner;
public class test{

//Scanner input = new Scanner();

public static int gcd(int a, int b)
{
	for(int i=a;i>0;i--)
	{
		if(a%i == 0 && b%i == 0)
			return i;
	}
	return -1000;
}

	public static void main(String args[]){
		Scanner input = new Scanner(System.in);
		int a, b;
		a = input.nextInt();
		b = input.nextInt();
		System.out.printf("%d\n", gcd(a, b));
	}
}
