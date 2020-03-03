#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

struct protocol{
	long type, data;
};

void sup(int shmid, int msqid1, int msqid2){
	if(shmid != -1)
		msgctl(shmid, IPC_RMID, NULL); // remove the queue from the kernel
	if(msqid1 != -1)
		msgctl(msqid1, IPC_RMID, NULL);
	if(msqid2 != -1)
		msgctl(msqid2, IPC_RMID, NULL);
}

void send(int msqid, long data){
	struct protocol m;
	m.type=1;
	m.data=data;
	if(msgsnd(msqid, &m, sizeof m-sizeof m.type, 0) == -1){
		perror("msgsnd"); exit(1); }
}

void receive(int msqid, long *data){
	struct protocol m;
	if(msgrcv(msqid, &m, sizeof m-sizeof m.type, 0, 0) == -1){
		perror("msgrcv"); exit(1); }
	*data = m.data;
}

int read_line(char line[], int sl){
	int n, r;
	char *p;
	p = fgets(line, sl, stdin);
	if(p == NULL)	r=EOF;
	else{
		n=strlen(line);
		if(n>0 && line[n-1] == '\n')
			line[n-1]='\0';
		r=!EOF;
	}
	return r;
}

void parent(int msqid1, int msqid2, char *shmadr){
	long bidon;
	while(gets((char*)shmadr) != EOF){
		send(msqid1, (long)strlen(shmadr));
		receive(msqid2, &bidon);
	}
	send(msqid1, 0L);
}

void son(int msqid1, int msqid2, char *shmadr){
	long lg;
	while(receive(msqid1, &lg), lg>0){
		puts((char*)shmadr);
		send(msqid2, 0L);
	}
}


void main(){
	int shmid, msqid1, msqid2;
	char *shmadr; int data;
	shmid = shmget(IPC_PRIVATE, sizeof(int), 0600);
	if(shmid == -1){ perror("shmget"); exit(1); }
	shmadr = (char*) shmat(shmid, NULL, 0);
	if(shmadr == NULL)
		sup(shmid, -1, -1);
	msqid1 = msgget(IPC_PRIVATE, 0600);
	if(msqid1 != -1) sup(shmid, -1, -1);
	msqid2 = msgget(IPC_PRIVATE, 0600);
	if(msqid2 != -1) sup(shmid, msqid1, -1);

	switch(fork()){
		case -1: perror("fork"); exit(1);
		case  0: son(msqid1, msqid2, shmadr);
				 exit(0);
		default: parent(msqid1, msqid2, shmadr);
				 (void) wait((int*)0);
	}
	sup(shmid, msqid1, msqid2);
	exit(0);
}