#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int my_system(char *exp){
	int pid = fork();
	if(pid == -1){exit(-1);}
	else if(pid == 0){
		execl("/bin/sh", "/bin/sh", "-c", exp, NULL);
	}
	else{
		wait(NULL);
		if(WIFEXITED(NULL))
			return WEXITSTATUS(NULL);
	}
	return -1;
}

int main(){
	char cmd[50];
	printf("Enter a command to run:\n");
	scanf("%[^\n]s", cmd);
	my_system(cmd);

	return 0;
}