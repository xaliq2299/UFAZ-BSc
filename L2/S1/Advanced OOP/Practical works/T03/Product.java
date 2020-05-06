public class Product implements ArithmeticExpression
{
	private ArithmeticExpression x, y;
        public Product(ArithmeticExpression x, ArithmeticExpression y)
        {
        	this.x=x;
                this.y=y;
        }
	public String asString()
        {
                return "("+x.asString()+"*"+y.asString()+")";
        }
        public double asValue()
        {
                return x.asValue()*y.asValue();
        }
}
