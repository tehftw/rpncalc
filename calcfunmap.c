#include "calcfunmap.h"

struct calcfunmap calcfunmap_initializeWrapArray (
		struct calcfunmapEntry *entry_zero, 
		size_t arrlen
) {
	struct calcfunmap new_map;
	new_map.length = 0;
	new_map.capacity = arrlen;
	new_map.entry_zero = entry_zero;

	return new_map;
}


void calcfunmap_appendCalcfun (
		struct calcfunmap *cfmap,
		char *operator_string,
		calcfunPointer funptr
) {
	if( cfmap->length >= cfmap->capacity  ) {
		fprintf(stderr, "\nError: Tried to append a function to map(@%p) that is full)", cfmap);
	} else { 
		++(cfmap->length);
	}
}
