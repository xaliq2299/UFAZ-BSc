#include <stdio.h>

double f(double);
double u(int);

int main()
{
	int n, x;
	double y;

	scanf("%d", &n);
	for(x=0;x<=n;x++)
	{		
		y=u(x);
		printf("u(%d) = %.3lf, ", x, y );
		printf("%f\n", f(y)-y );  
	}

	return 0;
}


double f(double x)
{
	float y;
	y=-x*x+x+0.5;
	return y;
}


double u(int x)
{
	if(x==0)
		return 0;
	else
		return f(u(x-1));
}
