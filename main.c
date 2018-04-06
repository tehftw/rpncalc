/* clear && gcc -Wall -g stack.c -lm && ./a.out */

/* TODO:
 *	Multiple arguments for operators( '1 2 3 +3' -> '(+ 1 2 3)')
 *	'-x'(might not be needed due to the C function that translates numbers)
 *	improve Interactive - remember the whole history of valid input and spit it out for the user to use again if needed
 *	Refactor how functions are read: create a dictionary(key: mnemonic of , value: pointer to function), then each time it will compare function against dictionary
 *	Add checking of whether it's valid(don't allow non-numbers to be threw onto the stack, disallow invalid arguments etc.)
 *	Switch to C++ standard containers(stack, map)
 *	Add 'readme'
 *	Fix bug: when inserting whitespace, program pushes double='0' onto stack
 *	Multiple number-stacks
 *	Print a list of all available functions
 *	Multiple usage when receiving a sequence of operands. e.g. buffer="+++" causes it to do addition 3 times
 * */

/*
TODO calcfuns:
drop number from top of stack: 'd'/'del'/'drop'
change the sign of number: '-'


summate/multiplicate multiple numbers
summation and multiplication over whole stack

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


#include "dstack.h"
#include "chstack.h"
#include "functions.h"


const size_t DEFAULT_SIZE_NUMBERS_STACK = 0x20;
const size_t DEFAULT_SIZE_INPUT_STRING = 0x80;
const size_t DEFAULT_SIZE_CURRENT_WORD_STRING = 0x20;
const size_t DEFAULT_SIZE_HISTORY_STRING = 0x80;


int main(int argc, char **argv)
{
	bool verbose = false;
	if(argc > 1)
	{
		if ( strcmp(argv[1], "-v") == 0 ) {
			verbose = true; printf("\nVerbose mode on");
		} else {
			printf("\nYou can add option '-v' to show a lot of worthless stuff.");	
		}
	}

	bool is_interactive = true;


	/* */
	printf("\n\tUNFINISHED\n");
	printf("\tA short hack implementation of a stack with numbers of 'double' type.\n");
	const size_t buf_size = DEFAULT_SIZE_INPUT_STRING;
	const size_t wordbuf_size = DEFAULT_SIZE_CURRENT_WORD_STRING;
	const size_t stk_size = DEFAULT_SIZE_NUMBERS_STACK;
	printf("\nStack size = %zu[doubles]; input buffer size = %zu[characters]\n", stk_size, buf_size);

	/* Creating a dstack by wrapping an array */
	double darray[stk_size];
	struct dstack stack;
	stack.capacity= stk_size;
	stack.stptr = 0;
	stack.ptr_zero = &darray[0];

	struct dstack *stk = &stack;




	/* Some basic-ass reverse polish notation calculator */


	printf("\nInteractive mode online.\n"); /* write 'quit' or 'exit' to stop."); */

	/* main loop */
	while(is_interactive) {
		printf("\n\n");
		// Saving input
		char input_buffer[buf_size+1];
		struct chstack inbuf = chstack_wrapArray(input_buffer, sizeof(input_buffer));
		input_buffer[buf_size] = '\0'; // to ensure it's always delimited
		int input_character;
		do {
			input_character = getchar();
			chstack_push(&inbuf, input_character);
			//printf("\ninput_buffer[%zu] = %c", buf_len, input_buffer[buf_len]);
		} while(input_character != EOF  &&
				input_character != '\n' &&
				inbuf.stptr < inbuf.capacity);
		chstack_push(&inbuf, '\0');

		printf("\n Stored buffer: '%s'", input_buffer);

		/* Read through the input and do operations: */
		char wordbuf_array[wordbuf_size+1];
		struct chstack wordbuf = chstack_wrapArray( wordbuf_array, sizeof(wordbuf_array) );
		chstack_makeEmpty(&wordbuf);
		const char delimiter = ' ';
		/* Two-val */
		const char *add = "+";
		const char *multiply = "*";
		/* One-val */
		const char *str_inverse = "/";
		const char *str_exp = "exp";
		const char *str_logn = "logn";

		if( verbose )printf("\n inbuf.stptr = %zu", inbuf.stptr);
		for(size_t i = 0; i < inbuf.stptr; i++) {
			/* If char = delimiter, then stop gathering more, 
			 * operate on the current word,
			 * and clear the word_buffer */
			char in = *(inbuf.ptr_zero + i);
			if( in == ' ' || in == '\n' || '\0' ) {
				if( verbose ) printf("\n Word: '%s'", wordbuf.ptr_zero);
				chstack_push(&wordbuf, '\0');
				/* If operation, then operate on doubles from top of dstack */
				if(  strcmp(wordbuf.ptr_zero, "quit") == 0	) {
					is_interactive = false;
				} else if( strcmp(wordbuf.ptr_zero, add) == 0 ) {
					if(verbose) printf(" Adding.");
					double result = dstack_pop(stk);
					result += dstack_pop(stk);
					dstack_push(stk, result);
				} else if (strcmp(wordbuf.ptr_zero, multiply) == 0) {  
					if( verbose )printf(" Multiply.");
					double result = dstack_pop(stk);
					result *= dstack_pop(stk);
					dstack_push(stk, result);
				} else if (strcmp(wordbuf.ptr_zero, str_exp) == 0) {
					if( verbose )printf(" Exp() function.");
					double result = dstack_pop(stk);
					result = exp(result);
					dstack_push(stk, result);
				} else if(strcmp(wordbuf.ptr_zero, str_inverse) == 0) {
					if( verbose ) printf("Inverse: ");
					double result = dstack_pop(stk);
					result = 1/result;
					dstack_push(stk, result);
				} else if(strcmp(wordbuf.ptr_zero, str_logn) == 0 ) {
					if( verbose ) printf("Logn(): ");
					double result = dstack_pop(stk);
					result = log(result);
					dstack_push(stk, result);
				} else {
					if( verbose ) printf(" Pushing double onto dstack.");
					dstack_push( stk, atof(wordbuf.ptr_zero) );
				}
				chstack_makeEmpty(&wordbuf);
				
			} else {
				/* Keep building the word*/
				if( verbose )printf("\n Pushing '%c' onto wordbuf. ", in);
				chstack_push(&wordbuf, in);
				if( verbose )printf(" Word = '%s'", wordbuf.ptr_zero);
			}
		}
		

		printf("\n\n Values(from top to bottom of stack):");
		dstack_print(stk);
	}

	printf("\n\n");
	return 0;
}






