#include <stdio.h>

void main()
{
int n;

printf("Enter any digit between 0 and 9: \n");
scanf("%d", &n);

switch(n)
{
case 0:printf("zero\n");break;
case 1:printf("one\n");break;
case 2:printf("two\n");break;
case 3:n==3;printf("three\n");break;
case 4:n==4;printf("four\n");break;
case 5:n==5;printf("five\n");break;
case 6:n==6;printf("six\n");break;
case 7:n==7;printf("seven\n");break;
case 8:n==8;printf("eight\n");break;
case 9:n==9;printf("nine\n");break;
default:printf("this is not a digit\n");break;
}
}














