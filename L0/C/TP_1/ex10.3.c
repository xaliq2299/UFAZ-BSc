#include <stdio.h>
#include <math.h>

int main() {
int a, b, c, D;
float x1, x2;

printf("Enter the values for a b and c for the equation of second degree:");
scanf("%d %d %d", &a, &b, &c);
D=b*b-4*a*c;
if (D>0) {
x1=(-b+sqrt(D))/2*a;
x2=(-b-sqrt(D))/2*a;
}
printf("The solutions are %f %f\n", x1, x2);
return 0;
}




