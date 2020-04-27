#include <stdio.h>

void myfunc(int a, int b, int c) {
   char buffer1[2];
   char *ret;

   ret = buffer1 + 14;
   /* (*ret) += ... ; */
   printf("%04x\n",ret);
}

int main(void) {
  int x;

  x = 0;
  myfunc(1,2,3);
  x = 1;
  printf("%d\n",x);
}
