#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signal){
	if(signal == SIGINT){
		printf("I received signal %d\n", signal);
		//date
		//counter
	}
	else if(signal == SIGTERM)
}

int main(){
	int counter=0;
	struct sigaction s;
	s.sa_handler = signalHandler;
	sigemptyset(&s.sa_mask);
	sigaddset(&s.sa_mask, SIGQUIT);
	int signal;
	sigaction(signal, &s, NULL);
	
	while(1){

		counter++;
	}
	return 0;
}
	
//==============================
//		by Nicolas Magaud
//==============================
/*
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>

#define MYFILE "myfile.txt"
int counter=0;

void print_value(){
	FILE *fp = fopen(MYFILE, "a");
	time_t time_in_seconds = time(NULL);
	char *time_readable = ctime(&time_in_seconds);
	fprintf(fp, "%s %d\n", time_readable, counter);
	fclose(fp);
	printf("counter=%d\n", counter);
}

void terminate(){
	printf("end\n");
	exit(1);
}

void setup_signals_handler(){
	struct sigaction action;
	action.sa_handler=print_value;
	sigemptyset(&action.sa_mask);
	//sigaddset(&action.sa_mask,SIGQUIT);
	sigaction(SIGINT, &action, NULL);
		
	action.sa_handler=terminate;
	//sigemptyset(&action.sa_mask);
	//sigaddset(&action.sa_mask,SIGINT);
	sigaction(SIGQUIT, &action, NULL);
	
}

int main(){
	setup_signals_handler();
	for(;;) counter++;

	return 0;
}
*/
