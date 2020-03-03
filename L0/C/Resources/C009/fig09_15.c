/* Fig 9.15: fig09_15.c */
/* Printing with the 0( zero ) flag fills in leading zeros */
#include <stdio.h>

int main()
{ 
   printf( "%+09d\n", 452 );
   printf( "%09d\n", 452 );
   return 0;
}