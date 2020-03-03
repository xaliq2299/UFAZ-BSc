/*3.14 ( Employee Class) Create a class called Employee that includes three instance variables—a first
name (type String ), a last name (type String ) and a monthly salary ( double ). Provide a constructor
that initializes the three instance variables. Provide a set and a get method for each instance variable. If
the monthly salary is not positive, do not set its value. Write a test application named EmployeeTest
that demonstrates class Employee ’s capabilities. Create two Employee objects and display each object’s
yearly salary. Then give each Employee a 10% raise and display each Employee ’s yearly salary again.*/

public class Employee {
	private String name;
	private String last_name;
	private double salary;
	
	public Employee (String n, String l, float s)
	{
		name = n;
		last_name = l;
		salary = s;
	}
	
	public void setEmployeeName ( String n )
	{
		name = n;
	}
	
	public String getEmployeeName ()
	{
		return name;
	}
	
	public void setEmployeeLastName ( String l )
	{
		last_name = l;
	}
	
	public String getEmployeeLastName ()
	{
		return last_name;
	}
	
	public void setEmployeeSalary( double s )
	{
		if ( s > 0.0 )
		    salary = s;
	}
	
	public double getEmployeeSalary ()
	{
		return salary;
	}
}
