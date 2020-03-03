import java.util.Scanner;

abstract class Shape{
	protected abstract float area(int x, int y);
}

public class Square extends Shape{
	private int width, height;
		
	public static void main(String args[]){		
		Scanner input = new Scanner(System.in);
		Square s = new Square();
		s.width = input.nextInt();
		s.height = input.nextInt();
		System.out.println( s.area(s.width, s.height) );
	}
	
	public float area(int x, int y){
		return (float)x*y;
	}
}
