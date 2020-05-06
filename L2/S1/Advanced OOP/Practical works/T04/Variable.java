public class Variable implements ArithmeticExpression
{
	private double value;
	private String label;
	public Variable(String label, double value)
	{
		this.label=new String(label);
		this.value=value;
	}
	public String asString()
	{
		return label;
	}
	public double asValue()
	{
		return value;
	}
	public void set(double value)
	{
		this.value=value;
	}
}
