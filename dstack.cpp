#include "dstack.h"




struct dstack dstack_wrapArray(double *darray_zero, size_t arrlen)
{
	struct dstack newstk;
	newstk.stptr = 0;
	newstk.capacity = arrlen;
	newstk.ptr_zero = darray_zero;
	return newstk;
}

double dstack_pop(struct dstack* stk)
{
	if (stk->stptr > 0) stk->stptr--;
	const double popval = *((stk->ptr_zero) + (stk->stptr));
	return popval;
}
void dstack_push(struct dstack* stk, const double val)
{
	/* Something's fucked here - it puts the stptr too high by 1*/
	if(stk->stptr < stk->capacity) {
		*((stk->ptr_zero) + (stk->stptr)) = val;
		(stk->stptr) += 1;
	}
	else {
		fprintf(stderr, "\nWarning: stack %p is overflown(stptr = %zu, capacity = %zu)", stk, stk->stptr, stk->capacity);
	}
}
void dstack_print(struct dstack* stk)
{
	/* Start from the top and go downwards*/
	double *displayed_val = (stk->ptr_zero + stk->stptr - 1);
	for(size_t i = 0; i < stk->stptr; i++)
	{
		printf("\n%zu. %f", i, *displayed_val);
		displayed_val--;
	}
}
