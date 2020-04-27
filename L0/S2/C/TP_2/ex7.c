#include <stdio.h>

int main()
{
int n;
float counter;
float term, sum=0;
printf("Enter your number:\n");
scanf("%d", &n);
for(counter=1;counter<=n;counter++)
{
term=1/counter;
sum=sum+term;
}
printf("The sum of Harmonic series is %f\n", sum);
return 0;
}

