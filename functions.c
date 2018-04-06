#include "functions.h"


const char *const KEY_SUMMATION = "*";
const char *const KEY_MULTIPLICATION = "*";
const char *const KEY_INVERSE = "/";
const char *const KEY_EXP = "exp";
const char *const KEY_LOGN = "logn";



void calcfun_addition(struct dstack *stk)
{
	double result = dstack_pop(stk);
	result += dstack_pop(stk);
	dstack_push(stk, result);
}


void calcfun_multiplication(struct dstack *stk)
{
	double result = dstack_pop(stk);
	result *= dstack_pop(stk);
	dstack_push(stk, result);
}


void calcfun_inverse(struct dstack *stk)
{
	double result = dstack_pop(stk);
	result = 1/result;
	dstack_push(stk, result);
}

void calcfun_exp(struct dstack *stk)
{
	double result = dstack_pop(stk);
	result = exp(result);
	dstack_push(stk, result);
}

void calcfun_logn(struct dstack *stk)
{
	double result = dstack_pop(stk);
	result = log(result);
	dstack_push(stk, result);
}
