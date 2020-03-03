//1st part
int units(int n){
	return n%10;
}

int allButUnits(int n){
	return n/10;
}

int square_r(int n){
	if(n == 0)	return 0;
	else if(n == 1)  return 1;
	else  return 2*square_r(n-1)-square_r(n-2)+2;
}

int magnitude_r(int n){
	if(n>=0 && n<=9)	return 1;
	else  return 10*magnitude_r(allButUnits(n));
}

int mostSignificantDigit(int n){
	return n/magnitude_r(n);
}

int middle(int n){
	n=allButUnits(n);
	return ( n-mostSignificantDigit(n)*magnitude_r(n) );
}

int palindrome(int n){
	if(n < 10)  return 1;
	else{
		if(units(n) == mostSignificantDigit(n) )
			palindrome(middle(n));
		else
			return 0;
	}
}

int reverse_r(int n){
	if(n>=0 && n<=9) return n;
	else   return units(n)*magnitude_r(n) + reverse_r(allButUnits(n));
}

//2nd part
float power_r(int n, float x){
	if(n == 1)	return x;
	else 	return x*power_r(n-1, x);
}

int sumOfOdd(int n){
	if(n == 0)	return 0;
	else  return 2*n+sumOfOdd(n-1)-1;
}

float sumOfInverse_r(int n){
	if(n == 1) return 1;
	else 	   return 1/(float)n + sumOfInverse_r(n-1);
}

int howManyTimesSubstract_r(int a, int b){
	if(a < b)   return 0;
	else   return 1+howManyTimesSubstract_r(a-b, b);
}

int divideBy7(int n){
	if(n < 7) return n;
	else  divideBy7(n-7);
}
