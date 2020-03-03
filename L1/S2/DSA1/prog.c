#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numbers[100], Max;

void Show(int table[], int n){
	for(int i=0;i<n;i++)
		printf( "%d\n", table[i] );
}

int readFile(const char a){
	FILE *fp;
	fp = fopen("file.c", "r");
	char str[100], *new;
	if(fp == NULL){
		printf("Error with opening file\n");
		printf("There is no such file\n");
		exit(1);
	}
	
	//a = '!';

	fscanf(fp, "%s", str);
	new = strtok(str, &a);
	int i=0;
	
	while(new != NULL){
		numbers[i++] = atoi(new);
		new = strtok(NULL, ",");
	}
	
	return i;
}

int main(){	
	int Max = readFile(',');
	Show(numbers, Max);
	
	return 0;
}
