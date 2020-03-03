#include <stdio.h>

int main()
{
	int n;

	printf("1.OR(|)\n2.AND(&)\n3.XOR(^)\n");	
	printf("Which operation?\n");
		
	scanf("%d", &n);

	switch(n)
	{
		case 1: printf("\t0\t1\n"
		       "0\t0\t1\n"
		       "1\t1\t1\n");
			break;
		case 2: printf("\t0\t1\n"
		       "0\t0\t0\n"
		       "1\t0\t1\n");
			break;
	        case 3:	printf("\t0\t1\n"
		       "0\t0\t1\n"
		       "1\t1\t0\n");
			break;
		default: printf("Please, enter smth available\n");
			 break;
	}
return 0;
}
