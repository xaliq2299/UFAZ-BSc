#include <stdio.h>
#include <math.h>

int print_stars(int i, int j);

int main()
{
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=50;j++)
			print_stars(i, j);
		puts("");
	}	

	return 0;
}

int print_stars(int i, int j)
{
	if(sqrt(pow(i-10, 2)+pow(j-25, 2)/5)<=8)
	{
		printf("*");
		return 1;
	}
	else
		printf(" ");
		return 0;
}
