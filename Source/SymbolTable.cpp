/*
 * SymbolTable.cpp
 */
#include "SymbolTable.h"
#include "Stack.h"

//push new STL on to stack
void SymbolTable::enter_new_scope()
{
    Stack *copy = this->addressToStackTop;
    copy->push(); 
}

//pop current STL off the stack
void SymbolTable::leave_current_scope()
{
    Stack *copy = this->addressToStackTop;
    copy->pop();
}

void SymbolTable::insert(string k)
{
    Record *temp = new Record(k);
    if(symbolRecord.head == NULL){ //first insert
        symbolRecord.head = temp; //linking head
        symbolRecord.current = temp; //continuing current
    }
    else{
        symbolRecord.current->after = temp; //single linking
        symbolRecord.current = symbolRecord.current->after; //moving forward
    }
}

int SymbolTable::recordSearch(string key)
{
    Stack *stackCpy = this->addressToStackTop;
    SymbolTable *templist = stackCpy->curr;
    
    while(templist !=NULL){
        if(templist->symbolRecord.head != NULL){ //looping starting at the head
            Record *temp = templist->symbolRecord.head;
            while(temp->after != NULL){
                if(temp->key == key){
                    //cout << key << " is found in symbol table stored at " << templist << endl;
                    return 1;
                }
                temp = temp->after;
            }
            if(temp->key == key){ //this outer if prevents above loop from going too far and segfaulting
                //cout << key << " is found in symbol table stored at " << templist << endl;
                return 1;
            }
        }
        else{
            //cout<<"There are no records in current stack"<<endl;
            return 0;
        }
        if(templist->prev != NULL){ //moving to new stack
            templist = templist->prev;
        }
        else{
            return 0;
        }
    }
    return 0;
}

void SymbolTable::searchKeyExists() //Temporary function, used for testing and seeing all entries in all symbol tables
{
    Stack *stackCpy = this->addressToStackTop;
    SymbolTable *templist = stackCpy->curr;
    
    while(templist !=NULL){
        if(templist->symbolRecord.head != NULL){
            Record *temp = templist->symbolRecord.head;
            while(temp->after != NULL){
                cout<<temp->key<<endl;
                temp = temp->after;
            }
        }
        if(templist->prev != NULL){
            templist = templist->prev;
        }
    	else{
    		return;
    	}
	}
}
