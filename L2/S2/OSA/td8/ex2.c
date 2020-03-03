#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

#define FE "coco"
#define MAX 1024
#define MAXPRIO 3

struct protocol {
	long type;
	char line[MAX];
};

void treat(char *data){
	puts(data);
}

void server(){
	key_t k; int l;
	int msqid;
	struct protocol m;
	k=ftok(FE, 'E');
	if(msqid=msgget(k, IPC_CREAT | 0666) == -1){
		perror("msgget"); exit(1);}
	while((l = msgrcv(msqid, &m, MAX, -MAXPRIO, 0)) > 0)
		treat(m.line);
	if(l == -1){
		perror("msgrcv"); exit(1);}
	if(msgctl(msqid, IPC_RMID, NULL) == 0){
		perror("msgctl"); exit(1); }
}

void client(long prio, char *data){
	key_t k;
	int msqid, l;
	struct protocol m;
	k=ftok(FE, 'E');
	msqid = msgget(k,0); // ??? TODO	
	if(data == NULL)	
		l=0;
	else{
		strcpy(m.line, data);
		l = strlen(m.line);
	}
	m.type = prio;
	if(msgsnd(msqid, &m, l, 0) == -1){
		perror("msgsnd"); exit(1);
	}
}

void main(int argc, char *argv[]){
	char *p; long prio;
	p = strrchr(argv[0], '/');
	if (p == NULL) p=argv[0];
	if (strcmp(argv[0], "server") == 0 )
		server();
	else if(strcmp(argv[0], "client") == 0){
		switch(argc){
			case 1: client(3L, NULL);
					break;
			case 3: break;
		}
	}

	else{
		fprintf(stderr, "the program should be named server or client");
		exit(1);
	}

	exit(0);
}