#include <stdio.h>

int main()
{
int d[ 4 ] = {1, 2, 3, 4};
int i;

printf("%s%13s\n", "Element", "Value");

for(i=0;i<10;i++)
{
printf("%7d%13d\n", i, d[ i ]);
}
return 0;
}
