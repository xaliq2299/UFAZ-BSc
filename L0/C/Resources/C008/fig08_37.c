/* Fig. 8.37: fig08_37.c
   Using strerror */
#include <stdio.h>
#include <string.h>

int main()
{ 
   printf( "%s\n", strerror( 2 ) ); 

   return 0;

} /* end main */