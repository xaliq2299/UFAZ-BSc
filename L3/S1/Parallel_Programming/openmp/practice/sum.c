#include <stdio.h>

int main(){
	int array[100];
	for (int i=0;i<100;i++)
		array[i]=i;
	int sum=0;
	//#pragma omp parallel for reduction(+:sum)
		for (int i=0;i<100;i++)
		sum += array[i];

	printf("%d = \n", sum);
	return 0;
}