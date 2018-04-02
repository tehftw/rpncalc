#include "dstack.h"




struct dstack dstack_wrapArray(double *darray_zero, size_t arrlen)
{
	struct dstack newstk;
	newstk.stptr = 0;
	newstk.capacity = arrlen;
	newstk.ptr_zero = darray_zero;
	return newstk;
}
double *dstack_getTop(struct dstack* stk)
{
	return ((stk->ptr_zero)+(stk->stptr));
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
