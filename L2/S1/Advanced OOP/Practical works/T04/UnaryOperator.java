public abstract class UnaryOperator implements ArithmeticExpression
{
	ArithmeticExpression x;
        public UnaryOperator(ArithmeticExpression x)
        {
                this.x=x;
        }
        public abstract String asString();
        public double asValue()
        {
                return eval(x.asValue());
        }
        protected abstract double eval(double x);
}
