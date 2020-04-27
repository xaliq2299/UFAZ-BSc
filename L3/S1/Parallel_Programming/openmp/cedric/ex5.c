#include <stdio.h>
#include <omp.h>

int main(){
	int i=42;

	#pragma omp parallel private(i) /// no link with the original variable just the name is the same
	{
		int j;
		printf("Hello, world %d\n", i);
	}

	// printf("Hello, world %d\n", i);
	return 0;
}