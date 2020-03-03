#include <stdio.h>

int get_prime(int);

int main()
{
	int num, divisor;

	scanf("%d", &num);

	printf("%d=", num);

	while(num!=1)
	{
		divisor=get_prime(num);
		
		if(num/divisor!=1)		
			printf("%d*", divisor );
		else
			printf("%d\n", divisor);
		
		num/=divisor;		
	}

	return 0;
}


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
