#include<stdio.h>

int main(void)
{
/*DECLARATION*/
int integer1;/*first number by user*/
int integer2;/*second number by user*/
int sum;/*variable result*/

printf("Welcome to C\n");
printf("Enter First integer\n");
scanf("%d", &integer1);
printf("Enter Second integer\n");
scanf("%d", &integer2); 

sum = integer1 +integer2;

printf("\tSum is %d\n",sum);
printf("\a Thank you\n");
return 0;
}
