/* Fig. 10.7: fig10_07.c
   Printing an unsigned integer in bits */
#include <stdio.h>

void displayBits( unsigned value ); /* prototype */

int main()
{ 
   unsigned x; /* variable to hold user input */

   printf( "Enter an unsigned integer: " );
   scanf( "%u", &x );

   displayBits( x );
   
   return 0; /* indicates successful termination */

} /* end main */

/* display bits of an unsigned integer value */
void displayBits( unsigned value )
{ 
   unsigned c; /* counter */

   /* define displayMask and left shift 31 bits */
   unsigned displayMask = 1 << 31; 

   printf( "%10u = ", value );

   /* loop through bits */ 
   for ( c = 1; c <= 32; c++ ) { 
      putchar( value & displayMask ? '1' : '0' );
      value <<= 1; /* shift value left by 1 */   

      if ( c % 8 == 0 ) { /* output space after 8 bits */
         putchar( ' ' );
      } /* end if */

   } /* end for */

   putchar( '\n' );
} /* end function displayBits */
