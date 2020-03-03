#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int counter=0;
void signalHandler(int signal){
	counter++;
	if(signal == SIGINT)
		printf("%d: I received signal\n", counter);
}

int main(){
	signal(SIGINT, signalHandler);
	while(1){
		if(counter == 5) break;
	}
	
	return 0;
}
