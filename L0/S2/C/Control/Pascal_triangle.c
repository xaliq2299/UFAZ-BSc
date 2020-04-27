#include <stdio.h>

long factorial(unsigned int numb)
{
	int prod=1, a;

	for(a=1;a<=numb;a++)
		prod*=a;
	return prod;
}

int main()
{
	int row, blank, a, counter, term;
	printf("enter the row: ");
	scanf("%d", &row);

	blank=row-1;
	for(a=0;a<row;a++)
	{
		for(counter=1;counter<=blank;counter++)
			printf(" ");
		for(term=0;term<=a;term++)
			printf("%li ", factorial(a)/factorial(term)/factorial(a-term) );
		puts("");
		blank--;
	}

	return 0;
}
