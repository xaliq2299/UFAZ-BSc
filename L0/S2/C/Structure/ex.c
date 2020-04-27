//learning structures
#include <stdio.h>

int main()
{
	struct employee
	{
		char firstName[ 20 ];
		char lastName[ 20 ];		
		int age;
		char gender;
		double hourlySalary; 
		struct employee person; //ERROR
		struct employee *ePtr; //it is possible to put pointers inside the structure
	};
struct employee ar; //means there will be created ar variable of each type that is inside the structure

return 0;
}
