#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define SIZE 10000

typedef struct {
	char *filename;
	char buffer[SIZE];
	int fd;
} MYFILE;

void my_getc(MYFILE f){
	char c;
	read ( f.fd , &c , 1);
}

void my_putc(MYFILE f){
	char c;
}

int my_open(MYFILE f, char mode){
	int fd;
	if(mode == 'r')
		fd = open(f.filename, O_RDONLY);	
	else if(mode == 'w')
		fd = open(f.filename, O_WRONLY);
	else if(mode == 'a')
		fd = open(f.filename, O_WRONLY | O_RDONLY);
	else{
		printf("Problem with opening the file\n");
		return -1;
	}
	f.fd = fd;
	return 1;
}

void my_close(MYFILE f){
	close(f.fd);
}

int main(){
	MYFILE f; f.filename = "bar";
	my_open(f,'r');

	return 0;
}