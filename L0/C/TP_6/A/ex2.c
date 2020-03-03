#include <stdio.h>

int main()
{
int first, second;
int swap();
printf("Two numbers:\n");
scanf("%d%d", &first, &second);

swap(&first, &second);

printf("After swapping %d %d\n", first, second );
return 0;
}

int swap(int *aPtr, int *bPtr)
{
int hold;

hold=*aPtr;
*aPtr=*bPtr;
*bPtr=hold;

return 0;
}
