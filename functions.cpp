#include "functions.h"


char *KEY_ADD = "+";
char *KEY_MULTIPLY = "*";
char *KEY_INVERSE = "/";
char *KEY_EXP = "exp";
char *KEY_LOGN = "logn";


struct CalcFunMap calcfunmap_initialize(CalcFunPtr cfparr, size_t cfparrlen)
{
	if(cfparrlen < 5 ) {
		fprintf(stderr, "\n Error: not enough capacity for calcfunmap");
	}
	else {
		
	}
}


CalcFunPtr calcfunmap_findCalcFun(const struct CalcFunMap cfmap, const char *key)
{
	for(size_t i = 0; i < cfmap.num_entries; i++) {
		struct CalcFunction curfun = *(cfmap.func + i);
		if( strcmp(curfun.key, key) == 0 ) {
			
		}
	}
	return 0;
}


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
