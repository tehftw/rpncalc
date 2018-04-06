#pragma once

#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <math.h>


#include "dstack.h"


typedef double CalcFun(struct dstack *stk); /* Request some values, then spit out the result */
typedef CalcFun (*CalcFunPtr);

typedef double (*calcfunPointer)(struct dstack *stk);

struct CalcFunction {
	char *key;
	CalcFunPtr func_ptr;
};

struct CalcFunMap {
	size_t capacity;
	size_t num_entries;
	struct CalcFunction *func;
};
void calcfunmap_addCalcFunction(struct CalcFunMap *, char *, CalcFunPtr);
struct CalcFunMap calcfunmap_initialize(CalcFunPtr, size_t);
CalcFunPtr calcfunmap_findCalcFun(const struct CalcFunMap, const char *);
void calc_findAndApplyFunction(struct dstack *, struct CalcFunMap, const char * );




void calc_applyFunction(struct dstack *, CalcFunPtr );

void calcfun_add(struct dstack *);
void calcfun_multiply(struct dstack *);

void calcfun_inverse(struct dstack *);
void calcfun_exp(struct dstack *);
void calcfun_logn(struct dstack *);

