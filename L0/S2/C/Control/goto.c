#include <stdio.h>

int main()
{
int n;
printf("Enter positive number: ");
scanf("%d", &n);

if(n<=0)
{
goto error;
error: printf("enter smth positive!\n");
}
return 0;
}
