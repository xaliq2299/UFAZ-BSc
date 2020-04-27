#include <stdio.h>

int main() {
int a;
printf("enter your number:\n");
scanf("%d", &a);
if (a>0){
printf ("%d is positive\n", a);
}
else if (a==0){
printf ("number is 0\n");
}
else{
printf ("%d is negative\n", a);
}
return 0;
}

