#include <stdio.h>
#include <string.h>

int main()
{ 
	char Filename[20];	
	void Large();	
	printf("Enter the name of a file: ");	
	scanf("%s", Filename);
	if(strcmp(Filename, "integer.txt") == 0)
	Large();

	return 0;
}

void Large()
{
	FILE *fp;        
	fp=fopen("integer.txt", "r");	
	int numb;		

	int N;
	fscanf(fp, "%d", &N);	
	int array[N]; 

	for(int a=0;a<N;a++)
	{
		if(fp!=NULL)		
		fscanf(fp, "%d ", &array[a]);
	}
	fclose(fp);	

	for(int a=0;a<N;a++)
	printf("%d ", array[a]);	
	printf("\nEnter the number of the element in the row above: ");
	scanf("%d", &numb);
	printf("%dth element in the row is %d\n", numb, array[numb-1]);  
}

