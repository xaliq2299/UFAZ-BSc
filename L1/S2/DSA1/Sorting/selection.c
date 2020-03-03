//selection sort
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
	for(int i=0;i<SIZE;i++){
		int small=array[i];
		for(int j=i+1;j<SIZE;j++){
			if(array[j]<small){
			   	int hold=small;	
				small=array[j];
				array[j]=hold;			
			}
		}
		array[i]=small;
		printf("%3.2f%%\r", 100*(float)i/((float)SIZE));
	}

	/*printf("After sorting:\n");
	for(i=0;i<SIZE;i++)
		printf("%4d", array[i] );
	puts("");*/

	return 0;	
}
