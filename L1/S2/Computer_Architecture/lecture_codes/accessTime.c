#include <stdio.h>

int main(){
	//int a[2][3];
	
	/*for(int i=0;i<2;i++){
		for(int j=0;j<3;j++)
			printf("Address of a[%d][%d]: %p\n", i, j, &a[i][j]);
	}
	
	puts("");
	
	for(int j=0;j<3;j++){
		for(int i=0;i<2;i++)
		  printf("Address of a[%d][%d]: %p\n", i, j, &a[i][j]);		
	}*/
	
	//row by row
	/*int array[1024][1024];
	for(int i=0;i<1024;i++){
		for(int j=0;j<1024;j++){
			array[i][j] = i+j;
		}
	}*/
	
	//column by column
	int array[1024][1024];
	for(int j=0;j<1024;j++){
		for(int i=0;i<1024;i++){
			array[i][j] = i+j;
		}
	}
	
	return 0;
}
