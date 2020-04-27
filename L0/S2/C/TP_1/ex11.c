/*A program dealing with Physics, calculate the force of gravity*/
#include <stdio.h>

int main (){
float g=9.81, m, W;
printf("Enter the mass of an object:\n");
scanf("%f", &m);
W=m*g;
printf("The force of gravity for this object is %.2f N\n", W);
return 0;
}
