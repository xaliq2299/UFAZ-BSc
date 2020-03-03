#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
//#define NTAB(t)  ((int) (sizeof(t)/sizeof(t)[0]))

//typedef struct {int signo; char *signame;} Sig;

void signalHandler(int signo){
	char *signame = malloc(sizeof(char)*50);
	psignal(signo, signame);
	//if(signo == SIGINT){}

	printf("%s\n", signame);
	//exit(0);
}

int main(){
	int n;
	for(int i=1;i<=64;i++)
		signal(i,signalHandler);

	while(1){
		scanf("%d", &n);
		if(n <= 0) {printf("No such signal in your system\n"); break;}
		kill(0, n);
	}

	return 0;
}