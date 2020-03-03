/* Fig. 7.16: fig07_16.c
   Sizeof operator when used on an array name
   returns the number of bytes in the array. */
#include <stdio.h>

size_t getSize( float *ptr ); /* prototype */

int main()
{
   float array[ 20 ]; /* create array */

   printf( "The number of bytes in the array is %li"
           "\nThe number of bytes returned by getSize is %li\n",
           sizeof array, getSize( array ) );

   return 0; /* indicates successful termination */

} /* end main */

/* return size of ptr */
size_t getSize( float *ptr )
{
   return sizeof ptr ;

} /* end function getSize */
