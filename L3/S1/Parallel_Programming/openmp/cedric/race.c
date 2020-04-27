#include <stdio.h>
#define MAX 10000

int main(){
	size_t i;
	int n=0;
	
	#pragma omp parallel for 
	for(i=0;i<MAX;i++){
		#pragma omp atomic
		n++;
	}	
	
	printf("n = %d\n", n);
	return 0;
}