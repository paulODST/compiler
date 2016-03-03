%{
#include <stdio.h>
#include "hash2.h"
#include<stdlib.h>
#include<string.h>

%}


%%
 scope = 0;
 buckets = 100;
 stack = (struct hash *)calloc(buckets, sizeof(struct hash));        


[0123456789]+           printf("NUMBER");

begin {		
		printf("START");
		Enter_new_scope();
}

end {
		printf("END");
		Leave_current_scope();
		display(); //just to show the SymbolTable	
}


output		        printf("PRINT");

[a-zA-Z][a-zA-Z0-9]* {
		printf("ID");
		Insert(yytext, "int");	
}	 

['*']['*']			printf("EXP");

\+			printf("ADD");
\- 			printf("SUB");
\* 			printf("MUL");
\/ 			printf("DIV");
\= 			printf("EQ");


\(			printf(" LP");
\)			printf("RP ");

\;			printf(" SCOL");


%%
