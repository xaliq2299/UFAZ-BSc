#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char w[] = "ACCGGGTTTT";

int main(){
  FILE *fp1 = fopen("file", "r");
  char c;
  int count=1;
  while(c = getc(fp1)){
    if(c == '\n')
      count++;
    if(count == 3559)
      break;
  }
  char line[100], *token;
  // c=getc(fp);
  // printf("%c", c);
 
  count=0;
  FILE *fp2 = fopen("gen", "w+");
  if(!fp2) printf("The file couldnt be opened\n");
  while( (c=fgetc(fp1)) != EOF ){
    if(c == 'a' || c == 'c' || c == 'g' || c == 't'){
      fprintf(fp2, "%c", c);
      count++;
    }
  }
  fclose(fp1); fclose(fp2);
  printf("%d\n", count);
  //}
  //int num = fgetchar(fp);
  //printf("%d\n", num);

  return 0;
}
