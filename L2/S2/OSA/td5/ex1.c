#include <stdio.h>
#include <signal.h>

int counter=1;

void signalHandler(int signo){
	if(signo == SIGINT){
		printf("\n%d\n", counter);
		counter++;
	}
}

int main(){
	signal(SIGINT, signalHandler);
	while(counter<=5)
		continue;
	return 0;
}