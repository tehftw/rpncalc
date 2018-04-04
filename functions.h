#pragma once
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
	CalcFun *func;
};

const char *KEY_ADD;
const char *KEY_MULTIPLY;
const char *KEY_INVERSE;
const char *KEY_EXP;
const char *KEY_LOGN;

void calc_applyFunction(struct dstack *, CalcFunPtr );

double calcfun_add(struct dstack *);
const CalcFunPtr calcfunptr_add;

double calcfun_multiply(struct dstack *);

struct CalcFunMap calcfunmap_initialize(CalcFunPtr, size_t);

void calc_findAndApplyFunction(struct dstack *, struct CalcFunMap, const char * );
