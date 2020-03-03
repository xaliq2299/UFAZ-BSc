import java.util.Scanner;

public class calculator {
	public static void main(String args[]){
		Scanner input = new Scanner(System.in);
		int a, b, c, ans;
		
		System.out.println("Give 2 integers successively :");
		a=input.nextInt();
		b=input.nextInt();
		
		System.out.println("Choose an operation");
		System.out.printf("1. +\n2. -\n3. *\n4. /\n5. %%\n");
		System.out.print("Operation : ");
		c=input.nextInt();
		
		switch(c) {
			case 1: ans=a+b; System.out.printf("Output : %d + %d = %d\n", a, b, ans); break;
			case 2: ans=a-b; System.out.printf("Output : %d - %d = %d\n", a, b, ans); break;
			case 3: ans=a*b; System.out.printf("Output : %d * %d = %d\n", a, b, ans); break;
			case 4: ans=a/b; System.out.printf("Output : %d / %d = %d\n", a, b, ans); break;
			case 5: ans=a%b; System.out.printf("Output : %d %% %d = %d\n", a, b, ans); break;
			default: break;
		}
	}
}
