

3/3/16------------------------------------------------------------------------------------------------ 
So far the lexor is running concurrently with the SymTable 

To run it:

	lex lexor.l (that will create the lex.yy.c file)
	cc lex.yy.c -o lexor -ll
	./lexor < (feed it any test file)

It will return a simplified version of the code and it will display the populated SymTable
--------------------------------------------------------------------------------------------------------

3/7/16-------------------------------------------------------------------------------------------------- 
I have a compiler running

To run it:
	yacc -d parse.y
	lex lexor.l (that will create the lex.yy.c file)
	cc lex.yy.c y.tab.c -o compiler -lm
	./compiler < (E.program)

I don't know how to create the output.asm 
-------------------------------------------------------------------------------------------------------

