#include <stdio.h>
int main()
{
int c[ 5 ] = {2, 3, 5, 4};
int i;

printf("%s%13s\n", "Element", "Value");

for(i=0;i<10;i++)
{
printf("%7d%13d\n", i, c[ i ]);
}
return 0;
}

