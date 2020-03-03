#include <locale.h>
#include <stdio.h>
#include <time.h>

int main () {
   time_t currtime;
   struct tm *timer;
   char buffer[80];
   struct lconv *lc;
   
   time( &currtime );
   timer = localtime( &currtime );

   printf("Locale is: %s\n", setlocale(LC_ALL, "en_US.UTF-8"));
   strftime(buffer,80,"%c", timer );
   printf("Date is: %s\n", buffer);
lc=localeconv();
   printf ("Currency symbol is: %s\n-\n",lc->currency_symbol);
  
   printf("Locale is: %s\n", setlocale(LC_ALL, "en_GB.UTF-8"));
   strftime(buffer,80,"%c", timer );
   printf("Date is: %s\n", buffer);
   
   lc=localeconv();
   printf ("Currency symbol is: %s\n-\n",lc->currency_symbol);

   return(0);
}
