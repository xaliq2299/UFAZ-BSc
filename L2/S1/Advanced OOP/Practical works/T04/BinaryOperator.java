public abstract class BinaryOperator implements ArithmeticExpression
{
	ArithmeticExpression x, y;
	public BinaryOperator(ArithmeticExpression x, ArithmeticExpression y)
	{
		this.x=x;
		this.y=y;
	}
	public String asString()
	{
		return "("+x.asString()+label()+y.asString()+")";
	}
	public double asValue()
	{
		return eval(x.asValue(), y.asValue());
	}
	protected abstract String label();
	protected abstract double eval(double x, double y);
}
