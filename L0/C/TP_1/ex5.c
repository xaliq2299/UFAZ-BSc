#include <stdio.h>

int main() {
int numb, sum=0, n=0;
float average;

while (1)
{
printf("Enter the number:\n");
scanf("%d", &numb);
if(numb!=-1)
{
sum=sum+numb;
n=n+1;
}
else
break;
}

average=sum/n;
printf("Average is %f\n", average);
return 0;
}
