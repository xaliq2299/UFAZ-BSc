public class Subtraction implements ArithmeticExpression
{
	ArithmeticExpression x, y;
        public Subtraction(ArithmeticExpression x, ArithmeticExpression y)
        {
                this.x=x;
                this.y=y;
        }
        public String asString()
        {
                return "("+x.asString()+"-"+y.asString()+")";
        }
        public double asValue()
        {
                return x.asValue()-y.asValue();
        }
}
