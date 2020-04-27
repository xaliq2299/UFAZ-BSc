/* Fig. 7.10: fig07_10.c
   Converting lowercase letters to uppercase letters
   using a non-constant pointer to non-constant data */
#include <stdio.h>
#include <ctype.h>
void convertToUppercase( char *sPtr ); /* prototype */
int main()
{  char string[] = "characters and $32.98"; /* initialize char array */
   printf( "The string before conversion is: %s", string );
   convertToUppercase( string );
   printf( "\nThe string after conversion is: %s\n", string );      
   return 0; /* indicates successful termination */
} /* end main */
/* convert string to uppercase letters */
void convertToUppercase( char *sPtr )
{  while ( *sPtr != '\0' ) { /* current character is not '\0' */ 
      if ( islower( *sPtr ) ) {    /* if character is lowercase, */
         *sPtr = toupper( *sPtr ); /* convert to uppercase */
      } /* end if */
      ++sPtr;  /* move sPtr to the next character */
   } /* end while */
} /* end function convertToUppercase */
