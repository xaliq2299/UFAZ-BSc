#include <stdio.h>
#include <stdlib.h>  

int n_b(char* addr, int i) {
  return (((char)0x1) & ((char)*(addr + i/8)) >> i%8);
}

char d2c(int n) {
  return (n < 0 ? '?': (n < 10 ? '0'+n : (n < 36 ? 'A' + (n-10) : '?'))); 
}

long long int P2(int n) {
  return (n < 0 ? 0 : (n == 0 ? 1 : 2 * P2(n - 1)));
}

// Functions to complete

void base2(int n) {
}

void baseB(int B, int n) {
}

void mantissa(float f, int result[]) {
}

float mantissa_normalized(float f) {
}

void exponent(float f, int result[]) {
}

int exponent_no_bias(float f) {
}

int sign(float f) {
}

int main() {

  return 0; 
}
