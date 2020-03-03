#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

void printFileProperties(struct stat stats);

int main(){
	char filename[65];
	printf("Enter the path for the file: ");
	scanf("%s", filename);
	struct stat stats;
	stat(filename,&stats);
	printf("%ld\n", stats.st_size);
	printf("%d\n", stats.st_mode & W_OK);
	printf("%d\n", stats.st_gid);

	printf("%d\n", stats.st_uid);
	return 0;
}

void printFileProperties(struct stat stats){
	if(stats.st_mode & R_OK) printf("read\n");
}