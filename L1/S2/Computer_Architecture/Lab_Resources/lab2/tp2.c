#include <stdio.h>

#define BIT(A, B) ((A >> B) & 0x1)

long long int P2(int n) {
  return (n < 0 ? 0 : (n == 0 ? 1 : 2 * P2(n - 1)));
}

// Question 2
int F2(int args) {
}

int F3(int args) {
}

int F4(int args) {
}

// Question 3

void truth2var(int (*func)(int)) {
}

// Question 4
void truthNvar(int N, int (*func)(int)) {
}

// Question 5

void disj_norm_form(int N, int (*func)(int)) {
}

int main() {

  return 0;  
}
