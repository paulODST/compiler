/* This is a Symbol Table implementation using a HashTable with
   chainning linked lists.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct hash *stack = NULL; //I am using a hashTable to store the scopes
int buckets = 0; //a bucket represent a scope

int temp, scope = 0; //help for switching between scopes


//Symbol Structure
struct symbol{
	int scope;
	char name[100];
	int value; 
	struct symbol *next;
};

struct hash{
	struct symbol *head;
	int count;
};

//Create symbol node
struct symbol *create_symbol(int scope, char *name, int value)
{
	struct symbol *newSymbol;
	
	newSymbol = (struct symbol *)malloc(sizeof(struct symbol));
	newSymbol->scope = scope;
	strcpy(newSymbol->name, name);
	newSymbol->value = value;
	newSymbol->next = NULL;

    return newSymbol;
}

//Change value attribute of symbol when it's already created
void modSymbol(char *name, int value){

	int findScope;

	findScope = Search(name);

	int index = findScope % buckets;

	struct symbol *mySymbol;

	mySymbol = stack[index].head;

	while(mySymbol != NULL){
		if(strcmp(mySymbol->name, name) == 0){
			mySymbol->value = value;
			break;
		}
		mySymbol = mySymbol->next;
	}
 return;
}

//Find symbol in Table ands return its value.
int findValue(char *name){

	int findScope, index;
	int retValue = 0;

	struct symbol *mySymbol;

	findScope = Search(name);

	index = findScope % buckets;

	mySymbol = stack[index].head;

	while(mySymbol != NULL){
		if(mySymbol->scope = findScope && strcmp(mySymbol->name, name) == 0){
			retValue = mySymbol->value;
			break;
		}
		mySymbol = mySymbol->next;
	}
 return retValue;
}

//Insert new symbol in SymbTable
void Insert(char *name, int value)
{
	int index = scope % buckets;
	struct symbol *newSymbol = create_symbol(scope, name, value);


	if (Search(name)){ //In case the symbol was already declared
		modSymbol(name, value);
	 	return;
        }

	if(!stack[index].head){
		stack[index].head = newSymbol;
		stack[index].count = 1;
	
	    return;
	}

	newSymbol->next = (stack[index].head);
	
	stack[index].head = newSymbol;
	stack[index].count++;

    return;
} 


int search_scope(int scope, char *name) //Only search the current scope to find symbol
{
	int index = scope % buckets, flag = 0;
	struct symbol *mySymbol;

	mySymbol = stack[index].head;
	if(!mySymbol){
	  //printf("\nERROR: variable '%s' was not declared\n\n", name);

	  return;	
	}

	while(mySymbol != NULL){
		if(mySymbol->scope == scope && strcmp(mySymbol->name, name)==0){
			//printf("\nVariable '%s' was found in scope '%d'\n\n", mySymbol->name, mySymbol->scope);
			flag = 1;
			break;
		}
		mySymbol = mySymbol->next;
	}
//        if(!flag)
//	     printf("variable is unavailable in scope");

	return flag;
}

//Search the whole SymbTable to find matching symbol.
int Search(char *name)
{
	int flag = 0;
	while(!search_scope(scope, name) && scope != 0){
		scope = scope-1;

	}

	if(search_scope(scope, name))
		flag = scope;

	scope = temp; //back to the scope on the top of the stack;
  
   return flag;
}

//Display SymbTable
void display(){
	
	struct symbol *mySymbol;
	int i;

        printf("\nscope		Name		Type\n");
	printf("-----------------------------------------------\n");

	for(i=0; i<buckets; i++){
	
		if(stack[i].count==0)
                   continue;

		mySymbol = stack[i].head;

		if(!mySymbol)
		   continue;


		while(mySymbol != NULL){
			printf("%d", mySymbol->scope);
			printf("\t\t%s", mySymbol->name);
			printf("\t\t%d\n", mySymbol->value);

			mySymbol = mySymbol->next;
		}
	
	}
	return;
}

void Leave_current_scope()
{
	temp = scope; //save the position of the last scope created

 	return;
}

void Enter_new_scope()
{
	scope++;//create a new scope by incrementing the index
  
        temp = scope;//In case search() is done within a scope
	return;
}

