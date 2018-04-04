#include "functions.h"


const char *KEY_ADD = "+";
const char *KEY_MULTIPLY = "*";
const char *KEY_INVERSE = "/";
const char *KEY_EXP = "exp";
const char *KEY_LOGN = "logn";


void calc_applyFunction(struct dstack *stk, CalcFunPtr fun_ptr)
{
	double result = fun_ptr(stk);
	dstack_push(stk, result);
}

const CalcFunPtr calcfunptr_add = &calcfun_add;
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
