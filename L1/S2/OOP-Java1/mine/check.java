public class check {
	public static void main(String[] args)	
	{	
		int a;
		float f = 58.562;
		System.out.printf("%d\n", a); //unlikely in C, Java will not print any random number for a, but produce an error.
		
		System.out.printf("%d\n", (int) f); //unlikely in C, Java can't do this casting, bcz this is not a valid promotion and can lead to lossy conversion. 
	}
}
