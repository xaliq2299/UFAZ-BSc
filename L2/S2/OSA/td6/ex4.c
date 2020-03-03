// mmap remember syntax
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, char **argv){
	if(argc != 2){printf("Argument problem!\n"); exit(-1);}
	char *filename = argv[1];
	int fd = open(filename,O_RDONLY);
	if(fd == -1){perror("Problem with opening file\n"); exit(-2);}

	struct stat bf;
	fstat(fd,&bf);
	size_t size = bf.st_size;
	char *s = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
	
//	printf("%s\n", s);
	int j, i;
	for(int i=0;s[i]!='\n';i++)
		printf("%c", s[i]);
	printf("\n");

	for(j=strlen(s)-1;s[j]!='\n';j--);
	//for(int i=j;s[i]!='\n';i--);
	printf("%d", j);
	for(int i=j+1;s[i]!='\n';i++)
		printf("%c", s[i]);
	
	return 0;
}