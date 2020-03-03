/* Fig. 11.7: fig11_07.c
   Reading and printing a sequential file */
#include <stdio.h>
int main()
{  int account;     /* account number */
   char name[ 30 ]; /* account name */
   double balance;  /* account balance */
   FILE *cfPtr;     /* cfPtr = clients.dat file pointer */
   /* fopen opens file; exits program if file cannot be opened */ 
   if ( ( cfPtr = fopen( "clients.dat", "r" ) ) == NULL ) {
      printf( "File could not be opened\n" );
   } /* end if */
   else { /* read account, name and balance from file */
      printf( "%-10s%-13s%s\n", "Account", "Name", "Balance" );
      fscanf( cfPtr, "%d%s%lf", &account, name, &balance );
      /* while not end of file */
      while ( !feof( cfPtr ) ) { 
         printf( "%-10d%-13s%7.2f\n", account, name, balance );
         fscanf( cfPtr, "%d%s%lf", &account, name, &balance );
      } /* end while */
      fclose( cfPtr ); /* fclose closes the file */
   } /* end else */
   return 0; /* indicates successful termination */
} /* end main */