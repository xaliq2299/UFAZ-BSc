#ifndef __POLISH__
#define __POLISH__
#include "numop.h"
#include "stack.h"


double apply_unary(uint64_t op, double a);

double apply_binary(uint64_t op, double a, double b);

bool is_op(NumOp no);

double front_eval_op(Stack* pol);

double front_eval_expression(Stack* pol);

#endif //__POLISH__
