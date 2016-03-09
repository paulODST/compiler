#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <set>
#include <string>
#include <iostream>
#include "List.h"

using namespace std;

class Stack;

class SymbolTable {
    //friend class Stack;
    public:
        void enter_new_scope();
        void leave_current_scope();
        void insert(string);
        int recordSearch(string);
        void searchKeyExists();
        List symbolRecord;
        SymbolTable *prev;
        Stack *addressToStackTop;
};
#endif