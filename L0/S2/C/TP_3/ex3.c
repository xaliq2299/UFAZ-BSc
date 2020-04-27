#include <stdio.h>

int main()
{
	unsigned choice1, choice2, choice3, choice4;
	
	printf("Quadruped:\n"); 
	printf("1)Breastfeeding    2)Talk\n");
	printf("Which one? ");
	scanf("%u", &choice1);

	switch(choice1)
	{
		case 1: printf("1)mammal   2)crocodile\n");
			printf("Which one? ");
			scanf("%u", &choice2);
			
			switch(choice2)
			{
				case 1: printf("For mammal the code is 1\n"); break;
				case 2: printf("For crocodile the code is 2\n"); break;
				default: printf("You entered smth else\n"); break;
			}
			
			break;
		case 2: printf("1)Human    2)Wings\n");
			printf("Which one? ");
			scanf("%u", &choice3);

			switch(choice3)
			{
				case 1: printf("For Human the code is 3\n"); break;
				case 2: printf("1)Bird    2)fish\n");
					printf("Which one? ");
					scanf("%u", &choice4);

					if(choice4 == 1)
					printf("For bird the code is 4\n");
					else if (choice4 == 2)
					printf("For fish the code is 5\n");
					else
					printf("You entered smth else\n");
					break;				
					default: printf("You entered smth else\n"); break;
			}
			break;
		default: printf("You entered smth else\n"); break;
	}

return 0;
}
