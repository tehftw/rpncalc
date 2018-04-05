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
char *KEY_ADD;
const CalcFunPtr calcfunptr_add;

double calcfun_multiply(struct dstack *);
char *KEY_MULTIPLY;

char *KEY_INVERSE;
char *KEY_EXP;
char *KEY_LOGN;
