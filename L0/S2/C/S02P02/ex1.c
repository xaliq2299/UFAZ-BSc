#include <stdio.h>

int main()
{
int evenodd(int number);
void prime(int n);
int numb1, numb2, number, n, i=0;
char string[50];
printf("Enter two integers: ");
scanf("%d%d", &numb1, &numb2);
printf("Integer part of the result of division: %d\n", numb1/numb2);
printf("Decimal part of the result of division: %f\n", (float)numb1/numb2-numb1/numb2);
number=numb1/numb2;
printf("\"Even or odd number part\" I did for the integer part of the result of division. So:\n");
evenodd(number);
printf("Enter a positive integer: ");
scanf("%d", &n);
prime(n);
printf("Now enter any string: ");
scanf("%s", string);

while(string[i]!='\0')
i++;

while(i>=0)
{
printf("%c", string[i]);
i--;
}
puts("");

return 0;
}

int evenodd(int number)
{
if(number%2==0)
printf("This number is even\n");
else
printf("This number is odd\n");

return 0;
}


void prime(int n)
{
int counter, check=0;
for(counter=1;counter<=n;counter++)
{
	if(n%counter==0)
	check=check+1;
}
if(check==2)	
printf("%d is prime\n", n);
else if(check==1)	
printf("This number is 1\n");
else
printf("%d is not a prime number\n", n);
}
