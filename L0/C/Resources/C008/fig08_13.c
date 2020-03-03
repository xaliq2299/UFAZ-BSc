/* Fig. 8.13: fig08_13.c Using gets and putchar */
#include <stdio.h>
void reverse( const char * const sPtr ); 
int main()
{  char sentence[ 80 ]; /* create char array */
   printf( "Enter a line of text:\n" );
   /* use gets to read line of text */
   gets( sentence ); 
   printf( "\nThe line printed backwards is:\n" );
   reverse( sentence );
   return 0; 
} 

/* recursively outputs characters in string in reverse order */
void reverse( const char * const sPtr )
{  
   /* if end of the string */
   if ( sPtr[ 0 ] == '\0' ) { /* base case */
      return; 
   } /* end if */ 
   else { /* if not end of the string */ 
      reverse( &sPtr[ 1 ] ); /* recursion step */
      putchar( sPtr[ 0 ] ); /* use putchar to display character */
   } /* end else */
}