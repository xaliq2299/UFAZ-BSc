/*Fig 6.4 fig06_04.c
 initializing an array with an initializer list*/
#include<sdtio.h>
int main(void){
int n[10]={32,27,25,25,26,45,64,45,9,10};
int i;

printf("%s%13s\n","Element","Value");
for(i=0;i<10;i++){
	printf("%7d%13d\n",i,n[i]);
}
return 0;
}