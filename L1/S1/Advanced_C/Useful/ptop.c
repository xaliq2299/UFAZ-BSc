//pointer to pointer
#include <stdio.h>
#include <stdlib.h>

void func(int**foo)
{
	*foo = (int*)calloc(5,sizeof(int));  
}

int main()
{   
	int*array = NULL;
	func(&array);
	printf("array=%p\n", array);

	return 0;
}
