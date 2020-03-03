#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float fA[100][2];

int readCSVfile(){
  int i=0;
  FILE *pif;
  pif=fopen("file.csv","r");
  char str[1000], *pIn;
  do{
    fscanf(pif,"%s",str);
    pIn=strtok(str,";");//PointerToString=strtok(PointerToTheString,constCharAS delimiter)
    while(pIn != NULL){
      *((float*)fA+(i++))=atof(pIn);
      pIn =strtok(NULL,";"); //to a new data
    }
  } while (fgetc(pif)!=EOF);
  return i;
}

/*      fA[i][0]=atof(pIn);
      pIn =strtok(NULL,";"); //to a new data
      fA[i][1]=atof(pIn);
      pIn =strtok(NULL,";"); //to a new data
      i++;
*/

int main(){
  int nNbReadValues=readCSVfile();
  for(int i=0;i<nNbReadValues/2;i++){
  		  printf("%f \t",fA[i][0]);
  		  printf("%f \t",fA[i][1]);
	  printf("\n");
  }
 
  int nPareto[9], nDominant=0, d=0, bCandidateIsDominant, bChallengerIsDominant, nNbObjectives=2;
  for(int i=0;i<nNbReadValues/2;i++) nPareto[i]=-1;
  
  for(int nCandidate=0;nCandidate<nNbReadValues/2;nCandidate++){
  	bCandidateIsDominant=1;
  	for(int nChallenger=0;nChallenger>=nNbReadValues/2;nChallenger++){
  		bChallengerIsDominant = 1;
  		for(int m=0;m<nNbObjectives;m++){
  			if(fA[nChallenger][m] >= fA[nCandidate][m])
  				bChallengerIsDominant=0;
  		}
  		if(bChallengerIsDominant){
  			bCandidateIsDominant=0;
  			break;
  		}
  		if(bCandidateIsDominant)
  			nPareto[d++]=nCandidate;
  	}

  }

  return 0;
}

/*
int main(){
	FILE *fp = fopen("file.csv", "r");
	if(fp == NULL){
		printf("%s\n", "FILE couldn't be opened");
		return 1;
	}
	
	char str[100], *pIn;
	int n;
	float data[n][2];

	while(!feof(fp)){
		fscanf(fp, "%f", &data[0][i]);
		float pareto[n] = {0};
	}
	
	fscanf(fp, "%s", str);
	new = strtok(str, ';');
	int i=0;
	
	while(new != NULL){
		data[i++] = atoi(new);
		new = strtok(NULL, ";");
	}

	return 0;
}
*/