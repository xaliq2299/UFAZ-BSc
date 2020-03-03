/* Fig. 8.32: fig08_32.c
   Using memmove */
#include <stdio.h>
#include <string.h>

int main()
{ 
   char x[] = "Home Sweet Home"; /* initialize char array x */
   
   printf( "%s%s\n", "The string in array x before memmove is: ", x ); 
   printf( "%s%s\n", "The string in array x after memmove is: ", 
           memmove( x, &x[ 5 ], 10 ) );

   return 0;
} 