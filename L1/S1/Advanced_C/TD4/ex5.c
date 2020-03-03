#include <stdio.h>

int belongs(int searched, int my_array[], int nb_elements){
	if(nb_elements == 0)				return 0;
	else if(my_array[0] == searched)	return 1;
	else   belongs(searched, my_array+1,nb_elements-1);
}

int main(){
	int num, my_array[5] = {12,9,7,89,61};
	
	printf("my_array=%p\n", my_array);	
	printf("my_array=%p\n", my_array+1);	
	printf("my_array=%p\n", my_array+2);	
	printf("Enter number to search in array: ");
	scanf("%d", &num);
	printf("%d\n", belongs(num, my_array, 5) );
	
	return 0;
}
