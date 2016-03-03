#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct hash *stack = NULL; //I am using a hashTable to store the scopes
int buckets = 0; //a bucket represent a scope

int temp, scope = 0; //help for switching between scopes


struct symbol{
	int scope;
	char name[100];
	char type[20]; //dummy record
	struct symbol *next;
};

struct hash{
	struct symbol *head;
	int count;
};

struct symbol *create_symbol(int scope, char *name, char *type)
{
	struct symbol *newSymbol;
	
	newSymbol = (struct symbol *)malloc(sizeof(struct symbol));
	newSymbol->scope = scope;
	strcpy(newSymbol->name, name);
	strcpy(newSymbol->type, type);
	newSymbol->next = NULL;

    return newSymbol;
}

void Insert(char *name, char *type)
{
	int index = scope % buckets;
	struct symbol *newSymbol = create_symbol(scope, name, type);


	if (Search(name) == 1)
		return;

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

int search_scope(int scope, char *name) //Only search the current scope
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

int Search(char *name)
{
	int flag = 0;
	while(!search_scope(scope, name) && scope != 0){
		scope = scope-1;

	}

	if(search_scope(scope, name))
		flag = 1;

	scope = temp; //back to the scope on the top of the stack;
  
   return flag;
}


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
			printf("\t\t%s\n", mySymbol->type);

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

