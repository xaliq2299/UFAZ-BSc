#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

char dirs[10][25];
void split(char *filename){
	char *token; int i=0;
	token=strtok(filename,":"); //1st token
	strcpy(dirs[i++], token);
	while(1){
		token=strtok(NULL,":");
		if(token==NULL)	break;
		strcpy(dirs[i++], token);
	}
}

int main(){
	char *PATH = getenv("PATH");
	printf("%s\n", PATH);
	split(PATH);
	char *searched="ls";
	for(int i=0;i<9;i++)
		printf("%s\n", dirs[i]);
	
	struct stat buf;
	struct dirent *dir; DIR *d;
	for(int i=0;i<9;i++){
		//stat(dirs[i],&buf);
		//if(S_ISDIR(buf.st_mode))
			d = opendir(dirs[i]);
		while((dir=readdir(d))!=NULL){
		//	printf("%s\n", dir->d_name);
		//	if(strcmp( dir->d_name, searched) == 0)
		//		printf("[!] %s/%s\n", dirs[i], searched);
		}
		closedir(d);
	}
	return 0;
}