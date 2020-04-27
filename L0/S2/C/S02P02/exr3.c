#include<stdio.h>
#define NB_MAX 31

void fill(unsigned int t[NB_MAX]){
	int i=1;
	t[0]=1;
	while(i<NB_MAX){
		t[i]=t[i-1]*2;
		i++;
	}
}

void keyboard(){
	char c;
	int choice,i=0;
	unsigned int n, t[NB_MAX];
	fill(t);
	while(!0){
		choice=0;
		printf("Enter 0 or 1:");
		while(!choice)
		{
			c=getchar();
			choice=((c=='0')||(c=='1'));
		}
		if(c=='1')
			n+=t[i];
		i++;
		printf("Valeur courante:%d\n",n);
	}
}

int main(){
	keyboard();
	return 0;
}
