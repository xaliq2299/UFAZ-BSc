#include <stdio.h>

//print num is even, or it's odd
void isEven(int num){
	if (num%2==0) 
		printf("Number is even\n");
	else 
		printf("Number is odd");
}


//returns 1 if n is prime, 0 if it's not
int isPrime(int n){
	if(n<=0) printf("The integer is negative!");
	for(int a=2; a<=n/2; a++){
		if(n%a==0) return 0;
	}
	return 1;
}

int main(){
	int a,b;
	float res;
	printf("Please enter two integers: ");
	scanf("%d %d", &a, &b);
	res=(float) a/b;
	printf("Integer part of division is: %d\nDecimal part of division is: %.3f\n", a/b, (res - a/b));
	printf("----------------------------\n");
	int e;
	printf("Please enter an integer to verify even or odd: ");
	scanf("%d", &e);
	isEven(e);
	printf("----------------------------\n");
	int p;
	printf("Please enter an integer to verify even or odd: ");
	scanf("%d", &p);
	printf("The result of prime or not is: %d\n",isPrime(p));
	printf("----------------------------\n");
	char text[32] = {0};
	printf("Enter a string: ");
	scanf("%s", text);
	printf("%s in reverse order is -> ", text);
	for(int a=31; a>=0; a--) printf("%c", text[a]);
	printf("\n");
	return 0;
}