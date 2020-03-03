#include <stdio.h>
#include <stdlib.h>

float** allocate(int n, int m){
	float** grid = (float**)calloc(n,sizeof(float*));
	for(int i=0;i<n;i++)
		grid[i] = (float*)calloc(m,sizeof(float));
	return grid;
}

void printIt(float **grid, int n, int m){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			printf("%4.1f", grid[i][j] );
		puts("");
	}
}

void fillIn(float **grid, int n, int m){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			grid[i][j] = i+j;
	}
}

int main(){
	int row, col;
	scanf("%d%d", &col, &row);
	float **fArray = allocate(col,row);
	fillIn(fArray, row, col);
	printIt(fArray, row, col);
	
	return 0;
}
