public class Sum implements ArithmeticExpression
{
	private ArithmeticExpression x, y;
        public Sum(ArithmeticExpression x, ArithmeticExpression y)
        {
        	this.x=x;
                this.y=y;
        }
	public String asString()
        {
                return "("+x.asString()+"+"+y.asString()+")";
        }
        public double asValue()
        {
                return x.asValue()+y.asValue();
        }
}
