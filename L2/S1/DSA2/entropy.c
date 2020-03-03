#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
	int array[256] = {0}, counter=0;
	double entropy = 0.0;
	FILE *fp = fopen(argv[1],"rb");
	unsigned char buffer;
	
	if(fp == NULL)	printf("The file doesn't exist\n");
	else{
		while( fread(&buffer,1,1,fp) ){
			//printf("%c", buffer); //just prints the program
			array[buffer]++;
			counter++;
		}
		fclose(fp);
		
		printf("%d bytes in total\n", counter);
		//for(int i=0;i<256;i++)
		//		printf("%d: %ld\n", i, array[i] );
		
		for(int i=0;i<256;i++){
			if(array[i] != 0)
				entropy -= (double)array[i]/(double)counter*log2((double)array[i]/counter);
		}
		printf("ENTROPY = %.5lf\n", entropy);
	}
	return 0;
}
