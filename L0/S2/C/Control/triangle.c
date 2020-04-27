#include <stdio.h>
#include <math.h>

int main() {
float x1, y1, x2, y2, x3, y3, a, b, c, p, S;

printf("enter the coordinates of the points for triangle respectively:\n");
scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);

a=sqrt(pow( (x2-x1),2)+pow( (y2-y1),2));
b=sqrt(pow( (x3-x2),2)+pow( (y3-y2),2));
c=sqrt(pow( (x3-x1),2)+pow( (y3-y1),2));
p=a+b+c;
S=sqrt(p/2*(p/2-a)*(p/2-b)*(p/2-c));

printf("P=%.4f\n", p);
printf("A=%.4f\n", S);
return 0;
}
