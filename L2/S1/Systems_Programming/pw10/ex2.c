#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signalHandler(int signal){
	if(signal == SIGQUIT){
		printf("I received signal %d\n", signal);
	}
	system("ulimit -c unlimited");
}

int main(){
	signal(SIGQUIT, signalHandler);	
	while(1){
		
	}
	return 0;
}
