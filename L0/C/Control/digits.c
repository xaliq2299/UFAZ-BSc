#include <stdio.h>

int main () {
int a=0;
int sum=0;
int numb;
printf("Enter any positive number:\a");
scanf("%d", &numb);
while ( numb > 0 ) { 
	a=a+1;
	sum=sum+(numb%10);
	numb=numb/10;
}
printf("The number of digits in this number is %d\n", a);
printf("The sum of digits in this number is %d\n", sum);
return 0;
}

