Digit		[0-9]
Letter		[a-zA-Z]
IntLit		{Digit}+


%{

#include "Source/SymbolTable.h"
#include "gram.tab.h"
#include <string>
#include <iostream>
#include "Source/List.h"
#include "Source/Stack.h"
#include "Source/Record.h"
void process_id();
using namespace std;
extern "C" int yylex();

%}

%%

[ \t\n]+							{ /* delete */		}
"output"							return(OUTPUT);
"begin"								return BEG;	
"end"								return END;

{Letter}({Letter}|{Digit}|_)*		{ 
										process_id();
					  					return (ID);		
					  				}

{IntLit}							{ 
										yylval.intstuff = atoi(yytext);
				          				return INTLITERAL;
				          			}

"("									return ('(');
")"									return (')');
";"									return (';');
"="									return ('=');
"**"								return EXPONENT;
"*"									return ('*');
"/"									return ('/');
"+"									return ('+');
"-"                                 return ('-');

%%



void process_id()
{
	List *symbolRecord = new List;

	string tempYytext(yytext);

	if(stackCopy->top->recordSearch(tempYytext) == 0) {
		stackCopy->top->insert(tempYytext);
		Record *temp = new Record(tempYytext);
		symbolRecord->current = temp;
	} else {//record in symbol table
		Record *temp = new Record(tempYytext);
		symbolRecord->current = temp;
	}
	yylval.symbolstuff = symbolRecord;
}
