#include <stdio.h>

int main()
{
char string1[50];
char string2[]="string literal";
int i;
printf("Enter a string:");
//scanf("%s", string1); //we will use the following type of reading string
scanf("%[^\n]s", string1);/*here using ^\n we can enter even string with
			    spaces between them, because it ends with \n*/
printf("string1 is: %s\nstring2 is: %s\n"
	"string1 with spaces between characters is:\n", string1, string2);
for(i=0;string1[i]!='\0';i++)
	printf("%c ", string1[i]);
printf("\n");
return 0;
}
