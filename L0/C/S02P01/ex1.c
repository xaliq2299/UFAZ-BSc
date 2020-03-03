#include <stdio.h>
#include <math.h>
#define PI 3.1415

int main()
{
	float r, A, P;
	printf("Enter the radius of the circle: ");
	scanf("%f", &r);
	A=PI*pow(r, 2);
	P=2*PI*r;
	printf("The Area of this circle is %.2f\n", A);
	printf("The Perimeter of this circle is %.2f\n", P);

return 0;
}
