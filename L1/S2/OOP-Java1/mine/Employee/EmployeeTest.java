/*3.14 ( Employee Class) Create a class called Employee that includes three instance variables—a first
name (type String ), a last name (type String ) and a monthly salary ( double ). Provide a constructor
that initializes the three instance variables. Provide a set and a get method for each instance variable. If
the monthly salary is not positive, do not set its value. Write a test application named EmployeeTest
that demonstrates class Employee ’s capabilities. Create two Employee objects and display each object’s
yearly salary. Then give each Employee a 10% raise and display each Employee ’s yearly salary again.*/

public class EmployeeTest {
	public static void main (String[] args)
	{
		Employee employee1 = new Employee("Xaliq", "Agh", 80);
		Employee employee2 = new Employee("Fadi", "Lol", 100);
		
		System.out.printf("Employee1: %f\n", employee1.getEmployeeSalary() );
		System.out.printf("Employee2: %f\n", employee2.getEmployeeSalary() );
		
		double s1 = employee1.getEmployeeSalary();
		s1 = s1 + s1*0.1;
		employee1.setEmployeeSalary(s1);
		
		double s2 = employee2.getEmployeeSalary();
		s2 = s2 + s2*0.1;
		employee2.setEmployeeSalary(s2);
		
		//employee1.salary = employee1.salary + 0.1*employee1.salary;		 //wont work since private access modifier
		
		System.out.printf("Employee1: %f\n", employee1.getEmployeeSalary() );
		System.out.printf("Employee2: %f\n", employee2.getEmployeeSalary() );	
	}
}
