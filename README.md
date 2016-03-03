# compiler
compiler cse4650

3/3/16------------------------------------------------------------------------------------------------
so far the lexor is running concurrently with the SymTable
to run it:
  1. lex lexor.l (that will create the lex.yy.c file)
  2. cc lex.yy.c -o lexor -ll
  3. ./lexor < (feed it any test file)
  4. It will will return the simplified version of the code, and it will display the SymTable.
-----------------------------------------------------------------------------------------------------
