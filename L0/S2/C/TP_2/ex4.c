#include <stdio.h>
#include <math.h>

long factorial();

int main() {
int n, a=1, p=1, x;
double sum=0;

printf("Enter your number:\n");
scanf("%d", &x);
printf("Dear user, pls enter also the precision");
printf("(until to which value you want to find this limit):\n");
scanf("%d", &n);

while(a<=n)
{
	if(a%2==0)
	   sum=sum-pow(x,p)/factorial(p);
	else
	   sum=sum+pow(x,p)/factorial(p);
	p+=2;
	a++;
}
printf("%lf\n", sum);
return 0;
}

long factorial(int p)
{
	if(p==0)
	  return 1;
	else if(p==1)
       	  return 1;
	else
          return (p*factorial(p-1));
}

