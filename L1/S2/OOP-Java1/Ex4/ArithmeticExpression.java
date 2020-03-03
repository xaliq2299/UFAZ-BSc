public interface ArithmeticExpression{
	public String asString();
	public double asValue();
}

class Variable implements ArithmeticExpression{
	private String var;
	private double val;
	Variable(String var, double val){
		this.var = var;
		this.val = val;
	}
	
	public String asString(){
		return this.var;
	}
	
	public double asValue(){
		return this.val;
	}
	
	public void set(double val){
		this.val = val;
	}
}

class Sum extends BinaryOperator implements ArithmeticExpression{
	//private ArithmeticExpression x, y; //do we need?
	Sum(ArithmeticExpression x, ArithmeticExpression y){
		super(x, y);
	}

	public String label(){
		return "+";
	}
	
	public double eval(double arg1, double arg2){
		return arg1+arg2;
	}
}

class Product extends BinaryOperator implements ArithmeticExpression {
	//private ArithmeticExpression x, y; //do we need?
	Product(ArithmeticExpression x, ArithmeticExpression y){
		super(x, y);
	}
	
	public String label(){
		return "*";
	}
	
	public double eval(double arg1, double arg2){
		return arg1*arg2;
	}
}

abstract class BinaryOperator{
	private ArithmeticExpression x, y;
	
	BinaryOperator(ArithmeticExpression x, ArithmeticExpression y){
		this.x = x; this.y = y;
	}
	
	public String asString(){
		return "("+this.x.asString()+this.label()+this.y.asString()+")";
	}

	public double asValue(){
		return eval(x.asValue(), y.asValue());
	}
		
	public abstract String label();
	public abstract double eval(double arg1, double arg2);
}
/*
class Division implements ArithmeticExpression{
	private ArithmeticExpression x, y;
	Division(ArithmeticExpression x, ArithmeticExpression y){
		this.x = x; this.y = y;
	}
	
	public String asString(){
		return "("+x.asString()+"/"+y.asString()+")";
	}
	
	public double asValue(){
		return x.asValue()/y.asValue();
	}
	
	public String label(){
		return "/";
	}
}

class Subtraction implements ArithmeticExpression{
	private ArithmeticExpression x, y;
	Subtraction(ArithmeticExpression x, ArithmeticExpression y){
		this.x = x; this.y = y;
	}
	
	public String asString(){
		return "("+x.asString()+"-"+y.asString()+")";
	}
	
	public double asValue(){
		return x.asValue()-y.asValue();
	}
	public String label(){
		return "-";
	}
}
*/
class Main{
	public static void main(String args[]){
		Variable x = new Variable("x", 2.5);
		Variable y = new Variable("y", 4);
		/*ArithmeticExpression exp = new Sum(x, new Product(y, new Sum(x, y)));
		System.out.println(exp.asString());
		System.out.println(exp.asValue());
		x.set(5);
		System.out.println(exp.asValue());		
		*/
		ArithmeticExpression exp = new Sum(x, y);
		System.out.println(exp.asString());
		System.out.println(exp.asValue());
	}
}
