#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
	int fd1, fd2;
	fd1 = open("foo.txt", O_RDONLY);
	if(fd1 == -1){ printf("File foo couldn't be opened or doesn't exist\n"); return 0; }
	fd2 = open("bar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(fd2 == -1){ printf("File bar couldn't be opened or doesn't exist\n"); return 0; }
	char c; ssize_t n;

	while (( n = read ( fd1 , &c , 1)) > 0)
	if ( write ( fd2 , &c , 1) == -1) perror ( "write" ) ;
	if ( n == -1) perror ( "read" ) ;
	if ( close ( fd1 ) == -1) perror ( "close foo" ) ;
	if ( close ( fd2 ) == -1) perror ( "close bar" ) ;
	
	return 0;
}