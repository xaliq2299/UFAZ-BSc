public class SquareRoot extends UnaryOperator
{
	public SquareRoot(ArithmeticExpression x)
	{
		super(x);
	}
	public String asString()
	{
		return "V"+x.asString()+"'";
	}
	protected double eval(double x)
	{
		return Math.sqrt(x);
	}
}
