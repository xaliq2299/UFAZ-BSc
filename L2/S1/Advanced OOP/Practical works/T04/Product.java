public class Product extends BinaryOperator
{
        public Product(ArithmeticExpression x, ArithmeticExpression y)
        {
                super(x, y);
        }
        protected String label()
        {
                return "*";
        }
        protected double eval(double x, double y)
        {
                return x*y;
        }
}
