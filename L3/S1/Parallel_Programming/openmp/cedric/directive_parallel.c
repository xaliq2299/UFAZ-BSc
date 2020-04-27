#include <stdio.h>
#include <omp.h>

int main(){
	#pragma omp parallel num_threads(100) // if we dont specify, by default it si number of logical cores
	{
		printf("Hello, %d\n", omp_get_thread_num());
		printf("world, %d\n", omp_get_thread_num());
	}
	return 0;
}