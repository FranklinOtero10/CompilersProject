comp: y.tab.c lex.yy.c
	gcc y.tab.c lex.yy.c -o comp -Wl,--allow-multiple-definition
	
y.tab.c: jparser.y
	bison -d jparser.y -o y.tab.c
	
lex.yy.c: jlexer.l
	lex jlexer.l
	
clean:
	rm comp
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h