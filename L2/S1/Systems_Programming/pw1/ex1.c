#include <stdio.h>
#include <string.h>
#define SIZE 25

int main(){
	char str1[SIZE], str2[SIZE];
	printf("Enter the string: ");
	fgets(str1, SIZE, stdin);
	strncpy(str2, str1, SIZE);
	printf("The copied string: ");
	puts(str2);
	printf("Length = %ld\n", strlen(str2)-1 );
	return 0;
}
