#include <stdio.h>
#include <math.h>

int main() {
float p, r;
int year;
double a;
r=0.05;
p=1000.00;
printf("%s =>%s\n", "Year", "YourMoney");
for(year=1;year<=10;year++) {
a=p*pow( (1.0+r) , year);
printf("%d => %f\n", year, a);
}
return 0;
}
