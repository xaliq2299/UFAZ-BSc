#include <stdio.h>

int main()
{
	unsigned choice;
	
	printf("1)mammal\n"
	       "2)crocodile\n"
	       "3)human\n"
	       "4)bird\n"
	       "5)fish\n");

	printf("Enter one of the animals in the list: ");
	scanf("%u", &choice);

	switch(choice)
	{
		case 1: printf("Code is 1\n"); break;
		case 2: printf("Code is 2\n"); break;
		case 3: printf("Code is 3\n"); break;
		case 4: printf("Code is 4\n"); break;
		case 5: printf("Code is 5\n"); break;
		default: printf("This is not animal from the list\n"); break;
	}

return 0;
}
