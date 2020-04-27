/*Fig 6.3 fig06_03.c
 initializing an array*/
#include<sdtio.h>
int main(void){
int n[10];
int i;
for(i=0;i<10;i++){
	n[i]=0;/*set element at location i to 0*/
}
printf("%s%13s\n","Element","Value");
for(i=0;i<10;i++){
	printf("%7d%13d\n",i,n[i]);
}
return 0;
}