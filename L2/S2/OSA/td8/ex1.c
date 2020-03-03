#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

struct message{
	long mtype;
	char text[25];
};

/*int create_file(){
	key_t k; int id;
	k = ftok("file", 'F');
	if(k==-1) perror(" ftok ");
	id = msgget(k, IPC_CREAT | 0666);
	if(id == -1) perror("msgget");
	return id;
}*/

/*void remove_file(int id){
	int r;
	r=msgctl(id, IPC_RMID, NULL);
	if(r == -1) perror(" msgctl ");
}*/

/*void write_value(int id, char *str){
	key_t k;
	k = ftok("file", 'F');
	if(k==-1) perror(" ftok ");	
	struct message m;
	m.mtype=1;
	strcpy(m.text,str);
	int r=msgsnd(id, &m, sizeof(m)-sizeof(m.mtype), 0);
	if(r == -1) perror(" msgsnd ");
}*/

/*
char *read_value(int id){
	struct message m; int r;
	r=msgrcv(id, &m, sizeof(m) - sizeof(m.mtype), m.mtype, 0);
	if(r == -1) perror(" msgrcv ");
	return m.text;
}*/

int main(){
	char msg[50]; //struct message m; m.mtype=1;
	struct message m;
	pid_t pid = fork(); int id;
	
	if(pid == -1){exit(-1);}
	else if (pid == 0){ // child
		key_t k; int id;
		k = ftok("file", 65);
		id = msgget(k, 0);
		if(id == -1) perror("msgget");
		
		int r=msgrcv(id, &m, sizeof(m), 1, 0);
		printf("# of bytes: %ld\n", strlen(m.text));
		msgctl(id, IPC_RMID, NULL);
	}
	else{ // father
		key_t k; int id;
		k = ftok("file", 65);
		if(k==-1) perror(" ftok ");
		id = msgget(k, IPC_CREAT | 0666);
		if(id == -1) perror("msgget");
		
		m.mtype=1;
			scanf("%[^\n]s", msg);
			strcpy(m.text,msg);
		int r=msgsnd(id, &m, sizeof(m), 0);
		if(r == -1) perror(" msgsnd ");
		wait(NULL);
	}

	return 0;
}