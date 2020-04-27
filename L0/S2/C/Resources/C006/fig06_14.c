/*Fig 6.14: fig06_14.c
Demonstrating the const type qualifier with arrays*/
#include <stdio.h>
void tryToModifyArray(const int b[]);
int main(void){
int a[]={10,20,30};
tryToModifyArray(a);
printf("%d %d %d\n",a[0],a[1],a[2]);
return 0;
}
/*in function tryToModifyArray, array b is const, so it cannot be
used to modify the original array a in main.*/
void tryToModifyArray(const int b[]){
b[0]/=2;/*error*/
b[1]/=2;/*error*/
b[2]/=2;/*error*/
}