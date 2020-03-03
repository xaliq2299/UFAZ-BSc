#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

double compressionRate(double cSize, int oSize){ //Compressed Size, Original Size
	return cSize/(double)oSize/(double)8*(double)100;
}

typedef struct {
	short s; char c;
}Stack3;

int main(int argc, char** argv){
	int c;
	if(argc < 2){
		printf("USAGE: %s filename\n", argv[0]);
		exit(1);
	}
	
	while( (c = getopt(argc,argv,"a:")) != -1){
		switch(c){
			case 'a':{
				/*DICTIONARY SYMBOLS*/
				printf("Thank you for choosing the option %d\n", atoi(argv[2]) );
				int g=atoi(argv[2]);
				unsigned long symbols[(int)pow(2,g*8)];
				for(int i=0;i<pow(2,8*g);i++)
					symbols[i] = 0;
		
				/*FILE OPENING*/
				char *filename = argv[3];
				int fd = open(filename, O_RDONLY);
				if(fd == -1){
					printf("[!] ERROR while opening the file.\n");
					exit(1);
				}	
		
				/*READING FILE*/
				unsigned long count = 0;
				unsigned long re;
				if(g == 1){
					unsigned char buff[1024];
					while (	(re = read(fd,buff,1024)) > 0){
						count+=re;
						for(int i=0;i<re;i++)  symbols[ buff[i] ] ++;
					}
				}
				else if(g == 2){
					unsigned short buff[1024];
					while (	(re = read(fd,buff,1024)) > 0){
						count+=re;
						for(int i=0;i<re;i++)  symbols[ buff[i] ] ++;
					}
				}
/*				else if(g == 3){
					Stack3 buff[1024];
					while (	(re = read(fd,buff,1024)) > 0){
						count+=re;
						for(int i=0;i<re;i++)  symbols[ buff[i] ] ++;
					}
				}*/
				else if(g == 4){
					unsigned long buff[1024];
					while (	(re = read(fd,buff,1024)) > 0){
						count+=re;
						for(int i=0;i<re;i++)  symbols[ buff[i] ] ++;
					}
				}
				else{
					printf("The length of data length is not convenient %d.\n", g);
					exit(1);
				}
				/*ENTROPY*/
				double entropy = 0.0;
				for(int i=0;i<pow(2,8*g);i++){
					if( symbols[i] ){
						double p = (double)symbols[i]/(double)count;
						entropy -= p*log2(p);
					}
				}
				printf("Entropy of the file = %lf\n", entropy);
				printf("Compression Rate: %.4lf%%\n", compressionRate(entropy,g) );
				
				break;
			}
			case '?': if(optopt == 'a')
		     		      printf("You need to give the value of parameter.\n");
					  else
						  printf("Unavailable option -%c", optopt);
					  break;
			default: break;
		}
	}

	return 0;
}
