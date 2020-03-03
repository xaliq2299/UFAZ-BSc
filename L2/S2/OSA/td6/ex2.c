// remember
#include <stdio.h>

#define RELATIVE_ADDRESS(s,c) (size_t) (&((struct toto*)0)->c)

struct toto{
	char c; char *pc; int i;
};

int main(){
	struct toto v;
	
	printf("%lu\n", (size_t) (&((struct toto*)0)->c));
	
	printf("%lu\n", RELATIVE_ADDRESS(v,c) );
	printf("%lu\n", RELATIVE_ADDRESS(v,pc) );
	printf("%lu\n", RELATIVE_ADDRESS(v,i) );

	return 0;
}