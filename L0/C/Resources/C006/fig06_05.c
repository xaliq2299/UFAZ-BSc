/*Fig 6.5 fig06_05.c
 initialize the element of array s to the even integers from 2 to 20*/
#include<sdtio.h>
#define SIZE 10
int main(void){
int s[SIZE];
int j;
for(j=0;j<SIZE;j++){
	s[j]=2+2*j;
}
printf("%s%13s\n","Element","Value");
for(j=0;j<SIZE;j++){
	printf("%7d%13d\n",j,s[j]);
}
return 0;
}