#include <stdio.h>

int divide(float a, float b, float *q){
	if(b == 0)
		return 0;
	else
		*q = a/b;
	return 1;
}

int main(){
	float q;
	divide(365,5,&q);
	printf("%f\n", q);
	
	return 0;
}
