#ifndef STACK_H
#define STACK_H

#include "SymbolTable.h"

extern Stack *stackCopy;

class Stack {
    public:
        void push();
        void pop();
        SymbolTable *top;
        SymbolTable *curr;
};
#endif