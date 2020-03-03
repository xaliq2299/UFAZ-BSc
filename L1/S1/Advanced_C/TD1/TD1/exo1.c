#include <stdio.h>

int factorial(int n){
	int static i = 1;
	if(i == 1) printf("Hello world\n"); i++;
	if(n == 0)	return 1;
	else return n*factorial(n-1);
}

int square(int n){
	if(n == 0)	return 0;
	else if(n == 1)  return 1;
	else  return 2*square(n-1)-square(n-2)+2;
}

float power(int n, float x){
	if(n == 0) return 1;
	else return x*power(n-1, x);
}

int sumOfOdd(int n){
	if(n == 0)	return 0;
	else  return 2*n+sumOfOdd(n-1)-1;
}

int units(int n){
	return n%10;
}

int allButUnits(int n){
	return n/10;
}

int magnitude(int n){
	if(n>=0 && n<=9)	return 1;
	else  return 10*magnitude(allButUnits(n));
}

int reverse(int n){
	if(n>=0 && n<=9)	return units(n);
	else return units(n)*magnitude(n)+reverse(allButUnits(n));
}
