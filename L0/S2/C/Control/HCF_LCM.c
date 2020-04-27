#include <stdio.h>

int main()
{
	int a, b, BCD, SCD, i, j;

	scanf("%d %d", &a, &b);

	if(b>a && b%a == 0)
		printf("BCD is %d\nSCD is %d\n", b, a);
	else if(a>b && a%b == 0)
		printf("BCD is %d\nSCD is %d\n", a, b);
	else
	{
		if(a>b)
		{
			for(i=1;i<=a;i++)
			{
				if(a%i==0 && b%i==0)
				BCD=i;
			}
			printf("BCD: %d\n", BCD);				

			for(j=a;;j++)
			{
				if(j%a == 0 && j%b == 0)
				{
					SCD=j;
					printf("SCD: %d\n", SCD);
					break;
				}
			}	
		}

		if(a<b)
		{
			for(i=1;i<=b;i++)
			{
				if(b%i==0 && a%i == 0)
				BCD=i;
			}
			printf("BCD: %d\n", BCD);
			
			for(j=b;;j++)
			{
				if(j%a == 0 && j%b == 0)
				{
					SCD=j;
					printf("SCD: %d\n", SCD);
					break;
				}
			}		
		}
	}
	
	return 0;
}
