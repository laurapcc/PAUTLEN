CC=gcc
CFLAGS=-Wall

all: pruebaSintactico

pruebaSintactico: pruebaSintactico.c lex.yy.o y.tab.o generacion.o tablaSimbols.o
	$(CC) $(CFLAGS) $^ -o $@

generacion.o: generacion.h generacion.c
	$(CC) $(CFLAGS) -c generacion.c

tablaSimbols.o: 
	gcc -c symbols_table.c

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c $^

y.tab.o: y.tab.c
	$(CC) $(CFLAGS) -c $<

lex.yy.c: alfa.l y.tab.h
	flex $<

y.tab.c: alfa.y
	bison -d -y $^

y.tab.h: alfa.y
	bison -d -y -v $^

test1:
	./pruebaSintactico entrada_sin_1.txt output_sin_1.txt

test2:
	./pruebaSintactico entrada_sin_2.txt output_sin_2.txt

test3:
	./pruebaSintactico entrada_sin_3.txt output_sin_3.txt

test4:
	./pruebaSintactico entrada_sin_4.txt output_sin_4.txt

test5:
	./pruebaSintactico entrada_sin_5.txt output_sin_5.txt

compare1:
	diff -b output_sin_1.txt salida_sin_1.txt

compare2:
	diff -b output_sin_2.txt salida_sin_2.txt

compare3:
	diff -b output_sin_3.txt salida_sin_3.txt

clean: 
	rm -rf *.o pruebaSintactico
	rm -rf output_sin_1.txt output_sin_2.txt output_sin_3.txt output_sin_4.txt output_sin_5.txt
	rm -rf y.output y.tab.c y.tab.h lex.yy.c