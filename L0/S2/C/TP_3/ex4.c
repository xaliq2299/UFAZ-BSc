#include <stdio.h>

int main()
{
	unsigned choice, choice1, choice2, choice3, choice4, choice5;
	
	printf("1)From the list    2)Diagnostic approach\n");	
	printf("Using which approach you want to select animal: ");	
	scanf("%u", &choice);	

	switch(choice)
	{
		case 1: printf("1.mammal\n2.crocodile\n3.human\n4.bird\n5.fish\n");
			printf("Which one? ");
			scanf("%u", &choice1);	
			switch(choice1)
			{
				case 1: printf("You chose mammal\n"); break;
				case 2: printf("You chose crocodile\n"); break;
				case 3: printf("You chose human\n"); break;
				case 4: printf("You chose bird\n"); break;
				case 5: printf("You chose fish\n"); break;
				default: printf("You entered smth else\n"); break;			
			}
			break;
	
		case 2: printf("Quadruped:\n"); 
			printf("1)Breastfeeding    2)Talk\n");
			printf("Which one? ");
			scanf("%u", &choice2);
	
			switch(choice2)
			{
				case 1: printf("1)mammal   2)crocodile\n");
					printf("Which one? ");
					scanf("%u", &choice3);
				
					switch(choice3)
					{
						case 1: printf("You chose mammal\n"); break;
						case 2: printf("You chose crocodile\n"); break;
						default: printf("You entered smth else\n"); break;
					}
				
					break;
				case 2: printf("1)Human    2)Wings\n");
					printf("Which one? ");
					scanf("%u", &choice4);
	
					switch(choice4)
					{
						case 1: printf("You chose Human\n"); break;
						case 2: printf("1)Bird    2)fish\n");
							printf("Which one? ");
							scanf("%u", &choice5);
	
							if(choice5 == 1)
							printf("You chose Bird\n");
							else if (choice5 == 2)
							printf("You entered fish\n");
							else
							printf("You entered smth else\n");
							break;				
						default: printf("You entered smth else\n"); break;
					}
					break;
				default: printf("You entered smth else\n"); break;
			}
			break;
		default: printf("You entered smth else\n"); break;	
	}

return 0;	
}
