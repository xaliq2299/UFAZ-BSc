/*Fig 6.18: fig06_18.c
Linear Search*/
#include <stdio.h>
#define SIZE 100
int linearSearch(const int array[],int key, int size);
int main(void){
	int a[SIZE], x, searchKey, element;
	for(x=0;x<SIZE;x++)
		a[x]=2*x;
	printf("Enter integer search key:\n");
	scanf("%d",&searchKey);
	element =linearSearch(a,searchKey,SIZE);
	if (element !=-1){
		printf("Fouund value in element %d\n",element);
	}
	else{
		printf("Value not found");
	}
	return 0;
}

int linearSearch(const int array[], int key,int size){
	int n;
	for(n=0;n<SIZE;++n){
		if (array[n]==key){
			return n;
		}
	}
	return -1;
}