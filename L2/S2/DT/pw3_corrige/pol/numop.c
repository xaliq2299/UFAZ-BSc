#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef union 
{
 double value;
 uint64_t code;
} NumOp;

NumOp String2NumOp(char* str)
{
	NumOp no;
	char* res;
	double d = strtod(str,&res);
	if (res == str)
		no.code = -str[0];
	else
		no.value = d;
	return no;
}
