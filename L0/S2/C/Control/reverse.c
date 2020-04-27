#include <stdio.h>

int main()
{
	int N, M=0;

	scanf("%d", &N);

	while(N!=0)
	{
		M=M*10+(N%10);
		N/=10;
	}

	printf("%d\n", M);

	return 0;
}
