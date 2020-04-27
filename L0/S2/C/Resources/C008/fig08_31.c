/* Fig. 8.31: fig08_31.c
   Using memcpy */
#include <stdio.h>
#include <string.h>

int main()
{  char s1[ 17 ];                   /* create char array s1 */
   char s2[]  = "Copy this string"; /* initialize char array s2 */
   memcpy( s1, s2, 17 ); 
   printf( "%s\n%s\"%s\"\n", 
           "After s2 is copied into s1 with memcpy,",
           "s1 contains ", s1 );
   return 0; /* indicates successful termination */
} /* end main */