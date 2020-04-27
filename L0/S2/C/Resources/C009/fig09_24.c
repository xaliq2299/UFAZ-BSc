/* Fig 9.24: fig09_24.c */
/* Reading and discarding characters from the input stream */
#include <stdio.h>

int main()
{  int month1; /* define month1 */
   int day1;   /* define day1 */
   int year1;  /* define year1 */
   int month2; /* define month2 */
   int day2;   /* define day2 */
   int year2;  /* define year2 */
   printf( "Enter a date in the form mm-dd-yyyy: " );
   scanf( "%d%*c%d%*c%d", &month1, &day1, &year1 );
   printf( "month = %d  day = %d  year = %d\n\n", month1, day1, year1 );
   printf( "Enter a date in the form mm/dd/yyyy: " );
   scanf( "%d%*c%d%*c%d", &month2, &day2, &year2 );
   printf( "month = %d  day = %d  year = %d\n", month2, day2, year2 );
   return 0; 
}