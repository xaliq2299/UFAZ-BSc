#include <dirent.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
	DIR *d;
	struct dirent *dir;
	d=opendir(".");
	if(d){
		while((dir=readdir(d))!=NULL){
			if(dir->d_name[0] != '.')
				printf("%ld \t %s\n", dir->d_ino, dir->d_name);
		}
	}
	closedir(d);
	return 0;
}