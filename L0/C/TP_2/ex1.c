#include <stdio.h>

int main() {
long n, a, product=1;

printf("Enter any integer:\n");
scanf("%ld", &n);

if (n>0) {
for(a=1; a<=n; a++)
        product=product*a;
printf("%ld!=%ld\n", n, product);
}
else if (n==0) {
printf("0!=1\n");
}
else {
printf("factorials for negative numbers doesn`t exist!!!\n");
}
return 0;
}



