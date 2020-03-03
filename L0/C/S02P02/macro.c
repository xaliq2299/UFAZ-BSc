#include <stdio.h>
#include <math.h>
#define f(x) (2*x*x*x+3)*(x*x-1)/sqrt(3*x*x+1)

float value (float a);
float deriv (float a, float H);
float deriv2 (float a, float H);

int main()
{
	int choice;
	float x, h;

	printf("What do you want to find?\n");
	printf("1.f  2.first derivative  3.second derivative\n");
	scanf("%d", &choice);
	printf("Also enter the value of x variable: ");
	scanf("%f", &x);

	switch(choice)
	{
		case 1: printf("y(%f)=%f\n", x, value(x)); 
			break;
		case 2: printf("Enter the h value also:\n");
			scanf("%f", &h);
			printf("f'(%f)=%f\n", x, deriv(x, h));      
			break;
 		case 3: printf("Enter the h value also:\n");
			scanf("%f", &h);
			printf("f''(%f)=%f\n", x, deriv2(x, h));
			break;	
	}

return 0;
}

float value (float a)
{
	return f(a);
}


float deriv (float a, float H)
{
	return ( (f(a+H)-f(a-H))/(2*H) );  
}

float deriv2 (float a, float H)
{	
	return (deriv(a+H,H)-deriv(a-H,H))/(2*H);
}
