#pragma once

#include <cstdbool>
#include <cstring>
#include <cassert>

#include <string>
using std::string;

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



const string KEY_ADD = "+";
const string KEY_MULTIPLY = "*";
const string KEY_INVERSE = "/";
const string KEY_EXP = "exp";
const string KEY_LOGN = "logn";

void calc_applyFunction(struct dstack *, CalcFunPtr );

double calcfun_add(struct dstack *);
const CalcFunPtr calcfunptr_add = &calcfun_add;

double calcfun_multiply(struct dstack *);

