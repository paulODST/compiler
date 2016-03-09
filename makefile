compiler: gram.o lex.o
		g++ -c -g lex.c gram.c
		g++ -g gram.o lex.o Source/List.cpp Source/Record.cpp Source/Stack.cpp Source/SymbolTable.cpp Source/main.cpp -o compiler -lfl
		./compiler < testFiles/test.E

gram.o:	gram.c lex.o
		g++ -c -g lex.c gram.c

gram.c:	gram.y
		cat gram.tok gram.prod > gram.y
		bison -d gram.y
		mv gram.tab.c gram.c

gram.y:	gram.tok gram.prod
		cat gram.tok gram.prod > gram.y

lex.o:	gram.tok lex.c
		flex lex.l
		mv lex.yy.c lex.c
		g++ -c lex.c
		
clean:	
		\rm *.o compiler gram.y gram.c lex.c gram.tab.h gram.output
