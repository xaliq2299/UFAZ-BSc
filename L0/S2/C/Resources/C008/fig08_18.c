/* Fig. 8.18: fig08_18.c
   Using strcpy and strncpy */
#include <stdio.h>
#include <string.h>

int main()
{  char x[] = "Happy Birthday to You"; /* initialize char array x */
   char y[ 25 ]; /* create char array y */
   char z[ 15 ]; /* create char array z */
   /* copy contents of x into y */
   printf( "%s%s\n%s%s\n", 
      "The string in array x is: ", x,
      "The string in array y is: ", strcpy( y, x ) );
   /* copy first 14 characters of x into z. Does not copy null 
      character */
   strncpy( z, x, 14 ); 
   z[ 14 ] = '\0'; /* terminate string in z */
   printf( "The string in array z is: %s\n", z );
   return 0; 
}