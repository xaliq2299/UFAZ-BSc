#include <stdio.h>

int main()
{
	int num, range;

	printf("Enter an integer: ");
	scanf("%d", &num);
	printf("Enter the range: ");
	scanf("%d", &range);

	for(int a=1;a<=range;a++)
	printf("%d * %d = %d\n", num, a, num*a);

	return 0;
}
