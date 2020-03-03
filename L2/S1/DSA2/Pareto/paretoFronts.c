#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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

  int nNbObjectives=2, nComplexity=0, nNbParetoFront=1;
  int nNbReadValues=readCSVfile();
  int nNbIndividualsToRank=nNbReadValues/nNbObjectives;
  for (int i=0;i<nNbReadValues/2;i++) nPareto[i]=-1;
  for(int i=0;i<nNbReadValues/2;i++){
    printf("%f \t",fA[i][0]);
    printf("%f \t",fA[i][1]);
    printf("\n");
  }

int numberOfIndividuals=nNbIndividualsToRank;

    int nDominant=0, bCandidateIsDominant,bChallengerIsDominant;

 while(numberOfIndividuals>0){
        for(int nCandidate=0;nCandidate<numberOfIndividuals;nCandidate++){
            bCandidateIsDominant=1;
            for(int nChallenger=0;nChallenger<numberOfIndividuals;nChallenger++){
            //    if(nCandidate==nChallenger)       continue;
                bChallengerIsDominant=1;
                for(int m=0;m<nNbObjectives;m++)
                    if(fA[nChallenger][m]>=fA[nCandidate][m]) bChallengerIsDominant=0;
            if(bChallengerIsDominant){
                bCandidateIsDominant=0;
            // break;
            } 
        }
            if(bCandidateIsDominant) nPareto[nDominant++]=nCandidate;
        }
        printf("Rank is: %d\n",nNbParetoFront++);
        for(int j=0;j<21;j++){
            if(nPareto[j]>-1){
                printf("%f\t",fA[nPareto[j]][0]);
                printf("%f\n",fA[nPareto[j]][1]);
            }
        }

        for(int j=0;j<21;j++){
            int k=0;
            for(;k<21;k++) 
                if(nPareto[k]==(numberOfIndividuals-1)){ 
                    numberOfIndividuals--;
                    nPareto[k]=-1;
                    k=0;
                }
            if(nPareto[j]>-1){
                fA[nPareto[j]][0]=fA[numberOfIndividuals-1][0];
                fA[nPareto[j]][1]=fA[numberOfIndividuals-1][1];
                numberOfIndividuals--;
                }
            }
          for(int j=0;j<21;j++) nPareto[j]=-1;
    } 
/* 
  while(nNbIndividualsToRank>0){
    int nDominant=0, bCandidateIsDominant,bChallengerIsDominant;
    for (int nCandidate=0;nCandidate<nNbIndividualsToRank;nCandidate++){
      bCandidateIsDominant=1;
      for (int nChallenger=0;nChallenger<nNbIndividualsToRank;nChallenger++){
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

    printf("Pareto front %d is:\n",nNbParetoFront++);

    for(int i=0;i<21;i++){
      for (int k=0; k<21; k++)
        if (nPareto[k]==nNbIndividualsToRank-1){
          printf("%f \t",fA[nPareto[k]][0]);
          printf("%f \t",fA[nPareto[k]][1]);
          printf("\n");
          nPareto[k]=-1;
          nNbIndividualsToRank--;
          k=0;
        }
      if (nPareto[i]>-1){
        printf("%f \t",fA[nPareto[i]][0]);
        printf("%f \t",fA[nPareto[i]][1]);
        printf("\n");
        // deleting the individual
        fA[nPareto[i]][0]=fA[nNbIndividualsToRank-1][0];
        fA[nPareto[i]][1]=fA[nNbIndividualsToRank-1][1];
        //for (int k=0;k<nNbIndividualsToRank;k++)
          //if (nPareto[k]==nNbIndividualsToRank)
            //nPareto[k]=i;
//        nPareto[i]=nPareto[nNbIndividualsToRank-1];
        //i=0;
        nNbIndividualsToRank--;
      }
    }
    // Reinitializing the pareto front
    for (int i=0;i<nNbIndividualsToRank;i++) nPareto[i]=-1;

  }
  printf("Complexity = %d\n",nComplexity);
*/
  printf("\n");
  return 0;
}
