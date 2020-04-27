#include <stdio.h>
#define SIZE 12

void read_integers(int size, int tab[size]);
void sort_integers(int size, int tab[size]);
int dichotomy(int size, int tab[size], int a);


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
	
	printf("Enter the number to search: ");
	scanf("%d", &a);
	dichotomy(SIZE, array, a);
	
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


int dichotomy(int size, int tab[size], int a)
{
	int i, imin=0, imax=size-1;

	while(imin<=imax)
	{
		i=(imin+imax)/2;
		if(tab[i]==a)
		{
			printf("%d exists in the table\n", a);
			return 1;
		}
		else if(tab[i]>a)
			imax=i-1;
		else
			imin=i+1;		
	}

	printf("%d does not exist in the table\n", a);
	return 0;
}
