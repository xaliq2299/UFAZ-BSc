#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){
	int c, oa=0, ob=0, oc=0;
	while((c=getopt(argc,argv,"a:bc")) != -1){
		switch(c){
			case 'a': oa=1; break;
			case 'b': ob=1; break;
			case 'c': oc=1; break;
			case '?': if(optopt == 'a')
					  printf("Option -%c needs more args\n",optopt);
					  else
					  printf("Unknown option -%c\n", optopt);
			printf("Unknown option -%c \n", optopt); 
			default: printf("GETOPT ");
		}
	}
	printf("A=%d, B=%d and C=%d\n", oa,ob,oc);
	
	return 0;
}
