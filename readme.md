# Calculator-program based on reverse polish notation.

## What's this?

A simple calculator working on reverse polish notation. This means that it reads the input sequentially(pushing any values onto stack), and operates by taking from the top of stack and pushing the result onto the stack. 

For example: `2 3 + 5 *`( "2 and 3 added, and that by 5 multiplied") will give you the result of operation `(2 + 3) * 5`. Note, you will also get the same result with `5 2 3 + *`. It's not as amazing as lisp-like notation of `(* (+ 2 3) 5))`, though it's easy to program a RPN calculator compared to any other I know of.

As of 2018-04-06 the program has only 5 functions(other than pushing numbers onto stack): 
    2 operands:
	"+" addition 
    "*" multiplication
	1 operand:
    "/" inverse top of stack(1/x)
    "exp" exp() function(e^x)
    "logn" natural logarithm
## How to build:

This program is built with `clang` compiler, and GNU make. Though as you might see, you can easily switch in the `makefile` to use `gcc` or any other compiler instead. 

1. clone this repository
2. `cd` to the folder with repository 
3. `make`

To run: `./rpncalc`

## Why I like it?

There isn't any problems caused by the order of operations. Everything goes sequentially, without potential for ambiguity. Thus, it's simple to translate it into a task for machine.
