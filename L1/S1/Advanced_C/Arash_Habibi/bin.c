#include <stdio.h>

int main()
{
	int i=0;
	
	while(i>>=1)
		i++;
	printf("%d\n", i);
	return i;
}
