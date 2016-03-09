/*
 * main.cpp
 *
 * The driver for compiler
 */ 
#include "Stack.h"
#include <stdio.h>
 
//Globals for compiler
extern "C" int yyparse();
Stack *stackCopy;

int main()
{
        // Initialize stack of symbol tables
        Stack *stack = new Stack;
        stack->push();

        stackCopy = stack;//make copy to access in compiler

        // Initialize key function 
        int yyparse();
        
        return(yyparse());
}