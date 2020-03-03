#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *my_getenv(char *str){
	int i=0;
	while(environ[i]){
		strtok(environ[i], "=");
		if(strcmp(environ[i], str) == 0){
			char *s=strtok(NULL, "=");
			return s;
		}
		i++;
	}
}

int main(){
	//printf("HOME=%s\n", my_getenv("HOME") );
	printf("USER=%s\n", my_getenv("USER") );
	return 0;
}