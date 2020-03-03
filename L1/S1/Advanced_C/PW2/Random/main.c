#include "random.h"
#define N 20

int main(){
	srandom( getpid() );

	printf("The value of RAND_MAX: %d\n", RAND_MAX );	
	printf("N=20 calls of random function:\n");
	for(int i=1;i<=N;i++)
		printf("%ld\n", random() );
	printf("Random floating point number between 0 and 1: %f\n", random01() );
	printf("Random floating point number between 0 and 5: %f\n", random0n(5) );
	printf("Toss of one die: %d\n", tossOfOneDice() );
	printf("Toss of two dice: %d\n", tossOfTwoDice() );

	return 0;
}
