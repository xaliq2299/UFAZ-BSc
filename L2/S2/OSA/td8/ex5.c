#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

struct model{
	int n;
	char data[1000];
};

#define MAX sizeof(struct model)
#define SEMPROD 0
#define SEMCONS 1

void supp_ipc(int shmid, int semid){
	if(shmid != -1)
		shmctl(shmid, IPC_RMID, NULL);
	if(semid != -1)
		semctl(semid, IPC_RMID, 0);
}

void P(int semid, int semnum){
	struct sembuf sop[1];
	sop[0].sem_num=semnum;
	sop[0].sem_op=-1;
	sop[0].sem_flg=0;
	semop(semid, sop, 1); // struct sembuf*: the reason of table
}

void V(int semid, int semnum){
	struct sembuf sop[1];
	sop[0].sem_num=semnum;
	sop[0].sem_op=1;
	sop[0].sem_flg=0;
	semop(semid, sop, 1);
}

int read_line(char line[], int size){
	int n, r;
	char *p;
	p = fgets(line, size, stdin);
	if(p == NULL)	r=EOF;
	else{
		n=strlen(line);
		if(n>0 && line[n-1] == '\n')
			line[n-1]='\0';
		r=!EOF;
	}
	return r;
}

void father(int semid, struct model *shmadr){
	P(semid, SEMPROD);
	while(read_line(shmadr->data,sizeof(shmadr->data) != EOF)){
		shmadr->n = strlen(shmadr->data)+1;
		V(semid,SEMCONS);
		P(semid, SEMPROD);
	}
	shmadr->n = 0;
	V(semid, SEMCONS);
}

void child(int semid, struct model* shmadr){
	long lg;
	P(semid, SEMCONS);
	while(shmadr->n != 0){
		puts((char*) shmadr->data);
		V(semid, SEMPROD);
		P(semid, SEMCONS);
	}
}

int main(int argc, char **argv){
	int shmid, semid;
	struct model *shmadr;
	int data;
	u_short val_init[2];

	shmid = shmget(IPC_PRIVATE, MAX, 0600);
	if(shmid == -1){
		perror("shmid");
		exit(1);
	}

	shmadr = (struct model*) shmat(shmid, NULL, 0);
	semid = semget(IPC_PRIVATE, 2, 0600); // 2 is number of semaphores
	val_init[SEMPROD]=1;
	val_init[SEMCONS]=0;
	if(semctl(semid, -1, SETALL, val_init)==-1){
		perror("semctl");
		supp_ipc(shmid, -1);
		exit(1);
	}
	switch(fork()){
		case -1: perror("fork"); exit(1);
		case  0: child(semid, shmadr);
		exit(0);
		default: father(semid, shmadr);
		(void )wait((int*)0);
	}
	supp_ipc(shmid, semid);
	exit(0);
}