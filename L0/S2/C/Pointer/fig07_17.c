/* Fig. 7.17: fig07_17.c
   Demonstrating the sizeof operator */
#include <stdio.h>
int main()
{  char c;           
   short s;         
   int i;       
   long l;         
   float f;        
   double d;         
   long double ld;   
   int array[ 20 ];  /* create array of 20 int elements */
   int *ptr = array; /* create pointer to array */
   printf( "     sizeof c = %c\tsizeof(char)  = %li"   
           "\n     sizeof s = %s\tsizeof(short) = %li"   
           "\n     sizeof i = %d\tsizeof(int) = %li"   
           "\n     sizeof l = %ld\tsizeof(long) = %li"   
           "\n     sizeof f = %f\tsizeof(float) = %li"   
           "\n     sizeof d = %lf\tsizeof(double) = %li"   
           "\n    sizeof ld = %ld\tsizeof(long double) = %li"   
           "\n sizeof array = %li"   
           "\n   sizeof ptr = %li\n",    
          sizeof c, sizeof( char ), sizeof s, sizeof( short ), sizeof i,
          sizeof( int ), sizeof l, sizeof( long ), sizeof f, 
          sizeof( float ), sizeof d, sizeof( double ), sizeof ld, 
          sizeof( long double ), sizeof array, sizeof ptr );  

   return 0; /* indicates successful termination */
} /* end main */
