//quicksort
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

int cmpfunc ( const void *a, const void *b){
	return ( *(int*)a - *(int*)b );
}

int main(){
	int array[SIZE];
	FILE *fp = fopen("numbers.txt", "r");
	for(int i=0;i<SIZE;i++)
		fscanf(fp, "%d", &array[i]);
	fclose(fp);
	
	/*printf("Before sorting:\n");
	for(int i=0;i<SIZE;i++)
		printf("%4d", array[i] );
	puts("");*/

	//algorithm(is already defined in C)
	qsort(array, SIZE, sizeof(int), cmpfunc);
	
	/*printf("After sorting:\n");
	for(int i=0;i<SIZE;i++)
		printf("%4d", array[i] );
	puts("");*/
	
	return 0;
}
