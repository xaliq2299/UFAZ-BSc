#include <stdio.h>

void find_mode(int big, int freq[big+1] );

int main()
{
	int size, a, b, big, check=0;	
	
	printf("Number of elements in array: ");
	scanf("%d", &size);

	int array[size];
	
	printf("Enter the numbers:\n");
	//input the numbers
	for(a=0;a<size;a++)
		scanf("%d", &array[a]);
	//determining the biggest
	big=array[0];
	for(a=1;a<size;a++)
	{
		if(array[a]>big)
		big=array[a];	
	}		

	int freq[big+1];//the most important

	for(a=0;a<big+1;a++)
		freq[a]=0;

	for(a=0;a<size;a++)
		freq[array[a]]+=1;

	for(a=0;a<big+1;a++)
	{
		if(freq[a]!=1 && freq[a]!=0)
		{		
			find_mode(big, freq);
			check++;			
			break;
		}
	}

	if(check==0)	
		printf("There is no mode\n");

	return 0;
}


void find_mode(int big, int freq[big+1] )
{	
	int a, b, big1;

	big1=freq[0];

	for(a=1;a<big+1;a++)
	{
		if(freq[a]>big1)
			big1=freq[a];
	}

	printf("Mode: ");
	for(a=0;a<big+1;a++)
	{
		if(big1==freq[a])	
		printf("%4d", a);	
	}
	puts("");
}
