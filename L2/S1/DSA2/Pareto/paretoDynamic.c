#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 100

int nNB_IND;

float fA[MAX_SIZE][3]; // Objective 1, Objective 2, Nb of dominants

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
        for(int m=0;m<nNbObjectives;m++){
          int nNbObjectivesWhereIDominate=0;
          if(fA[nChallenger][m]>=fA[nCandidate][m]){
            nNbObjectivesWhereIDominate++;
            bChallengerIsDominant=0;
 //           nPareto[nCandidate][nDominated++]=nChallenger;
          }
          if(nNbObjectivesWhereIDominate == nNbObjectives)
            nPareto[nCandidate][nDominated++]=nChallenger;
          if(bChallengerIsDominant) fA[nCandidate][2]++; // counting the
    } }                                                // number of dominants
    //All the bookkeeping work as been dome

  //Printing the first pareto front
  
  int nNbRemoved=0;
  while(nNbRemoved<=nNB_IND){
    for (int i=0;i<nNB_IND;i++){
      if (fA[i][2]==0) { //I am a dominant
        printf("I am solution %f\t%f\n",fA[i][0],fA[i][1]);
        printf("and I dominate: ");
        for(int j=0;j<nNB_IND;j++){
          if(nPareto[i][j])
            printf("(%f,%f) ", fA[nPareto[i][j]][0], fA[nPareto[i][j]][1]);
          else
            break;
          printf("\n");
        }
      }
    }
}}
  return 0;
}

/*


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
                if(nPareto[k]==(nNB_IND-1)){ 
                    nNB_IND--;
                    nPareto[k]=-1;
                    k=0;
                }
            if(nPareto[j]>-1){
                fA[nPareto[j]][0]=fA[nNB_IND-1][0];
                fA[nPareto[j]][1]=fA[nNB_IND-1][1];
                nNB_IND--;
                }
            }
          for(int j=0;j<21;j++) nPareto[j]=-1;
    } 
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
  printf("\n");
  return 0;
}
*/
