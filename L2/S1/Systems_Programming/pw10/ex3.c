#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signalHandler(int signal){
	printf("Received the signal %d\n", signal);
	char s[25];
	psignal(signal, s);
	exit(0);
}

int main(){
	for(int i=1;i<=64;i++)
		signal(i, signalHandler);
	while(1){}

	return 0;
}
