#include <stdio.h>
#include <math.h>

double acos(double x);

int main () 
{
double x1, y1, x2, y2;
double cos, alpha;

scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
cos = (x1*x2 + y1*y2) / ( sqrt( x1*x1 + y1*y1 )*sqrt( x2*x2 + y2*y2 ) );
printf("%lf  ", cos);
alpha=acos(cos);

printf("The angle between these two vectors is %.5lf\n", alpha);
return 0;
}
