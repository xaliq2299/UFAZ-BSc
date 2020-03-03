#include <stdio.h>
#include <stdlib.h> //and use atoi or atof

int main(int argc, char **argv)
{
	printf("%d\n", argc);
	int n;
	
	for(int a=0;a<argc;a++)
	{
		/*
		printf("Argument: %d : %s\n", a, argv[a] );
		int nb_read = sscanf(argv[a], "%d", &n);
	
		if(nb_read > 0)
			printf("integer: %d +1 = %d\n", n, n+1);
		else
			printf("%s : Not an integer\n", argv[a] );
		*/
		printf("Argument: %d : %s\n", a, argv[a] );
	}
	return 0;
}
