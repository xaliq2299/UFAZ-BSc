#include <stdio.h>
#define SIZE 500

int get_prime(int num)
{
	int check, a, b;

	for(a=2;;a++)
	{
		check=0;
		for(b=1;b<=a;b++)
		{
			if(a%b==0)
			check++;
		}

		if(check == 2 && num%a==0)
		return a;
	}
}


int main()
{
	int array[SIZE]={0};
	
	int num, divisor, a;
	int ND=1;//Number of Divisors

	scanf("%d", &num);

	printf("%d=", num);

	while(num!=1)
	{
		divisor=get_prime(num);
		
		if(num/divisor!=1)		
			printf("%d*", divisor );
		else
			printf("%d\n", divisor);
		
		array[divisor]+=1;

		num/=divisor;		
	}

	for(a=2;a<SIZE;a++)
	{
		if(array[a]!=0)
		ND*=(array[a]+1);
	}

	printf("Number of Divisors: %d\n", ND);
	
	return 0;
}
