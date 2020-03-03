#include <stdio.h>
#include <math.h>

int main () {
float a, b, c, D, x1, x2, x, d, real1, real2, imaginary1, imaginary2;
int h=-1;

printf ("enter the coefficients of your quadratic equation:");
scanf ("%f %f %f", &a, &b, &c);
D=b*b-4*a*c;

if (D>0) {
x1=(-b-sqrt(D))/2*a;
x2=(-b+sqrt(D))/2*a;
printf("The roots are %f %f\n", x1, x2);
}
else if (D==0) {
x=-b/2*a;
printf("We have only one root as D=0: %f\n", x);
}
else {
d=D*h;
real1=-b/2*a;
imaginary1=sqrt(d)/2*a;
real2=-b/2*a;
imaginary2=sqrt(d)/2*a;
printf("root number 1 is %f+%fi\n", real1, imaginary1);
printf("root number 2 is %f-%fi\n", real2, imaginary2);
}
return 0;
}

