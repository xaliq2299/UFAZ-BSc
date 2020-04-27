#include <stdio.h>

int main()
{
	int number, sum=0;
		
	printf("Enter the numbers(CtrlD to terminate):\n");

		while(scanf("%d", &number)!=EOF)
		{
			if(number%2==0)			
			sum+=number;
		}
	
	printf("The sum of even numbers is %d\n", sum);

return 0;
}
