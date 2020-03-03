//insertion sort
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
	for(int a=0;a<SIZE;a++){
		for(int b=0;b<a;b++){
			if(array[a] < array[b] ){
				int hold = array[a];
				for(int i=a-1;i>=b;i--)
					array[i+1] = array[i];
				array[b] = hold;
			}
			else
		    	continue;
		}
		printf("%.2f%%\r", 100*(float)a/(float)SIZE );
	}
	
	/*printf("After sorting:\n");
	for(int i=0;i<SIZE;i++)
		printf("%4d", array[i] );
	puts("");*/
	
	return 0;
}
