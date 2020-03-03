/* Fig. 7.26: fig07_26.c
   Multipurpose sorting program using function pointers */
#include <stdio.h>
#define SIZE 10
/* prototypes */
void bubble( int work[], const int size, 
             int (*compare)( int a, int b ) );
int ascending( int a, int b );
int descending( int a, int b );
int main()
{  int order;   /* 1 for ascending order or 2 for descending order */
   int counter; /* counter */
   /* initialize array a */
   int a[ SIZE ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
   printf( "Enter 1 to sort in ascending order,\n" 
           "Enter 2 to sort in descending order: " );
   scanf( "%d",  &order );
   printf( "\nData items in original order\n" ); 
   /* output original array */
   for ( counter = 0; counter < SIZE; counter++ ) {
      printf( "%5d", a[ counter ] );
   } /* end for */
   /* sort array in ascending order; pass function ascending as an
     argument to specify ascending sorting order */
   if ( order == 1 ) {
      bubble( a, SIZE, ascending );
      printf( "\nData items in ascending order\n" );
   } /* end if */ 
   else { /* pass function descending */
      bubble( a, SIZE, descending );
      printf( "\nData items in descending order\n" );
   } /* end else */
   /* output sorted array */
   for ( counter = 0; counter < SIZE; counter++ ) {
      printf( "%5d", a[ counter ] );   
   } /* end for */
   printf( "\n" );
   return 0; /* indicates successful termination */
} /* end main */

/* multipurpose bubble sort; parameter compare is a pointer to
   the comparison function that determines sorting order */
void bubble( int work[], const int size, 
             int (*compare)( int a, int b ) )
{  int pass;  /* pass counter */
   int count; /* comparison counter */
   void swap( int *element1Ptr, int *element2ptr ); /* prototype */
   /* loop to control passes */
   for ( pass = 1; pass < size; pass++ ) {
      /* loop to control number of comparisons per pass */
      for ( count = 0; count < size - 1; count++ ) {
         /* if adjacent elements are out of order, swap them */
         if ( (*compare)( work[ count ], work[ count + 1 ] ) ) {
            swap( &work[ count ], &work[ count + 1 ] );
         } /* end if */
      } /* end for */
   } /* end for */
} /* end function bubble */

/* swap values at memory locations to which element1Ptr and 
   element2Ptr point */
void swap( int *element1Ptr, int *element2Ptr )
{  int hold; /* temporary holding variable */
   hold = *element1Ptr;
   *element1Ptr = *element2Ptr;
   *element2Ptr = hold;
} /* end function swap */

/* determine whether elements are out of order for an ascending
   order sort */
int ascending( int a, int b )
{   return b < a;   /* swap if b is less than a */
} /* end function ascending */

/* determine whether elements are out of order for a descending
   order sort */
int descending( int a, int b )
{   return b > a;   /* swap if b is greater than a */
} /* end function descending */
