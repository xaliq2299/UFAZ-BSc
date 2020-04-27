#include <stdio.h>

int main() {
float euro, manat;

printf("enter your money in euros:\n");
scanf("%f", &euro);

manat=1.9445*euro;

printf("%.2f\n", manat);
return 0;
}
