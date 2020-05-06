public class Division extends BinaryOperator
{
        public Division(ArithmeticExpression x, ArithmeticExpression y)
        {
                super(x, y);
        }
        protected String label()
        {
                return "/";
        }
        protected double eval(double x, double y)
        {
                return x/y;
        }
}
