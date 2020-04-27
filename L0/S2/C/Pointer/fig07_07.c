/* Fig. 7.7: fig07_07.c
   Cube a variable using call-by-reference with a pointer argument */
#include <stdio.h>
void cubeByReference( int *nPtr ); /* prototype */
int main()
{  int number = 5; /* initialize number */
   printf( "The original value of number is %d", number );
   /* pass address of number to cubeByReference */
   cubeByReference( &number );
   printf( "\nThe new value of number is %d\n", number );
   return 0; /* indicates successful termination */
} /* end main */
/* calculate cube of *nPtr; modifies variable number in main */
void cubeByReference( int *nPtr )
{  *nPtr = *nPtr * *nPtr * *nPtr;  /* cube *nPtr */
} /* end function cubeByReference */
