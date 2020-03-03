#include <stdio.h>
#define SIZE 6

int main()
{
char string1[SIZE]={'f', 'i','r','s','t','\0'};
for(int i=0;i<SIZE;i++)
printf("%c", string1[i]);
printf("\n");
return 0;
}
