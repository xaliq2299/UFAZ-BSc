#include "numop.h"
#include "stack.h"



double apply_unary(uint64_t op, double a)
{
	switch(-op)
	{
		case 'r': return sqrt(a);
	}
	return 0;
}

double apply_binary(uint64_t op, double a, double b)
{
	switch(-op)
	{
		case '+': return b+a;
		case '-': return b-a;
		case '*': return b*a;
		case '/': return b/a;
	}
	return 0;
}

bool is_op(NumOp no)
{
	return isnan(no.value);
}

double front_eval_op(Stack* pol)
{
	NumOp v1 = front(pol);
	popFront(pol);
	if (is_op(v1))
		return v1.value;

	NumOp v2 = front(pol);
	popFront(pol);
	if (is_op(v2))
		return apply_unary(v2.code,v1.value);

	NumOp v3 = front(pol);
	popFront(pol);

	if (is_op(v3))
		return apply_binary(v3.code,v2.value,v1.value);

	return 0; // just for warning
}

double front_eval_expression(Stack* pol)
{
	bool cont = true;

	while(cont)
	{
		NumOp no;
		no.value = front_eval_op(pol);
		if (empty(pol))
			cont = false;
		pushFront(pol,no);
	}

	double res = front(pol).value;
	popFront(pol);
	return res;
}
