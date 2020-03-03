#include <stdio.h>
#include <stdlib.h>

int main()
{
	char string[10];
	
	scanf("%s", string);
	int counter = 0;
	
	for(int a=0;string[a]!='\0';a++)
	{
		if(string[a] == '(')
			counter++;
		else
			counter--;
	
		if(counter<0)
		{
			printf("False\n");
			exit(0);		
		}
	}
	
	printf("True\n");

	return 0;
}
