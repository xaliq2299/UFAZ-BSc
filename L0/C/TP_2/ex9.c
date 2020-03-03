#include <stdio.h>

int main() 
{
int n, counter, a;
printf("Enter an integer:\n");
scanf("%d", &n);
for(counter=1;counter<=10;counter++)
{
a=counter*n;
printf("%d x %d = %d\n", n, counter, a); 
}
return 0;
}
