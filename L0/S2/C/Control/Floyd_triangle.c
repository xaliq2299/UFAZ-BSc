#include <stdio.h>

void main()
{
	int row, rows, a=1, i;

	scanf("%d", &rows);
	
	for(row=1;row<=rows;row++)
	{
		for(i=1;i<row;i++)
		{
			printf("%4d", a);
			a++;
		}
		puts("");
	}
}
