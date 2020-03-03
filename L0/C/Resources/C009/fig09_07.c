/* Fig 9.7: fig09_07.c */
/* Using the p, n, and % conversion specifiers */
#include <stdio.h>

int main()
{  int *ptr;      /* define pointer to int */
   int x = 12345; /* initialize int x */
   int y;         /* define int y */
   ptr = &x;      /* assign address of x to ptr */
   printf( "The value of ptr is %p\n", ptr );
   printf( "The address of x is %p\n\n", &x );
   printf( "Total characters printed on this line:%n", &y );
   printf( " %d\n\n", y );
   y = printf( "This line has 28 characters\n" );
   printf( "%d characters were printed\n\n", y );
   printf( "Printing a %% in a format control string\n" );
   return 0; 
}