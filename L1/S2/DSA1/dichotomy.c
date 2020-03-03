#include <stdio.h>
#define SIZE 12

int main(){
	int array[SIZE] = {1,2,3,4,5,6,7,9,11,15,22,39};
	int nNum, iLeft = 0, iRight = SIZE-1, middle;
	printf("Enter the number you want to search: ");
	scanf("%d", &nNum);
	while(iLeft<=iRight){
		middle=(iLeft+iRight)/2;
		if(array[middle] > nNum)
			iRight=middle-1;
		else if(array[middle] < nNum)
			iLeft=middle+1;
		else{
		   printf("Found.\n");
		   return 1;
		}
	}
	printf("Not found.\n");
	return 0;
}
