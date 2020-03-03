#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv[]){
	int fd;
	fd = open("file.txt", O_CREAT | O_WRONLY, 0600);
	if(fd == -1){
		printf("ERROR is opening or creating the file.\n");
		exit(1);
	}
	write(fd,"THIS IS A TEST FOR OPEN FILE.\n",29);
	close(fd);
	
	fd = open("file.txt", O_CREAT);
	if(fd == -1){
		printf("ERROR is opening or creating the file.\n");
		exit(1);
	}
	char buf[29];
	read(fd,buf,29);
	buf[29] = '\0';
	printf("BUFF: %s\n", buf);
	close(fd);
	
	return 0;
}
