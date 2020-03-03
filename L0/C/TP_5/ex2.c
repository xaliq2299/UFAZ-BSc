#include <stdio.h>
#define SIZE 12

void read_integers(int size, int tab[size]);
void sort_integers(int size, int tab[size]);


int main()
{
	int array[SIZE], a, b;
	
	read_integers(SIZE, array);
	
	printf("Numbers before sorting:\n");
	for(b=0;b<SIZE;b++)
		printf("%4d", array[b] );
	puts("");

	
	sort_integers(SIZE, array);
	
	printf("Numbers after sorting in ascending order:\n");
	for(b=0;b<SIZE;b++)
		printf("%4d", array[b] );
	puts("");
	
	return 0;
}


void read_integers(int size, int tab[size])
{
	for(int a=0;a<size;a++)
	{
		printf("Enter number %d: ", a+1);
		scanf("%d", &tab[a] );
	}
}

void sort_integers(int size, int tab[size])
{
	int pass, hold, a;

	for(pass=1;pass<size;pass++)
	{
		for(a=0;a<size-1;a++)
		{
			if(tab[a]>tab[a+1])
			{
				hold=tab[a];
				tab[a]=tab[a+1];
				tab[a+1]=hold;
			}
		}
	}
}
