#include <stdio.h>

void printstar()
{
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=50;j++)
			printf("*");
		printf("\n");
	}

}

int main()
{
	printstar();

	return 0;
}
