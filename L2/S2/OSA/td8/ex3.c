#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

#define MAX 1024

struct protocol{
	long dest; long source;
	char rest[1];
};

int open(key_t key){
	int msqid;
	msqid = msgget(key, 0);
	return msqid;
}

int send(int msqid, int me, int him, void *message, size_t size){
	struct protocol *p;
	p = malloc(sizeof(struct protocol)+size-1);
	if(p == NULL) return -1;
	p->dest = him;
	p->source = me;
	memcpy(p->rest, message, size);

	if(msgsnd(msqid, p, size+sizeof(p->source), 0) == -1)
		return -1;

	free(p);
	return 0;
}

int receive(int msqid, int me, int *him, void *message, size_t *size){
	struct protocol *p;
	int l;

	p=malloc(sizeof(struct protocol)+ *size-1);
	if(p == NULL)	return -1;
	l = msgrcv(msqid, p, *size+sizeof(p->source), me, 0);
	if(l == -1) { free(p); return -1; }
	*him = p->source;
	*size = l - sizeof(p->source);
	memcpy(message, p->rest, *size);
	free(p);
	return 0;
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

int create(key_t key){
	int msqid = msgget(key, IPC_CREAT|0666);
	return msqid;
}

void main(int argc, char **argv){
	int me, him;
	size_t l;
	key_t k;
	int msqid;
	char line[MAX]; char msg[MAX];
	me = atoi(argv[1]);
	if(me == 0){
		fprintf(stderr, "usage: %s <n>", argv[0]); exit(1);
	}
	k = 0x12345678;
	msqid = create(k);
	while(printf("> ", read_line(line, sizeof line)) != EOF){
		switch(*line){
			case 's': sscanf(line+1, "%d %s", &him, msg);
			l = strlen(msg);
			if(send(msqid, me, him, msg, strlen(msg+1)) == -1){
				perror(" "); exit(1);
			}
			printf("message sent\n");
			break;

			case 'r': l=MAX;
			if(receive(msqid, me, &him, msg, &l) == -1){
				perror(""); exit(1); }
				printf("msg received from %d: %s\n", him, msg);
				break;
			
			case '\0': break;
			default: 
				printf("s <n> <msg> \t send message to processes n\n");
				printf("r \t receive message\n");
				break;
		}
	}
	exit(0);
}