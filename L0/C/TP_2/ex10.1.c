#include <stdio.h>

int main()
{
	int A, J, a;
	float square;

	printf("Enter the number: ");
	scanf("%d", &A);

	printf("Dear user, enter also the approximation: ");
	scanf("%d", &J);
	square=A;
	
	for(a=1;a<=J;a++)
		square=(square+(float)A/square)/2;

	printf("The square root of %d is %f\n", A, square);
	
return 0;
}
