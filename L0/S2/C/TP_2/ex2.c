#include <stdio.h>
#include <math.h>

int main() {
int x, n;
double result;

printf("Dear user, enter your numbers x and n(to calculate power):");
scanf("%d %d", &x, &n);

result=pow(x,n);

printf("%d to the power %d is %.0lf\n", x, n, result);
return 0;
}
