#include <stdio.h>
#include "run.h"
#include "buffer.h"

int main(int argc, char **argv){
	// some default values for option arguments
	char format[25]={0}; // format for printing time
	int bExitCode=0, bTime=0; // "boolean" values
	int limit=0, interval=10000000; // limit for executions and interval between them
	
	int option; // used in getopt
	char prog[40]; // the command that's going to be executed (possibly with some args)
	Buffer buf_old = get_buffer(); // buffer to store outputs of executions

	// dealing with options and option arguments
	if(argc==1) {exit(1);} // only ./detecter
	while( (option = getopt(argc, argv, "+t:i:l:c")) != -1 ){
		switch (option){
			case 't': if(optarg){ bTime=1; strcpy(format, optarg); } // time
					  else exit(1);
					  break;
			case 'i': if(optarg) { // interval
						interval=atoi(optarg);
					  	if(interval <= 0) exit(1);
					  	interval*=1000;
					  }
					  else exit(1);
					  break;
			case 'l': if(optarg){ // limit for launchs
						limit=atoi(optarg); 
					  	if(limit<0) exit(1);
					  }
					  else exit(1);
					  break;
			case 'c': bExitCode=1; break; // exit code
			case '?': printf("Unknown option.\n"); // unknown
					  exit(1);
		}
	}
	
	if(argc == optind) exit(1); // provided no command to run
	strcpy(prog, argv[optind]);

	int i=0; // counter for # of execution
	for(i=0;i<limit;i++){ // limited execution
		buf_old = run(&buf_old,prog,argv,optind,i,bTime,format,bExitCode); // running the command
		usleep(interval); // does nothing during some interval
	}
	if(limit == 0){ // infinite execution
		while(1){
			buf_old = run(&buf_old,prog,argv,optind,i,bTime,format,bExitCode); // runnning the command
			usleep(interval); // does nothing during some interval
			i++;
		}	
	}

	destruct_buffer(&buf_old); // free memory
	exit(0); // successful
}