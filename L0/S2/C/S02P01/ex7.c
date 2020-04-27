#include <stdio.h>

void Prime(int A, int B);
int main()
{
int low, high, temp;
printf("Enter two numbers(intervals):");
scanf("%d %d", &low, &high);

if(low>high)
{
	temp=low;
	low=high;
	high=temp;
}
printf("Prime numbers between %d and %d are:\n", low, high);
Prime(low, high);

return 0;
}

void Prime(int A, int B){
int check;
for(A+1;A<B;A++)
{
	check=0;
	for(int c=1;c<=A+1;c++)
	{
		if((A+1)%c==0)
		check=check+1;
	}		
	if(check==2)
	printf("%d\n", A+1);					
}
}
