/*this program prints ASCII codes of all characters*/
#include <stdio.h>

void main()
{
	char c;	//variabe c will be automatically initialized to 0 (I mean the character whose ASCII code is 0)
	        //for extra information: ASCII codes are in the interval [0;122]
	while(c<='z')
	{
		printf("%c = %d\n", c, c);
		c++;	
	}
}
