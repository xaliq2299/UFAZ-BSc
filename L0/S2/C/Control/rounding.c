#include <stdio.h>
#include <math.h>

void main() 
{
	float num;
	int num1, num2, rnd;

	printf("Enter the number: ");
	scanf("%f", &num);

	printf("Round off to: ");
	scanf("%d", &rnd);

	num1=(int)num;
	num2=((int)(num*(int)pow(10,rnd))%(int)(pow(10,rnd)));
	printf("\n%d.%d\n", num1, num2);
}
