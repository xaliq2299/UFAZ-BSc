#include <stdio.h>

int main(){
	int array[256] = {0};
	char string[24];
	
	scanf("%[^\n]s", string);
	
	for(int i=0;string[i] != '\0';i++){
		array[string[i]]++;
	}
	
	for(int i=0;i<256;i++){
		if(array[i] != 0)
			printf("%c: %d\n", i, array[i]);
	}
	
	return 0;
}
