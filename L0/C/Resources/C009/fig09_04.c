/* Fig 9.4: fig09_04.c */
/* Printing floating-point numbers with  
   floating-point conversion specifiers */

#include <stdio.h>

int main()
{  printf( "%e\n", 1234567.89 );
   printf( "%e\n", +1234567.89 );
   printf( "%e\n", -1234567.89 );
   printf( "%E\n", 1234567.89 );
   printf( "%f\n", 1234567.89 );
   printf( "%g\n", 1234567.89 );
   printf( "%G\n", 1234567.89 );
   return 0; /* indicates successful termination */
} 