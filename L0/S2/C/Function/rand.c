#include <stdlib.h>
#include <stdio.h>

int main ()
{
for(int i=1;i<=10;i++)
{
        printf("%10d", 1 + ( rand() % 6 ) );

        if ( i%5 == 0 )
           printf("\n");

}
return 0;
}

