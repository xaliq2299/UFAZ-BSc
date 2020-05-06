public class Division implements ArithmeticExpression
{
	private ArithmeticExpression x, y;
        public Division(ArithmeticExpression x, ArithmeticExpression y)
        {
        	this.x=x;
                this.y=y;
        }
        public String asString()
        {
                return "("+x.asString()+"/"+y.asString()+")";
        }
	public double asValue()
        {
                return x.asValue()/y.asValue();
        }
}
