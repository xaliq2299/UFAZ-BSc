#include <stdio.h>

struct fraction{
	int numer;
	int denom;
};

int main()
{
	struct fraction fraction1, fraction2; 
	int a, small, EKQ, numer;
	
	printf("Fraction number 1 --> ");
	printf("Numerator and denominator: ");

	scanf("%d %d", &fraction1.numer, &fraction1.denom);
	 
	printf("Fraction number 2 --> ");
	printf("Numerator and denominator: ");

	scanf("%d %d", &fraction2.numer, &fraction2.denom);
	
	//Step of finding the common denominator 
	for(a=1;;a++)
	{
		if(a%fraction1.denom==0 && a%fraction2.denom==0)
		{
		EKQ=a;
		break;
		}		
	}
	
	numer=EKQ/fraction1.denom*fraction1.numer+EKQ/fraction2.denom*fraction2.numer;	
	printf("%d/%d + %d/%d = %d/%d=%f\n", fraction1.numer, fraction1.denom, fraction2.numer, fraction2.denom, numer, EKQ, (float)numer/EKQ); 

return 0;
}
