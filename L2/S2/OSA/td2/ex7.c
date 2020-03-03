// Look: problem when there's no argument for command
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]){
	if(argc<=2){
		printf("Wrong number of args\n");
		exit(-1);
	}
	int All=0, why;
	int n=atoi(argv[1]); // how many times command will be run
	char *cmd = argv[2]; // command that we run

	// a punch of memory for the args of our command
	char **args=malloc(sizeof(char*)*(n-3));
	for(int j=0;j<argc-3;j++)
		args[j]=malloc(sizeof(char)*10);
	for(int i=0;i<argc-3;i++) // copying the needed args to run our command
		strcpy(args[i], argv[i+3]);
	
	for(int i=0;i<n;i++){
		pid_t pid = fork();
		if(pid == -1){ // failure
			exit(-2);
		}
		else if(pid == 0){ // child

			if(argc == 2){
				for(int i=0;i<argc-3;i++) // copying the needed args to run our command
					strcpy(args[i], " ");
			}
			//execvp(cmd, cmd);
			execvp(cmd, args);
		}
		else{
			wait(&why);
			if(WIFEXITED(why)){
				printf("%s ", cmd);
				for(int j=0;j<argc-3;j++)
					printf("%s ", args[j]);
				printf("%d\n", i);
			}
			else
				All=1;
		}
	}

	return All;
}
