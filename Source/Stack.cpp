#include "Stack.h"
#include "SymbolTable.h"
using namespace std;

void Stack::push()
{
    if(top == NULL) {
        SymbolTable *s = new SymbolTable();
        s->prev = NULL;
        s->addressToStackTop = this;
        top = s;
        curr = s;
        Stack *stackCopy = this;
    } else {
        SymbolTable *s = new SymbolTable();
        s->prev = top;
        s->addressToStackTop = this;
        top = s;
        curr = s;
        Stack *stackCopy = this;
    }
}

void Stack::pop()
{
    if(top == NULL) {
        return;
    } else if(top->prev == NULL) {
        top = NULL;
        curr = NULL;
    } else {
        top = top->prev;
        curr = top;
    }
}