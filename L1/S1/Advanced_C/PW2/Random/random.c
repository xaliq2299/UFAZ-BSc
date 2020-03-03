#include "random.h"
#include <stdlib.h>

float random01(){
	return (float)random()/RAND_MAX;
}

float random0n(int n){
	return n*random01();
}

int tossOfOneDice(){
	return (int)random0n(6)+1;
}

int tossOfTwoDice(){
	return tossOfOneDice()+tossOfOneDice();
}
