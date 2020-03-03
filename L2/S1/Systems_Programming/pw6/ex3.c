// the exercise is related to the topic we didn't cover: drivers
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

char* my_ttyname(int fd){
	char *s1, *s2;
	if ((s1 = ttyname(fd)) == NULL)
    	perror("ttyname() error");
 	else 
    	strcpy(s1, s2);
  	return s2;
}

int main(int argc, char **argv){
	int fd = open(argv[1], O_RDONLY);
	printf("%s\n", my_ttyname(fd) );

	return 0;
}
