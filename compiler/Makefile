all: alfa

alfa:
	flex alfa.l
	bison -d alfa.y
	gcc -g -Wall alfa.c hash.h lex.yy.c alfa.tab.c symbols_table.c generacion.c 
