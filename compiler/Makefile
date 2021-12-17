all: alfa

alfa:
	flex alfa.l
	bison -d alfa.y
	gcc -g -Wall alfa.c tokens.h lex.yy.c alfa.tab.c symbols_table.c generacion.c 

clean:
	rm -rf symbols_table.o lex.yy.c alfa.tab.h alfa.tab.c generacion.o 
