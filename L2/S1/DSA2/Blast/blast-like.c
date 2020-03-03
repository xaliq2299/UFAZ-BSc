/* by Pierre Collet */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

#define REF_SIZE 10000

char w[]="accgagttaga";
char r[REF_SIZE+1];

int score(char c1, char c2){ if (c1==c2) return 1; return -1; }

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
  
  r[0]='c'; r[1]='c'; r[2]='a'; r[3]='a'; r[4]='g'; r[5]='g';
  r[6]='t'; r[7]='c'; r[8]='a'; r[9]='g'; r[10]='t'; r[11]='c';

  int nPosSeq=0,nBestGlobalScore=0,nPositionInWord=0;
  for (int i=0;i<1/*REF_SIZE-strlen(w)*/;i++){
    int nCScore=0, nBestCScore=0, nMinScore=0, nPos=0, nBestPos=0;
    for (int j=0;j<strlen(w);j++){
      nBestGlobalScore+=score(r[i+j],w[j]); nCScore+=score(r[i+j],w[j]);
      if (nCScore>nBestCScore) {nBestCScore=nCScore; nBestPos=nPos;}
      if (nBestGlobalScore<nMinScore) {nMinScore=nBestGlobalScore; nPos=j; nCScore=0;}
printf("nCScore=%d, nBestCScore=%d, nMinScore=%d, nPos=%d, nBestPos=%d, nBestGlobalScore=%d\n",nCScore, nBestCScore, nMinScore, nPos, nBestPos, nBestGlobalScore);
    }
    if (nBestCScore > nBestGlobalScore)
      {nBestGlobalScore=nBestCScore; nPosSeq=i;nPositionInWord=nBestPos;}
printf("Conclusion: nCScore=%d, nBestCScore=%d, nMinScore=%d, nPos=%d, nBestPos=%d, nBestGlobalScore=%d\n",nCScore, nBestCScore, nMinScore, nPos, nBestPos, nBestGlobalScore);
printf("Next position:\n");
  }
  printf ("Position in Sequence=%d\n",nPosSeq);
  printf ("Best Score = %d\n",nBestGlobalScore);
  printf ("Position in Word = %d\n",nPositionInWord);

  return 0;
}
