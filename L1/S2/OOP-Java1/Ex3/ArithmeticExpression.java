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

class Sum implements ArithmeticExpression{
	private ArithmeticExpression x, y;
	Sum(ArithmeticExpression x, ArithmeticExpression y){
		this.x = x; this.y = y;
	}

	public String asString(){
		return "("+this.x.asString()+"+"+this.y.asString()+")";	
	}
	
	public double asValue(){
		return this.x.asValue()+this.y.asValue();
	}
}

class Product implements ArithmeticExpression {
	private ArithmeticExpression x, y;
	Product(ArithmeticExpression x, ArithmeticExpression y){
		this.x = x; this.y = y;
	}
	
	public String asString(){
		return "("+this.x.asString()+"*"+this.y.asString()+")";	
	}
	
	public double asValue(){
		return this.x.asValue()*this.y.asValue();
	}
}

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
}

class Main{
	public static void main(String args[]){
		Variable x = new Variable("x", 2.5);
		Variable y = new Variable("y", 4);
		ArithmeticExpression exp = new Sum(x, new Product(y, new Sum(x, y)));
		System.out.println(exp.asString());
		System.out.println(exp.asValue());
		x.set(5);
		System.out.println(exp.asValue());		
	}
}
