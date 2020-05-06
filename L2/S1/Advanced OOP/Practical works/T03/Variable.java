public class Variable implements ArithmeticExpression
{
        private double value;
        private String name;
        public Variable(String name, double value)
        {
                this.name=new String(name);
        	this.value=value;
        }
        public String asString()
        {
        	return new String(name);
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
