#include <stdio.h>
#include <math.h>
#define EPS 0.000001

float dicho(float a, float b){
	float m=(a+b)/2;
	
	if(b-a < EPS)		 return m;
	else if(sin(m) > 0)  dicho(m, b);
	else if(sin(m) < 0)  dicho(a, m);	
}
	
int main(){
	int a=3, b=4;
	printf("sin(x)=0\nx=%f\n", dicho(a, b) );
	return 0;
}
