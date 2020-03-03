#include <stdio.h>
#include <math.h>

int main() {
float DIST;
int Xa, Ya, Xb, Yb;

printf("Enter the coordinates x and y for point A:\n");
scanf("%d %d", &Xa, &Ya);
printf("Enter the coordinates x and y for point B:\n");
scanf("%d %d", &Xb, &Yb);
DIST=sqrt(pow(Xa-Xb, 2)+pow(Yb-Ya, 2));

printf("distance between A and B is %f\n", DIST);
return 0;
}
