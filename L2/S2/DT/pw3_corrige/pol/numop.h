#ifndef __NUMOP__
#define __NUMOP__

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

NumOp String2NumOp(char* str);

#endif // __NUMOP__
