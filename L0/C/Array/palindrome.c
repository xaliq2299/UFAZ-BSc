#include <stdio.h>

int main()
{
	char string[11];
	int check=0, flag=0, a, b;

	scanf("%s", string);

	for(a=0;string[a]!='\0';a++)
		check+=1;
	
	for(a=0, b=check-1;a<=check/2, b>check/2;a++, b--)
	{
		if(string[a]==string[b])
			flag++;		
		else
		{
			flag=0;
			break;			
		}
	}
	
	if(flag==0)
		printf("%s is not Palindrome\n", string);
	else
		printf("%s is Palindrome\n", string);
	
	return 0;
}
