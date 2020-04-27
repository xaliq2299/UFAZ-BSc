import java.util.Scanner;

public class TriangleType{
	
	public static String triangle_type(int a, int b, int c){
		if(a<=0 || b<=0 || c<=0)
			return "None";
		if(c>Math.abs(a-b) && c<a+b && a>Math.abs(c-b) && a<c+b && b>Math.abs(a-c) && b<a+c){
			if(a == b && b == c)
				return "equilateral";
			else if(a==b || b==c || a==c)
				return "isosceles";
			else
				return "scalene";
		}
		else
			return "None";
	}

	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		//System.out.println(a+", "+b+", "+c);
		System.out.println( triangle_type(a,b,c) );
	}

}