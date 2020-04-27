#include <stdio.h>

long factorial (int n);

int main()
{
	int choice, numb, numb1, numb2, hold;
	long result;
	
	printf("Which operation do you want to perform?\n");
	printf("1.Permutation   2.Aranjeman   3.Combination\n");
	scanf("%d", &choice);
	
	switch (choice)
	{
		case 1: printf("Enter your number: ");
			scanf("%d", &numb);
			result=factorial(numb);
			printf("%d!=%ld\n", numb, result);			
			break;		
		case 2: printf("Enter the numbers: ");
			scanf("%d%d", &numb1, &numb2);
			if(numb1<numb2)
			{
				hold=numb1;
				numb1=numb2;
				numb2=hold;
			}			
			result=factorial(numb1)/factorial(numb1-numb2);
			printf("%dP%d=%ld\n", numb1, numb2, result);			
			break;		
		case 3: printf("Enter the numbers: ");
			scanf("%d%d", &numb1, &numb2);
			if(numb1<numb2)
			{
				hold=numb1;
				numb1=numb2;
				numb2=hold;
			}			
			result=factorial(numb1)/factorial(numb1-numb2);	
			printf("%dC%d=%ld\n", numb1, numb2, result);
			break;
		default: printf("You entered smth strange\n");	
	}

return 0;
}

long factorial (int n)
{
	long a, result=1;	
	for(a=1;a<=n;a++)
	result*=a;
	return result;
}
