#pragma once

#include <stdbool.h>
#include <string.h>
#include <assert.h>



#include "dstack.h"


typedef double CalcFun(struct dstack *stk); /* Request some values, then spit out the result */
typedef CalcFun (*CalcFunPtr);

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

double calcfun_add(struct dstack *);
double calcfun_multiply(struct dstack *);

double calcfun_inverse(struct dstack *);
double calcfun_exp(struct dstack *);
double calcfun_logn(struct dstack *);

