#include <stdio.h>
#include <math.h>

int main()
{
int tab[32], value=0, binar;

for(int i=0;i<=31;i++)
{
printf("Enter 0 or 1: ");
scanf("%d", &binar);
value=value+binar*pow(2, i);
printf("Current value is %d\n", value);
}
return 0;
}
