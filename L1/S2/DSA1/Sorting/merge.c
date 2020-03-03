//merge sort
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

int* merge(int *array, int l, int m, int r){
	int *temp = (int*)calloc(r-l+1, sizeof(int));
	int i=0, iPivot1=l, iPivot2=m+1;
	int pivot1 = array[iPivot1], pivot2 = array[iPivot2];
	while(i<r-l+1){
		if(pivot1 < pivot2){
			if(iPivot1 != m){
				temp[i++] = pivot1;
				pivot1 = array[++iPivot1];
			}
			else{
				temp[i++] = pivot1;
				for(int j=iPivot2;j<=r;j++)
					temp[i++] = array[j];
				break;
			}
		}
		else{
			if(iPivot2 != r){
				temp[i++] = pivot2;
				pivot2 = array[++iPivot2];
			}
			else{
				temp[i++] = pivot2;
				for(int j=iPivot1;j<=m;j++)
					temp[i++] = array[j];
				break;
			}
		}
	}
	return temp;
}

void divide(int *array, int l, int r){
	//int m;
	if(r == l) 	return;
	if(r-1 == l){
		if(array[l] > array[r]){
			int hold = array[l];
			array[l] = array[r];
			array[r] = hold;
		}
	}
	else{
		int m = (l+r)/2;
		divide(array, l, m);
		divide(array, m+1, r);
		int *temp = merge(array, l, m, r);
		for(int i=0,j=l;j<r+1;i++,j++)
			array[j] = temp[i];
	}
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
		
	//algorithm
	divide(array, 0, SIZE-1);
	
	/*printf("After sorting:\n");
	for(int i=0;i<SIZE;i++)
		printf("%4d", array[i] );
	puts("");*/
	
	return 0;
}
