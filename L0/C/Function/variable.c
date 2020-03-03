#include <stdio.h>/*program about global, local(static) variables**/

void useLocal( void );
void useStaticLocal( void );
void useGlobal( void );

int x=1;

int main( void )
{
	x=5;//local variable in main

	printf("local x in outer scope of main is %d\n", x);

	{
	   int x = 7;
	   printf("local x in inner scope of main is %d\n", x);
	}
	printf("local x in outer scope of main is %d\n", x);
	
	useLocal();
	useStaticLocal();
	useGlobal();
	useLocal();
	useStaticLocal();
	useGlobal();
	
	printf("\nlocal x in main %d\n", x);
	return 0;
}

void useLocal (void)
{
int x=25;

printf("\nlocal x in useLocal is %d after entering useLocal\n",  x);
++x;
printf("local x in useLocal is %d after incrementing\n", x);
}

void useStaticLocal(void)
{
static int x=50;

printf("\nlocal static x is %d on entering useStaticLocal\n", x);
x++;
printf("local static x is %d on exiting useStaticLocal\n", x);
}

void useGlobal(void)
{
printf("\nglobal x is %d on entering useGlobal\n", x);
x*=10;
printf("global x is %d on exiting useGlobal\n", x);
}

