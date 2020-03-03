#include <stdio.h>

int main()
{
int A, J, counter;
float sqrt;
printf("Enter your number:\n");
scanf("%d %d", &A, &J);
sqrt=A;
for(counter=1;counter<=J;counter++)
{
sqrt=(sqrt+A/sqrt)/2;
printf("the %dth approximation of square root of %d is the %f\n", counter, A, sqrt);
}
}

