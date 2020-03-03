/* Fig. 8.15: fig08_15.c
   Using sprintf */
#include <stdio.h>

int main()
{  char s[ 80 ]; /* create char array */
   int x;        /* x value to be input */
   double y;     /* y value to be input */
   printf( "Enter an integer and a double:\n" );
   scanf( "%d%lf", &x, &y );
   sprintf( s, "integer:%6d\ndouble:%8.2f", x, y );
   printf( "%s\n%s\n", 
           "The formatted output stored in array s is:", s );
   return 0;
}