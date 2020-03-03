/* Fig 9.21: fig09_21.c */
/* Using a scan set */
#include <stdio.h>

/* function main begins program execution */
int main()
{ 
   char z[ 9 ]; 
   printf( "Enter string: " );
   scanf( "%[aeiou]", z ); /* search for set of characters */
   printf( "The input was \"%s\"\n", z );
   return 0; 
}