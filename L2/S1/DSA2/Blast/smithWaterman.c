#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int score(char c1, char c2){if(c1==c2) return 3; return -3;}

int takeMax(int n1, int n2, int n3){
	if((n1>=n2)&&(n1>=n3)&&(n1>=0))	return n1;
	if((n2>=n1)&&(n2>=n3)&&(n2>=0)) return n2;
	if((n3>=n2)&&(n3>=n1)&&(n3>=0)) return n3;
	return 0;
}


#define REF_SIZE 10000

char w[]="accgagttaga";
char r[REF_SIZE+1];

//int score(char c1, char c2){ if (c1==c2) return 1; return -1; }

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
  //Smith-Waterman here
 
  int **mat, nNbCol=strlen(r)+1, nNbLin=strlen(w)+1;
  if((mat = (int**)malloc(nNbLin*sizeof(int*))) == NULL){
  	fprintf(stderr, "Memory allocation error");
  	exit(1);
  }
  for(int i=0;i<nNbLin;i++){
  	 if((mat[i] = (int*)malloc(nNbCol*sizeof(int*))) == NULL){
  	 	fprintf(stderr, "Memory allocation error");
  		exit(1);
  	}
  }
  for(int i=0;i<nNbCol;mat[0][i++]=0);
  for(int i=0;i<nNbLin;mat[i++][0]=0);
  for(int i=0;i<nNbCol;printf("%d - ", mat[0][i++]) );
  for(int i=0;i<nNbLin;printf("%d", mat[i++][0]) );
  printf("\n");

  for(int nL=1;nL<nNbLin;nL++)
  	for(int nC=1;nC<nNbCol;nC++){
  		mat[nL][nC]=takeMax(mat[nL][nC]+score(w[nL-1],r[nC-1]), 
  							mat[nL][nC-1]-2,
  							mat[nL-1][nC]-2);
  	}

  for(int i=0;i<10;i++){
  	for(int j=0;j<nNbLin-1;j++) printf("%2d ", mat[i][j]);
//  		printf("%s\n", ); //do it by yourseld and + backtracking
  }
  printf ("Position in Sequence=%d\n",nPosSeq);
  printf ("Best Score = %d\n",nBestGlobalScore);
  printf ("Position in Word = %d\n",nPositionInWord);
  
  return 0;
}
