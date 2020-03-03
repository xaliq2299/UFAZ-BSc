#include <stdio.h>
#define SIZE 5
#include <string.h>

char buf[SIZE];

char getChar(){
	char c;
	if(buf[0] == '\0'){ //buf is empty
		for(int i=0;i<SIZE;i++){
			scanf(" %c", &c);
			buf[i] = (char)c;
		}
	}
	else{ // if it is not empty
		return (char)getc(stdin);
	}
}

int main(){
	char r = getChar();
	printf("%s\n", buf);
}