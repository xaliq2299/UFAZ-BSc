/* Fig. 7.12: fig07_12.c
   Attempting to modify data through a 
   non-constant pointer to constant data. */
#include <stdio.h>
void f( const int *xPtr ); /* prototype */
int main()
{  int y;       /* define y */
   f( &y );     /* f attempts illegal modification */
   return 0;    /* indicates successful termination */
} /* end main */
/* xPtr cannot be used to modify the 
   value of the variable to which it points */
void f( const int *xPtr )
{  *xPtr = 100;  /* error: cannot modify a const object */
} /* end function f */
