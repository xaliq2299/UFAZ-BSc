//a program to assign numbers to a string using 'sprintf'
#include <stdio.h>

int main()
{
	int numb=523, num=626;
	char string[10];

	sprintf(string, "%d-%d", numb, num);

	printf("%s\n", string);

	return 0;
}
