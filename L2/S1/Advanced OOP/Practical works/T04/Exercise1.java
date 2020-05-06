public class Exercise1
{
	public static void main(String[] args)
	{
		Variable x=new Variable("x", 2.5);
		Variable y=new Variable("y", 4);
		ArithmeticExpression exp=new Sum(new SquareRoot(x), new Product(y, new Sum(x, y)));
		System.out.println(exp.asString());
		System.out.printf("%.3f\n", exp.asValue());
		x.set(5);
		System.out.printf("%.3f\n", exp.asValue());
	}
}
