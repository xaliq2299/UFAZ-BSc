int square_i(int n){
	int result=0;
	for(int i=1;i<=n;i++)
		result += n;
	return result;
}

float power_i(int n, float x){
	int result=1;
	for(int i=1;i<=n;i++)
		result *= x;
	return result;
}

int sumOfOdd_i(int n){
	int sum=0;
	for(int i=1;i<=n;i++)
		sum += 2*i-1;
	return sum;
}

float sumOfInverse_i(int n){
	float sum=0.0;
	for(int i=1;i<=5;i++)
		sum += 1./i;
	return sum;
}

int howManyTimesSubstract_i(int a, int b){
	int count=0; 
	do{
		a-=b; count++;
	}while(a >= b);
	return count;
}

int divideBy7_i(int n){
	return howManyTimesSubstract_i(n, 7);
}

int magnitude_i(int n){
	int magn=1;
	while(n/10 != 0){
		magn *= 10;
		n/=10;
	}
	return magn;
}

int reverse_i(int n){
	int rev=0;
	while(n != 0){
		rev += magnitude_i(n)*(n%10);
		n /= 10;
	}
	return rev;
}
