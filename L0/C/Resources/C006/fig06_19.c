/*Fig. 6.19: fig06_19.c
Binary search of a sorted array */
#include <stdio.h>
#define SIZE 15
int binarySearch (const int b[], int searchkey, int low, int high);
void printHeader(void);
void printRow(const int b[],int low,int mid, int high);
int main(void){
int a[SIZE];
int i, key,result;
for (i=0;i<SIZE;i++)
a[i]=2*i;

printf("Enter a number between 0 and 28:");
scanf("%d",&key);
printHeader();
result=binarySearch(a,key,0,SIZE-1);
if (result!=-1)
printf("\n%d found in array element %d\n",key,result);
else
printf("\n%d not found\n",key);
return 0;
}

int binarySearch(const int b[], int searchkey, int low, int high){
	int middle;
	while(low<=high){
		middle =(low+high)/2;
		printRow(b,low,middle,high);
		if (searchkey==b[middle])
			return middle;
		else if (searchkey<b[middle])
			high=middle-1;
		else
			low=middle+1;
	}
	return -1;
}

void printHeader(void){
	int i;
	printf("\nSubscripts:\n");
	for (i=0;i<SIZE;i++)
		printf("%3d",i);
	printf("\n");
	for (i=1;i<=4*SIZE;i++)
		printf("-");
	printf("\n");
}

void printRow(const int b[],int low, int mid, int high){
	int i;
	for(i=;i<SIZE;i++)
	{
		if(i<low || i>high)
			printf("	");
		else if (i==mid)
			printf("%3d*",b[i]);
		else 
			printf("%3d",b[i]);
	}
	printf("\n");
}