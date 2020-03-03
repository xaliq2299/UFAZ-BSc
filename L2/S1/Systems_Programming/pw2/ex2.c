#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1000

int main(int argc, char *argv[]){
	int n, m=1, nFileSize, nbLines=0;  // n is #of lines the user wants to display from the file of name filename, m is #of last bytes read from the file each time
	char temp[BUF_SIZE] = {0};         // the characters read are written to this string
	char buf[BUF_SIZE] = {0};          // but to avoid extra newline we finally write it this buf string
	char *filename, c;			       // name of the file
	FILE *fp;				           // pointer to the file

	if(argc == 1){
		printf("Give some arguments\n");
		printf("The format: ./a.out n filename\n");
		return -1;
	}

	n = atoi(argv[1]);  // second argument is the number of lines in asked by the user
	filename = argv[2]; // third  argument is the name of the file
	if(n < 0){ //if #of lines is negative
		printf("The number of lines should be positive\n");
		printf("The format: ./a.out n filename\n");
		return -1;
	}
	if( (fp = fopen(argv[2], "r")) == NULL){ // if the file pointer points to nothing
		fprintf(stderr, "The file couldn't be opened or doesn't exist\n");
		printf("The format: ./a.out n filename\n");
		return -2;
	}

	fseek(fp, 0, SEEK_END);  nFileSize=ftell(fp); // determining #of characters in the file

	while(nbLines != n){ // loop to find n lines
		if(nFileSize == m)	break; // in case if n is tha same as the whole # of lines of the file
		nbLines=0; // each time when we go from the end of the file we reinitialize # of lines to 0
		fseek(fp,-m,SEEK_END); // go m bytes back from the end of the file
		fread(temp, sizeof(char), m, fp); // read last m bytes
		for(int i=0;temp[i]!='\0';i++){
			if(temp[i] == '\n')	nbLines++;
		}
		m++;
	}

	if(n > nbLines+1) //if #of lines asked is more than the #of whole lines of a file
		printf("There is no %d lines in the file %s\n", n, filename);
	else if(nFileSize == m){ // if #of lines asked is the same as the #of whole lines of a file
		fseek(fp,-m,SEEK_END); // go m bytes back from the end of the file
		fread(temp, sizeof(char), m, fp); // read last m bytes
		printf("%s\n", temp); // printing the whole file
	}
	else if(nbLines == n){ // if #of lines asked is less than the #of whole lines of a file
		m-=2; // we remove extra \n
		fseek(fp,-m,SEEK_END); // go to the m last bytes that we need 
		fread(buf, sizeof(char), m, fp); // and read them until the end
		printf("%s\n", buf); // printing the n last line of a file
	}

	return 0;
}