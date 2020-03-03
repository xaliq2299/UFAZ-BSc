#include <stdio.h>
int main() {
  float a = 1e20, b = -1e20, c =  3.14;
  printf("a+(b+c)=%f, (a+b)+c=%f\n", a+(b+c), (a+b)+c);
  return 0;
}
