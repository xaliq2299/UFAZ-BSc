import java.util.Scanner;

public class condition {
	public static void main(String args[]){
		int[] ans = method();
		
		if(ans.length == 2)
			System.out.printf("%d %d\n", ans[0], ans[1]);
		else
			System.out.println(ans[0]);
	}

	public static int[] method() {	
		Scanner input = new Scanner(System.in);
		int a, b;
		System.out.println("Enter 2 integers:");
		a=input.nextInt();
		b=input.nextInt();
		
		if(a%2 == 0 && b%2 == 0) {
			int[] array = new int[1];
			array[0] = a+b;
			System.out.print("Sum: ");
			return array;
		}
		else if(a%2 != 0 && b%2 != 0) {
			int[] array = new int[1];
			array[0] = a*b;
			System.out.print("Multiplication: ");
			return array;
		}
		else{
			int[] array = new int[2];
			array[0] = a*a;
			array[1] = b*b;
			System.out.print("Square of each integer: ");
			return array;
		}
	}
}
