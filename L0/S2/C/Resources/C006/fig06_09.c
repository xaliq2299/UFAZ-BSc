/*Fig 6.9: fig06_09.c
Roll a six-sided die 6000 times*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 7

int main(void){
	int face,roll;
	int frequency[SIZE]={0};
	srand(time(NULL));
	int i, j;
	for(roll=1;roll<=6000;roll++){
		face=1+rand()%6;
		++frequency[face];
	}
	printf("%s%17s\n","Face","Frequency");
	for (face=1;face<SIZE;face++)
		printf("%4d%17\n",face,frequency[face]);
	return 0;
}