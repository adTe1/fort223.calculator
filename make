all: compiler

syntax.tab.c syntax.tab.h: syntax.y tr.h
	bison -v -d syntax.y

lex.yy.c: lex.l syntax.tab.h
	flex lex.l

compiler: lex.yy.c syntax.tab.c tr.c tr.h
	gcc -o compiler  lex.yy.c syntax.tab.c tr.c

tr.o: tr.c tr.h
	gcc tr.o -c tr.c

clean:
	rm -f compiler lex.yy.c syntax.tab.c syntax.tab.h 
	
