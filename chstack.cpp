#include "chstack.h"

struct chstack chstack_wrapArray(char *charray_zero, size_t arrlen)
{
	struct chstack newstk;
	newstk.stptr = 0;
	newstk.capacity = arrlen;
	newstk.ptr_zero = charray_zero;
	*(charray_zero) = '\0';
	return newstk;
}
void chstack_push(struct chstack* stk, const char ch)
{
	if(stk->stptr < stk->capacity) {
		*( (stk->ptr_zero) + (stk->stptr) ) = ch;
		(stk->stptr) += 1;
	} else {
		fprintf(stderr, "\nWarning: stack %p is overflown(stptr = %zu, capacity = %zu)", stk, stk->stptr, stk->capacity);
	}
}
void chstack_makeEmpty(struct chstack* stk)
{
	for(size_t i = 0; i < stk->capacity; i++) { *(stk->ptr_zero + i) = '\0'; }
	stk->stptr = 0;
}





