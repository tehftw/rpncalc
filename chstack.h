#include <stdlib.h>
#include <stdio.h>


struct chstack {
	size_t capacity;
	size_t stptr;

	char *ptr_zero;
};

struct chstack chstack_wrapArray(char *, size_t);
void chstack_push(struct chstack *, char);
void chstack_makeEmpty(struct chstack *);
