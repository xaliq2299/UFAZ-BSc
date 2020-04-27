#include <stdio.h>

typedef struct student{
	int size;
	}*st;

int main()
{
	st Xaliq;
		
	Xaliq->size = 170; // produces segmentation fault
	
	return 0;
}
