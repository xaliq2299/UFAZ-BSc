#include <stdio.h>

int main()
{
	unsigned code;
	printf("Enter the code of animal (from 1 to 5):");
	scanf("%u", &code);
	
	switch(code)
	{
		case 1: printf("mammal\n"); break;
		case 2: printf("crocodile\n"); break;
		case 3: printf("human\n"); break;
		case 4: printf("bird\n"); break;
		case 5: printf("fish\n"); break;
		default: printf("No type of animal\n"); break;
	}

return 0;
}
