#include <stdio.h>
#include <stdlib.h>

struct color
{
	unsigned char r, g, b;
};

struct color funct(int gray)
{
	struct color c;
	c.r = c.g = c.b = gray;

	// everything before this disappears after return
	return c;
}

struct color *functP(int gray)
{
	struct color *pc = (struct color*) malloc(sizeof(struct color));
	pc->r = pc->g = pc->b = gray;

	// everything before this disappears after return
	return pc;
}

void f(void)
{
	int f[500];
}


int main()
{
	struct color *res = functP(5);
	printf("%d %d %d\n", res->r, res->g, res->b);	
	
	f();

	printf("%d %d %d\n", res->r, res->g, res->b);
//	struct color *res = functP(5);	
//	f();

//	printf("%d %d %d\n", res->r, res->g, res->b);

	return 0;
}
