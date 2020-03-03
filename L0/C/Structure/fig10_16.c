/* Fig. 10.16: fig10_16.c
   Representing cards with bit fields in a struct */

#include <stdio.h>

/* bitCard structure definition with bit fields */
struct bitCard {                                  
   unsigned face : 4;  /* 4 bits; 0-15 */         
   unsigned suit : 2;  /* 2 bits; 0-3 */          
   unsigned color : 1; /* 1 bit; 0-1 */           
}; /* end struct bitCard */                       

typedef struct bitCard Card; /* new type name for struct bitCard */

void fillDeck( Card * const wDeck );   /* prototype */
void deal( const Card * const wDeck ); /* prototype */

int main()
{ 
   Card deck[ 52 ]; /* create array of Cards */

   fillDeck( deck );
   deal( deck );

   return 0; /* indicates successful termination */

} /* end main */

/* initialize Cards */
void fillDeck( Card * const wDeck )
{ 
   int i; /* counter */

   /* loop through wDeck */
   for ( i = 0; i <= 51; i++ ) { 
      wDeck[ i ].face = i % 13; 
      wDeck[ i ].suit = i / 13; 
      wDeck[ i ].color = i / 26;
   } /* end for */

} /* end function fillDeck */

/* output cards in two column format; cards 0-25 subscripted with 
   k1 (column 1); cards 26-51 subscripted k2 (column 2) */
void deal( const Card * const wDeck )
{ 
   int k1; /* subscripts 0-25 */
   int k2; /* subscripts 26-51 */

   /* loop through wDeck */
   for ( k1 = 0, k2 = k1 + 26; k1 <= 25; k1++, k2++ ) { 
      printf( "Card:%3d  Suit:%2d  Color:%2d   ",
         wDeck[ k1 ].face, wDeck[ k1 ].suit, wDeck[ k1 ].color );
      printf( "Card:%3d  Suit:%2d  Color:%2d\n",
         wDeck[ k2 ].face, wDeck[ k2 ].suit, wDeck[ k2 ].color );
   } /* end for */

} /* end function deal */
