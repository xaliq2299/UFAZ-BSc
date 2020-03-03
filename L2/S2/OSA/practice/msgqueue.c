#include <stdio.h>
#include <sys/msg.h>

struct message{
	long mtype;
	int val;
};

int create_queue(){
	key_t k;
	int id;
	k = ftok("/etc/passwd", 'F');
	if(k==-1) perror("ftok");
	id = msgget(k,IPC_CREAT | 0666);
	if(id == -1)
		perror("msgget");
	return id;
}

void write_value(int id, int val){
	struct message m; int r;
	m.mtype=25;
	m.val=val;
	r=msgsnd(id, &m, sizeof m-sizeof m.mtype, 0);
	if(r == -1) perror("msgsnd");
}

int read_value(int id){
	struct message m; int r, val;
	r=msgrcv(id, &m, sizeof m-sizeof m.mtype, 25, 0);
	if(r == -1)
		perror("msgrcv");
	return m.val;
}

int main(){
	int id = create_queue();
	// printf("%d\n", id);
	// int id2 = create_queue();
	// printf("%d\n", id2);
	write_value(id,102);
	int val = read_value(id);
	printf("val=%d\n", val);

	return 0;
}