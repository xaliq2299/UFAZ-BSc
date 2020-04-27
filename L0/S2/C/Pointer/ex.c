#include <stdio.h>

int main()
{
	double tab[5];
	
	printf("%p\n", tab);
	printf("%p\n", &tab[0] );

	printf("%p\n", &tab[1] );
	printf("%p\n", tab+1);
	
	
	return 0;
}
