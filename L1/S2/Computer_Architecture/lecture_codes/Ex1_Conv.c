// Correction of TD 1 exercise 3

#include <stdio.h>
#include <malloc.h>

char d2c(int n) {
  return (n < 0 ? '?': (n < 10 ? '0'+n : (n < 36 ? 'A' + (n-10) : '?'))); 
}

void conversion_base(int *t, int sizet, int n) {
  int i;
  int sizeu;
  int *u;  

  sizeu = (sizet / n) + ((sizet % n == 0) ? 0 : 1);
  u = malloc(sizeof(int) * sizeu);

  for (i = 0; i < sizet; i++) {
    u[i/n] += t[i] << (i%n);
  }

  for (i = sizeu - 1; i >= 0; i--)
    printf("%c", d2c(u[i]));
  printf("\n");

  free(u);
}

int main() {
  //int t[7] = {1, 1, 0, 1, 1, 0, 1};
  //conversion_base(t, 7, 4);
  // ==> 5B
  int t[7] = {1, 0, 0, 1, 0, 0, 1};
  conversion_base(t, 7, 4);
  // ==> 49
}
