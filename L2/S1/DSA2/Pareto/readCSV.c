#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float fA[100];

int readCSVfile(){
  int i=0;
  FILE *pif;
  pif=fopen("file.csv","r");
  char str[1000], *pIn;
  do{
    fscanf(pif,"%s",str);
    pIn=strtok(str,";");//PointerToString=strtok(PointerToTheString,constCharAS delimiter)
    while(pIn != NULL){
      fA[i++]=atof(pIn);
      pIn =strtok(NULL,";"); //to a new data
    }
  } while (fgetc(pif)!=EOF);
  return i;
}

int main(){
  int nNbReadValues=readCSVfile();
  for(int i=0;i<nNbReadValues;i++)
    printf("%f \t",fA[i]);
  printf("\n");
  return 0;
}
