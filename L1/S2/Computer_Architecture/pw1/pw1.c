#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n_b(char* addr, int i) { //endianness
  return (((char)0x1) & ((char)*(addr + i/8)) >> i%8);
}

char d2c(int n) { // is used to convert a decimal number to another base
  return (n < 0 ? '?': (n < 10 ? '0'+n : (n < 36 ? 'A' + (n-10) : '?'))); 
}

long long int P2(int n) { //can't calculate power for <0 numbers
  return (n < 0 ? 0 : (n == 0 ? 1 : 2 * P2(n - 1)));
}

// Functions to complete
void base2(int n) {
	if(n != 0){
		int r = n%2;
		base2(n/2);
		printf("%d", r);
	}
}

void baseB(int B, int n) {
	if(n != 0){
		int r = d2c(n%B);
		baseB(B, n/B);
		printf("%c", r);
	}
}

void mantissa(float f, int result[]) {
	for(int i=0;i<23;i++)
		result[22-i] = n_b((char*)&f, i);
}

float mantissa_normalized(float f) {
	float ans = 0.0;
	int M[23];
	mantissa(f, M);
	for(int i=0;i<23;i++)
		ans+=M[i]*pow(2, -i-1);
	
	return ans;
}

void exponent(float f, int result[]) {
	for(int i=23;i<31;i++)
		result[30-i] = n_b((char*)&f, i);	
}

int exponent_no_bias(float f) {
	int ans = 0;
	int E[8];
	exponent(f, E);
	for(int i=7;i>0;i--)
		ans += E[7-i]*P2(i);
	
	return ans;
}

int sign(float f) {
	return n_b((char*)&f, 31);
}

int main() {
	float fVal;
	scanf("%f", &fVal);
	for(int i=0;i<32;i++)	
		printf("%d", n_b((char*)&fVal, i) );
	puts("");
	
	float M = mantissa_normalized(fVal); 
	int E = exponent_no_bias(fVal);
 	int S = sign(fVal);
 	
 	printf("%f\n", pow(-1, S)*(1+M)*P2(E-127) );				 	
	return 0;
}
