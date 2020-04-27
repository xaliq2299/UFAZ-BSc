#include <stdio.h>

int main()
{
	int row, a, b, c;
	
	printf("Enter the side: ");
	scanf("%d", &row);

	for(a=1;a<=row;a++)
	{
		for(b=1;b<=row-a;b++)//space
		printf(" ");	
		for(c=1;c<=2*a-1;c++)//printing *
		printf("*");
		
		puts("");	
	}

return 0;
}
