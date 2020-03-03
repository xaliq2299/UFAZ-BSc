/* by Pierre Collet */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

#define REF_SIZE 11000

char w[]="ACCGGGTTTT";
char r[REF_SIZE];
char nt[]={'A','C','G','T'};

int main(){
//to create a random string
//srand(time(NULL)); for (int i=0;i<REF_SIZE-1;i++) r[i]= nt[rand()%4];  

  FILE *pIF; pIF=fopen("DNACervisiaeSaccharomyces","r");
  char temp[1000], w1[11], w2[11], w3[11], w4[11], w5[11], w6[11];

  for (int i=0;i<3558;i++) fscanf(pIF,"%[^\n]\n",temp); // reads 3558 lines
  fscanf(pIF,"%s",temp); // reads '1' at the beginning of the line
  int nPos=0;

  for (int i=0;i<166;i++){ // reads i*60 characters  166 gives 9960
    fscanf(pIF,"%s %s %s %s %s %s\n%s",w1,w2,w3,w4,w5,w6,temp);
    strcat(r,w1); strcat(r,w2); strcat(r,w3);
    strcat(r,w4); strcat(r,w5); strcat(r,w6);
  }
  fscanf(pIF,"%s %s %s %s",w1,w2,w3,w4); // to which we add 40 characters
  strcat(r,w1); strcat(r,w2); strcat(r,w3); strcat(r,w4);

  printf("r= %s\n",r);
  printf("r length = %lu\n",strlen(r));


  return 0;
}

