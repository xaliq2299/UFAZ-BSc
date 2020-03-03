#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv){
	struct stat buf;
	if(argc == 1){
		printf("The filename is expected\n");
		return -2;
	}
	char *filename = argv[1];
	if( stat(filename, &buf) == -1 ){
		printf("[!]Problem while calling the stat function, file doesn't exist\n");
		return -1;
	}
	//another way of checking type of a file
	/*if((buf.st_mode & S_IFMT) == S_IFREG)
		printf("true\n");*/	 

	//types of requested file
	if( S_ISREG(buf.st_mode) )	printf("regular file\n");
	else if( S_ISDIR(buf.st_mode) )	printf("directory\n");
	else if( S_ISLNK(buf.st_mode) )	printf("symbolic link\n");
	
	//permissions
	if((buf.st_mode & S_IRUSR) ) printf("Owner has read permission\n");
	if((buf.st_mode & S_IWUSR) ) printf("Owner has write permission\n");
	if((buf.st_mode & S_IXUSR) ) printf("Owner has execute permission\n");

	return 0;
}

/*
int mask; char perm[9+1], *p;
strcpy(rwxrwxrwx);
p=perm;
mask=0400;
while(mask != 0){
	if( (buf.st_mode & mask) == 0 )
		*p='-';
		p++;
		mask>>=1;
}
*/