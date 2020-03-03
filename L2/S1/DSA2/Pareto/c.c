#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float fA[100][2];
int nPareto[100];

int readCSVfile(){
  int i=0;
  FILE *pif;
  pif=fopen("file.csv","r");
  char str[1000], *pIn;
  do{
    fscanf(pif,"%s",str);
    pIn=strtok(str,";");//PointerToString=strtok(PointerToTheString,constCharAS delimiter)
    while(pIn != NULL){
      *(((float *)fA)+(i++))=atof(pIn);
      pIn =strtok(NULL,";"); //to a new data
    }
  } while (fgetc(pif)!=EOF);
  return i;
}

int main(){

  int nNbObjectives=2, nComplexity=0;
  int nNbReadValues=readCSVfile();
  for (int i=0;i<nNbReadValues/2;i++) nPareto[i]=-1;
  for(int i=0;i<nNbReadValues/2;i++){
    printf("%f \t",fA[i][0]);
    printf("%f \t",fA[i][1]);
    printf("\n");
  }

  printf("Calculating the Pareto front\n");

  int nDominant=0, bCandidateIsDominant,bChallengerIsDominant;
  for (int nCandidate=0;nCandidate<nNbReadValues/2;nCandidate++){
    bCandidateIsDominant=1;
    for (int nChallenger=0;nChallenger<nNbReadValues/2;nChallenger++){
      bChallengerIsDominant=1;
      for (int m=0;m<nNbObjectives;m++){
        if (fA[nChallenger][m]>=fA[nCandidate][m]) bChallengerIsDominant=0;
        nComplexity++;
      }
      if (bChallengerIsDominant){
        bCandidateIsDominant=0;
        //break;
      }
    }
    if (bCandidateIsDominant) nPareto[nDominant++]=nCandidate;
  }

  for(int i=0;i<nNbReadValues/2;i++){
    if (nPareto[i]>-1){
      printf("%f \t",fA[nPareto[i]][0]);
      printf("%f \t",fA[nPareto[i]][1]);
      printf("\n");
    }
  }
  printf("Complexity = %d\n",nComplexity);

  printf("\n");
  return 0;
}
