#include <stdio.h>

void main()
{
int SIZE, pos=0, neg=0;
printf("Size:");
scanf("%d", &SIZE);
printf("\n");
int ar[SIZE];
for(int a=0;a<SIZE;a++)
{
printf("Enter number %d:\n", a+1);
scanf("%d", &ar[a]);

if(ar[a]>0)
	pos++;
else if(ar[a]<0)
	neg++;
else
	pos=pos;
	neg=neg;
}

printf("The number of positive numbers you entered is %d\n", pos);
printf("The number of negative numbers you entered is %d\n", neg);
}
