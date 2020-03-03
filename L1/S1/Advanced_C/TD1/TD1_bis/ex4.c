#include <stdio.h>

void printArray(int arr[], int nb){
	for(int i=0;i<nb;i++)
		printf("%4d", arr[i]);
	printf("\n");
}

void initialize(int arr[], int nb){
	for(int i=0;i<nb;i++)
		arr[i] = 0;
}

void input(int arr[], int nb){
	for(int i=0;i<nb;i++)
		scanf("%d", &arr[i] );
}

void duplicate(int original[], int cpy[], int nb){
	for(int i=0;i<nb;i++)
		cpy[i] = original[i];
}

int belongs(int arr[], int nb, int searched){
	for(int i=0;i<nb;i++){
		if(arr[i] == searched)
			return 1;
	}
	return 0;
}

int maximum(int arr[], int nb){
	int max=arr[0];
	for(int i=0;i<nb;i++){
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

void reverse(int arr[], int rev[], int nb){
	for(int i=0;i<nb;i++)
		rev[i] = arr[nb-1-i];
}

void permute(int arr[], int perm[], int nb){
	for(int i=1;i<nb;i++)
		perm[i] = arr[i-1];
	perm[0] = arr[nb-1];
}
