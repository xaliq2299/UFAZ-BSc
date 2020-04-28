#include "run.h"

Buffer run(Buffer *buf_old, char *prog, char **argv, int optind, int iExec, int bTime, char *format, int bExitCode){
	int fds[2]; // file descriptors for pipe	
	time_t rawtime; struct tm *info; char buffer[100]; // used for time
	char c; // the character that's going to be read from pipe and written to the buffer
	int cur, temp; // used for detecting modification of return code

	pipe(fds);
	pid_t pid = fork();
	if(pid == -1){exit(1);} // fork failed
	else if(pid == 0){ // child
		if(bTime){
			time( &rawtime );
			info = localtime( &rawtime );
			int s = strftime(buffer,80,format,info);
			char *timeBuf = malloc(sizeof(char)*(s+1));
			strcpy(timeBuf, buffer);
			timeBuf[s]='\n';
			write(1,timeBuf,s+1);
	 	}
		close(fds[0]); dup2(fds[1],1); close(fds[1]);
		execvp(prog, argv+optind); // executing the command
	}
	else{ // parent
		int why;
		close(fds[1]);
		if(iExec == 0){ // checking whether it's the 1st exec
			while(read(fds[0],&c,1)){ // reading from the pipe
				buf_old->data[buf_old->size-1]=c;
				buf_old->data = realloc(buf_old->data,++buf_old->size);
			}
			buf_old->size--; // very important
			write(1,buf_old->data,buf_old->size); // printing the result of execution
		}
		else{
			Buffer buf_new = get_buffer();
			while(read(fds[0],&c,1)){ // reading from the pipe
				buf_new.data[buf_new.size-1]=c;
				buf_new.data = realloc(buf_new.data,++buf_new.size);
			}
			buf_new.size--; // very important
			if(compare(buf_old, &buf_new)){ // compare the contents of buf_old and buf_new
				*buf_old=copy(buf_old,&buf_new); // if there's a difference, copy buf_new to buf_old
				destruct_buffer(&buf_new); // free the memory from buf_new
				write(1,buf_old->data,buf_old->size); // printing the result of execution (in case of modification)
			}
		}

		wait(&why); // waiting for the child
		if(bExitCode){ // if -c option is activated
			char exitCode[7]; // buffer which contains data about exit code
			exitCode[0]='e';		exitCode[1]='x'; 		
			exitCode[2]='i';		exitCode[3]='t';
			exitCode[4]=' ';	 	exitCode[6]='\n';
			if(iExec == 0){ // checking whether it's the 1st exec
				cur = WEXITSTATUS(why);
				exitCode[5]=cur+'0'; // converting integer to character
				write(1,exitCode,7); // printing the exit code
			}
			else{
				int temp = WEXITSTATUS(why);
				if(temp != cur){ // change in exit code?
					cur = temp; // overwrites the exit code
					exitCode[5]=cur+'0'; // converting integer to character
					write(1,exitCode,7); // printing the exit code (in case of modification)
				}
			}
		}
	}
	return *buf_old;
}

void print_summary(int argc, char **argv, char *prog, int optind, int bTime, char *format, int interval, int limit, int bExitCode){
	printf("prog=%s\n", prog);
	printf("format=%s, bExitCode=%d, interval=%d, limit=%d\n", format, bExitCode, interval, limit);
	printf("optind=%d\n",optind);
	for(int i=optind;i<argc;i++) printf("%s\n", argv[i]);
}