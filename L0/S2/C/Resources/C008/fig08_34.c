/* Fig. 8.34: fig08_34.c
   Using memchr */
#include <stdio.h>
#include <string.h>

int main()
{ 
   const char *s = "This is a string"; /* initialize char pointer */

   printf( "%s\'%c\'%s\"%s\"\n", 
           "The remainder of s after character ", 'r', 
           " is found is ", memchr( s, 'r', 16 ) );

   return 0;

} /* end main */