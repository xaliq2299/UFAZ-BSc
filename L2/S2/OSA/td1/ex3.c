#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd1,nb; char c;
	fd1=open("toto", O_RDONLY);
	int fd2=open("titi", O_WRONLY|O_CREAT,0666);

	while ( (nb=read(fd1,&c,1)) != 0)
		write(fd2,&c,1);
	close(fd1);
	close(fd2);

	return 0;
}