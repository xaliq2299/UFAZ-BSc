#include <stdio.h>

int divide(float a, float b, float *q){
	if(b == 0){
		printf("Division by zero!\n");
		return 0;
	}
	else
		*q = a/b;
	return 1;
}

int firstDegreeEquation(float a, float b, float *solution){
	if(a == 0 && b == 0){
		printf("Infinite solution: Everything\n");
		return 2;
	}
	else if(a == 0){
		printf("No solution\n");	
		return 0;
	}
	else
		*solution = (-b/a);
	return 1;
}

int main(){
	float ans;
	if(divide(365, 5, &ans))
		printf("%f\n", ans );	
	if(firstDegreeEquation(0,0,&ans) == 1)
		printf("%f\n", ans);

	return 0;
}
