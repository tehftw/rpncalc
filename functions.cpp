#include "functions.h"








void calc_applyFunction(struct dstack *stk, CalcFunPtr fun_ptr)
{
	double result = fun_ptr(stk);
	dstack_push(stk, result);
}


double calcfun_add(struct dstack *stk)
{
	double result = dstack_pop(stk);
	result += dstack_pop(stk);
	return result;
}


double calcfun_multiply(struct dstack *stk)
{
	double result = dstack_pop(stk);
	result *= dstack_pop(stk);
	return result;
}
