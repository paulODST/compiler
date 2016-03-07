%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hash.h"

void yyerror(char *s);

%}

%union {int num; char *id;}
%start line
%token print
%token end
%token start
%token <num> number
%token <id> ID
%type <num> line exp term
%type <id> assignment

%%

line 	: assignment ';'		{;}
     	| start ';' 			{Enter_new_scope();}
	| end ';' 			{Leave_current_scope();}
	| print '(' exp ')' ';'		{printf("Printing %d\n", $3);}		
	| line assignment ';' 		{;}
	| line print '(' exp ')' ';'	{printf("Printing %d\n", $4);}
	| line ';' end ';'		{Leave_current_scope();}
/*	| start ';' line';' 		{Enter_current_scope();} */  
	;

assignment : ID '=' exp 		{ Insert($1, $3); }
       	   ;

exp	   : term			{$$ = $1;}
	   | exp '+' term 		{$$ = $1 + $3;}
	   | exp '-' term		{$$ = $1 - $3;}
	   | exp '*' term		{$$ = $1 * $3;}
	   | exp '/' term		{$$ = $1 / $3;}
	   | exp '*' '*' term		{$$ = pow($1, $4);}
	   ;		

term	   : number 			{$$ = $1;}
	   | ID				{$$ = findValue($1);}	
	   ;	

%%


int main(void){

        /* Initialize Table & define # of nuckets and scopes*/
	scope = 1;
	buckets = 100;

	stack  = (struct hash *)calloc(buckets, sizeof(struct hash));

	return yyparse();

}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);}
