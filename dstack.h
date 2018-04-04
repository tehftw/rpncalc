/* */

#include <stdlib.h>
#include <stdio.h>

struct dstack {
	size_t capacity;
	size_t stptr;

	double *ptr_zero;
};


struct dstack dstack_wrapArray(double *, size_t);
double dstack_pop(struct dstack*);
void dstack_push(struct dstack*, double);
void dstack_print(struct dstack*);
