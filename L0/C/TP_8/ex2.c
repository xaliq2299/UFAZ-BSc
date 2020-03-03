#include <stdio.h>

void Calculation( int array[], int N );

int main()
{
	int N;	
	FILE *fp;        
	
	fp=fopen("integer.txt", "r");			
	fscanf(fp, "%d", &N);	
	int array[N]; 
	
	for(int a=0;a<N;a++)
	{
		if(fp!=NULL)		
		fscanf(fp, "%d ", &array[a]);
	}	
	Calculation(array, N);	
	
	fclose(fp);
}

void Calculation( int array[], int N )
{
	int sum=0, product=1, a;
	float average;
	
	for(a=0;a<N;a++)
	sum=sum+array[a];
	
	for(a=0;a<N;a++)
	product=product*array[a];
	
	average=sum/N;
	
	printf("Sum is %d\nProduct is %d\nAverage is %f\n", sum, product, average);
}
