%{
#include "y.tab.h"
%}


%%


[0-9]+          	{yylval.num = atoi(yytext); return number;}

begin    		{return start;}

end 			{return end;}

output			{return print;}

[a-zA-Z][a-zA-Z0-9]* 	{yylval.id = strdup(yytext); return ID;}	 

[-+=*;(/)]		{return yytext[0];}

[ \t\n]			; //do nothing 

. 			{ECHO; yyerror ("unexpected char");}

%%
int yywrap (void) {return 1;}
