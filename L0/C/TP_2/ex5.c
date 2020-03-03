#include <stdio.h>

int main()
{
int a, b, counter, result=0;
printf("Enter your numbers to multiply them:\n");
scanf("%d %d", &a, &b);
for(counter=1;counter<=a;counter++){
result=result+b;
}
printf("%d multiply by %d is %d\n", a, b, result);
return 0;
}
