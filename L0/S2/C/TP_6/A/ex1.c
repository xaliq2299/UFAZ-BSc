//it is impossible to code this problem using function, but managed to do it with structure (P.S: It is possible without function) 
#include <stdio.h>

	typedef struct {	
		int x, y;
	}Numbers;

Numbers exchange(Numbers Struct);

int main()
{
	Numbers numbers, Struct;

	printf("Enter two numbers: ");
	scanf("%d%d", &numbers.x, &numbers.y);
	
	printf("x=%d, y=%d\n", numbers.x, numbers.y);

	Struct=exchange(numbers);
	
	printf("x=%d, y=%d\n", Struct.x, Struct.y);

return 0;
}


Numbers exchange(Numbers Struct)
{	
	int hold;

	hold=Struct.x;
	Struct.x=Struct.y;
	Struct.y=hold;
	
	return Struct;
}
