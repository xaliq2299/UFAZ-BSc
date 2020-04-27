/* Fig. 8.6: fig08_06.c
   Using atof */
#include <stdio.h>
#include <stdlib.h>

int main()
{  double d; /* variable to hold converted string */
   d = atof( "99.0" ); 
   printf( "%s%.3f\n%s%.3f\n",
           "The string \"99.0\" converted to double is ", d,
           "The converted value divided by 2 is ", 
           d / 2.0 );
   return 0; /* indicates successful termination */
} /* end main */