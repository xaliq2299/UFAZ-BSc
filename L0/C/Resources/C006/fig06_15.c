/*Fig 6.15: fig06_15.c
This program sorts an array's values into ascending order*/
#include <stdio.h>
#define SIZE 10
int main(void){
int a[SIZE]={2,6,4,8,10,12,89,68,45,37};
int pass, i, hold;
printf("Data items in original order\n");
for (i=0;i<SIZE;i++)
printf("%4d",a[i]);

for(pass=1;pass<SIZE;pass++){
for (i=0;i<SIZE-1;i++){
if (a[i]>a[i+1]){
hold =a[i];
a[i]=a[i+1];
a[i+1]=hold;
}
}
printf("\n Data items in ascending order\n");

for(i=0;i<SIZE;i++)
printf("%4d",a[i]);
}
printf("\n");
return 0;
}