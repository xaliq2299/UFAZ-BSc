/* Fig 9.14: fig09_14.c */
/* Using the # flag with conversion specifiers 
   o, x, X and any floating-point specifier */
#include <stdio.h>

int main()
{  int c = 1427;      /* initialize c */
   double p = 1427.0; /* initialize p */
   printf( "%#o\n", c );
   printf( "%#x\n", c );
   printf( "%#X\n", c );
   printf( "\n%g\n", p );
   printf( "%#g\n", p );
   return 0;
}