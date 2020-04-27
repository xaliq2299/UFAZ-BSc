#include <stdio.h>
#include <stdlib.h>

float **matrixMul(float **A, float **B, int rowA, int colA, int rowB, int colB){
	float **C = (float **)malloc(sizeof(float*)*rowA); 
	for(int i=0;i<rowA;i++)
		C[i] = (float*)malloc(sizeof(float)*(sizeof(colB)));
	
	for(int i=0;i<rowA;i++)
		for(int j=0;j<colB;j++)
			for(int k=0;k<colA;k++)
				C[i][j]+=( A[i][k]*B[k][j] );
	
	return C;
}

void print_matrix(float **matrix, int row, int column){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			printf("%6.2f", matrix[i][j]);
		puts("");
	}
}

float **getEmptyMatrix(){
	int row, col;
	scanf("%d%d", &row, &col);
	float **matrix = (float **)malloc(sizeof(float*)*row); 
	for(int i=0;i<row;i++)
		matrix[i] = (float*)malloc(sizeof(float)*col);
	
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			scanf("%f", &matrix[i][j]);
	
	return matrix;
}

int main(){
	float **A = getEmptyMatrix();
	float **B = getEmptyMatrix();
	float **C = matrixMul(A, B, 3, 3, 3, 3);
	print_matrix(C, 3, 3);
	
	return 0;	
}
