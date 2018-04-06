#pragma once

#include <string.h>
#include <stdio.h>

#include "functions.h"

struct calcfunmapEntry {
	char *key;
	calcfunPointer funptr;
};

struct calcfunmap {
	size_t capacity;
	size_t length;
	
	struct calcfunmapEntry *entry_zero;
};


struct calcfunmap calcfunmap_initializeWrapArray (
		struct calcfunmapEntry * entry_zero, 
		size_t arrlen );
