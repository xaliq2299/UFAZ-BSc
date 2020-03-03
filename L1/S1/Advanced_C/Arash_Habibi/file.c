#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("bar.txt", "r");
	int n;
	char word[30];
	
	if(f == NULL)
	{
		printf("Cannot open the file\n");
		exit(0);
	}
	
	else
	{
		fscanf(f, "%s", word);
		fscanf(f, "%d", &n);
		printf("word: %s\n" 
		"n=%d\n",word,  n);
		fclose(f);
	}
	 
	return 0;
}
