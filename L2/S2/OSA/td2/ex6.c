// Look
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char **argv){
	if(argc != 2) exit(-1);
	int r;
	char *dir_name=argv[1];
	printf("%s", dir_name);
	
	if( (r= fork()) == -1 )
		exit(-1);
	else if(r == 0)
		execl("ls", "ls", dir_name, "-R", NULL);
		//wait(NULL);
		//return 1;

	return 0;
}