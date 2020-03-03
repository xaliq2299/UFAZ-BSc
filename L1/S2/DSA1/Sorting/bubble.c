//bubble sort
#include <stdio.h>
#define SIZE 100000

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
	
	//algorithm
	for(int pass=1;pass<SIZE;pass++){
		for(int i=0;i<SIZE-1;i++){
			if(array[i]>array[i+1]){
				int hold=array[i];
				array[i]=array[i+1];
				array[i+1]=hold;
			}
		}
		printf("%3.2f%%\r", 100*(float)pass/((float)SIZE));
	}

	/*printf("After sorting:\n");
	for(int i=0;i<SIZE;i++)
		printf("%4d", array[i] );
	puts("");*/
	
	return 0;
}
