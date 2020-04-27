#include <stdio.h>

int main() {
int a, b, c, D;

printf("Enter the values for a b and c for the equation of second degree:");
scanf("%d %d %d", &a, &b, &c);
D=b*b-4*a*c;
printf("D is %d\n", D);
return 0;
}

