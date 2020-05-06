import java.util.Scanner;

public class Exercise3
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		ParanthesisMatching p=new ParanthesisMatching(input.next());
		System.out.println(p.parse());
	}
}
