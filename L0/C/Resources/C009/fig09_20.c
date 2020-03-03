/* Fig 9.20: fig09_20.c */
/* Reading characters and strings */
#include <stdio.h>

int main()
{ 
   char x;      
   char y[ 9 ];
   printf( "Enter a string: " );
   scanf( "%c%s", &x, y );
   printf( "The input was:\n" );
   printf( "the character \"%c\" ", x );
   printf( "and the string \"%s\"\n", y );
   return 0; 
}