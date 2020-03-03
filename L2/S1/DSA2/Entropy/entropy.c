#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char** argv){
	if(argc < 2){
		printf("USAGE: %s filename\n", argv[0]);
		exit(1);
	}

	/*FILE OPENING*/
	char *filename = argv[1];
	unsigned long symbols[256] = {0};
	int fd = open(filename, O_RDONLY);
	if(fd == -1){
		printf("[!] ERROR while opening the file.\n");
		exit(1);
	}
	
	/*READING FILE*/
	unsigned long count = 0;
	unsigned char buff[1024];
	unsigned long re;
	while (	(re = read(fd,buff,1024)) > 0){
		printf("%ld\n", re);
		count+=re;
		for(int i=0;i<re;i++)
			symbols[ buff[i] ] ++;
	}
	
	/*ENTROPY*/
	double entropy = 0;
	for(int i=0;i<256;i++){
		if( symbols[i] ){
			double p = (double)symbols[i]/(double)count;
			entropy -= p*log2(p);
		}
	}
	
	printf("Entropy of the file = %lf\n", entropy);
	
	close(fd);
	return 0;
}
