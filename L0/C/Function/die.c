#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
srand (time(NULL));
for(int a=1; a<=20; a++)
{
printf ( "%d ", 1+rand()%6 );
}
printf("\n");
return 0;
}
