#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 100

int nNB_IND;

float fA[MAX_SIZE][3]; // Objective 1, Objective 2, Nb of dominants

int readCSVfile(){
  int i=0;
  FILE *pif;
  pif=fopen("Bike Pareto Data.csv","r");
  char str[1000], *pIn;
  do{
    fscanf(pif,"%s",str);
    pIn=strtok(str,";");//PointerToString=strtok(PointerToTheString,constCharAS delimiter)
    while(pIn != NULL){
      *(((float *)fA)+(i++))=atof(pIn);
      pIn =strtok(NULL,";"); //to a new data
    }
    *(((float *)fA)+(i++))=0; // initialises the nb of dominants to 0
  } while (fgetc(pif)!=EOF);
  return i;
}

int main(){
  int **nPareto;
  int nNbObjectives=2, nComplexity=0, nNbParetoFront=1;

  int nNbReadValues=readCSVfile();
  nNB_IND=nNbReadValues/(nNbObjectives+1); // +1 is for nb of dominants

  if (!(nPareto = (int**)malloc(nNB_IND*sizeof(int*)))) exit(-1);
  for (int i = 0; i < nNB_IND; i++)
    if (!(nPareto[i] = (int*)malloc(nNB_IND*sizeof(int)))) exit(-1);

  // initialisation of nPareto[][]
  for (int i=0;i<nNB_IND;i++) for (int j=0;j<nNB_IND;j++) nPareto[i][j]=-1;

  printf("Now calculating the Pareto fronts\n");

    int bChallengerIsDominant;
    for(int nCandidate=0;nCandidate<nNB_IND;nCandidate++){
      int nDominated=0;
      for(int nChallenger=0;nChallenger<nNB_IND;nChallenger++){
        if(nCandidate==nChallenger) continue; // to save time
        bChallengerIsDominant=1;
        int nNbObjectivesWhereIDominate=0;
        for(int m=0;m<nNbObjectives;m++){
          if(fA[nChallenger][m]>=fA[nCandidate][m]){
            nNbObjectivesWhereIDominate++;
            bChallengerIsDominant=0;
          }
          if(nNbObjectivesWhereIDominate==nNbObjectives){
            nPareto[nCandidate][nDominated++]=nChallenger;
          }
        }
        if(bChallengerIsDominant) fA[nCandidate][2]++; // counting the
    } }                                                // number of dominants

// All the bookkeeping work has been done!!!

// Printing the pareto fronts
  int nNbRemoved=0, nParetoFrontNb=1;
  while(nNbRemoved<=nNB_IND){
    printf("Pareto front No %d\n",nParetoFrontNb);
    for (int i=0;i<nNB_IND;i++)
      if (fA[i][2]==0){ // I am a dominant !!!
        printf("I am solution %f\t%f\n",fA[i][0],fA[i][1]);
        for(int j=0;j<nNB_IND;j++){
          if(nPareto[i][j]!=-1)
            fA[nPareto[i][j]][2]--;
          else break;
        }
       fA[i][2]=-1; // not a dominant anymore
       nNbRemoved++;
      }
    nParetoFrontNb++;
  }
  return 0;
}