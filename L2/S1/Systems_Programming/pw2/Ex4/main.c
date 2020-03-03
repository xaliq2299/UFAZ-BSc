#include <stdio.h>
#include "pi.h"

float perimeter(float r);
float area(float r);

int main(){
	float radius;
	printf("Radius: ");
	scanf("%f", &radius);
	printf("%.3f\n", perimeter(radius) );
	printf("%.3f\n", area(radius));
	
	return 0;
}