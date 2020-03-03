/* Fig 9.22: fig09_22.c */
/* Using an inverted scan set */
#include <stdio.h>

int main()
{  char z[ 9 ];
   printf( "Enter a string: " );
   scanf( "%[^aeiou]", z ); /* inverted scan set */
   printf( "The input was \"%s\"\n", z );
   return 0; 
} 