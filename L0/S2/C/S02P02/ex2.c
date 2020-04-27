#include <stdio.h>
#include <math.h>

float value(float X);
float derivative1 (float X, float H);
float derivative2 (float X, float H);
void sign (float *second);

int main()
{
int choice;
float x, h, second;

printf("Let's consider this function: f(x)=(2x^3+3)(x^2-1)/sqrt(3x^2+1)\n\n");
printf("What do you want to find?\nDo your choice\n");
printf("1.f   2.first derivative   3.second derivative\n");
scanf("%d", &choice);
printf("\n*****************************************************\n\n");
switch(choice)
{
	case 1:  printf("Enter the value of x: ");
		 scanf("%f", &x); 
		 printf( "f(%f) = %f\n", x, value(x) );
		 break;
	case 2:  printf("Enter the value of x: ");
		 scanf("%f", &x);
		 printf("Enter also the value of h variable to calculate the derivative: ");
		 printf("(As extra info. h should be almost 0, too small)\n");			
		 scanf("%f", &h);
		 printf("f'(%f) = %f\n", x, derivative1(x, h) );
		 break;
	case 3:  printf("Enter the value of x: ");
		 scanf("%f", &x);
		 printf("Enter also the value of h variable to calculate the derivative: ");
		 printf("(As extra info. h should be almost 0, too small)\n");			
		 scanf("%f", &h);
		 second=derivative2(x, h);
		 printf("y''(%f)=%f\n", x, second );
		 sign(&second);
		 break;	
	default: printf("Please enter smth else\n");
             	 printf("What do you want to find?\nDo your choice\n");
		 printf("1.f   2.first derivative   3.second derivative\n");
}


return 0;
}

float value(float X)
{
	return ( (2*X*X*X+3)*(X*X-1)/sqrt(3*X*X+1) );
}

float derivative1 (float X, float H)
{
return ((value(X+H)-value(X-H))/2/H);
}

float derivative2 (float X, float H)
{
	float second;	
	second=((derivative1(X+H, H)-derivative1(X-H, H))/2/H);
	return second;
}

void sign(float *second)
{
	if(*second<0)
	printf("It is negative\n");
	else if (*second>0)
	printf("It is negative\n");
	else
	printf("It is zero\n");
}
