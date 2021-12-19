CC=gcc
CFLAGS=-Wall
SYMBOLS_DIR=symbols_table
SYNTACTIC_DIR=syntactic
CODE_GENERATION_DIR=code_generation

all: compiler

compiler: y.tab.o lex.yy.o symbols_table.o generacion.o compiler.o
	$(CC) $(CFLAGS) $^ -o $@

compiler.o: compiler.c
	$(CC) $(CFLAGS) -c $^

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

symbols_table.o: $(SYMBOLS_DIR)/symbols_table.c
	$(CC) $(CFLAGS) -c $^

generacion.o: $(CODE_GENERATION_DIR)/generacion.c
	$(CC) $(CFLAGS) -c $^

ex1:
	./compiler $(SYNTACTIC_DIR)/ex1.c $(SYNTACTIC_DIR)/ex1.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex1.o -f elf32 $(SYNTACTIC_DIR)/ex1.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex1 $(SYNTACTIC_DIR)/ex1.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex1

ex2:
	./compiler $(SYNTACTIC_DIR)/ex2.c $(SYNTACTIC_DIR)/ex2.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex2.o -f elf32 $(SYNTACTIC_DIR)/ex2.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex2 $(SYNTACTIC_DIR)/ex2.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex2

ex3:
	./compiler $(SYNTACTIC_DIR)/ex3.c $(SYNTACTIC_DIR)/ex3.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex3.o -f elf32 $(SYNTACTIC_DIR)/ex3.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex3 $(SYNTACTIC_DIR)/ex3.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex3

ex4:
	./compiler $(SYNTACTIC_DIR)/ex4.c $(SYNTACTIC_DIR)/ex4.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex4.o -f elf32 $(SYNTACTIC_DIR)/ex4.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex4 $(SYNTACTIC_DIR)/ex4.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex4

ex5:
	./compiler $(SYNTACTIC_DIR)/ex5.c $(SYNTACTIC_DIR)/ex5.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex5.o -f elf32 $(SYNTACTIC_DIR)/ex5.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex5 $(SYNTACTIC_DIR)/ex5.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex5

ex6:
	./compiler $(SYNTACTIC_DIR)/ex6.c $(SYNTACTIC_DIR)/ex6.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex6.o -f elf32 $(SYNTACTIC_DIR)/ex6.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex6 $(SYNTACTIC_DIR)/ex6.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex6

ex7:
	./compiler $(SYNTACTIC_DIR)/ex7.c $(SYNTACTIC_DIR)/ex7.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex7.o -f elf32 $(SYNTACTIC_DIR)/ex7.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex7 $(SYNTACTIC_DIR)/ex7.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex7


clean: 
	rm -rf *.o 
	rm -rf compiler *.gch 
	rm -rf output_sin_1.txt output_sin_2.txt output_sin_3.txt output_sin_4.txt output_sin_5.txt
	rm -rf y.output y.tab.c y.tab.h lex.yy.c

clean_output: 
	rm -rf $(SYMBOLS_DIR)/mi_salida.txt $(CODE_GENERATION_DIR)/ex1.asm
	rm -rf $(SYNTACTIC_DIR)/ex1.asm $(SYNTACTIC_DIR)/ex1.asm $(SYNTACTIC_DIR)/ex1 $(SYNTACTIC_DIR)/ex1.o
	rm -rf $(SYNTACTIC_DIR)/ex2.asm $(SYNTACTIC_DIR)/ex2.asm $(SYNTACTIC_DIR)/ex2 $(SYNTACTIC_DIR)/ex2.o
	rm -rf $(SYNTACTIC_DIR)/ex3.asm $(SYNTACTIC_DIR)/ex3.asm $(SYNTACTIC_DIR)/ex3 $(SYNTACTIC_DIR)/ex3.o
	rm -rf $(SYNTACTIC_DIR)/ex4.asm $(SYNTACTIC_DIR)/ex4.asm $(SYNTACTIC_DIR)/ex4 $(SYNTACTIC_DIR)/ex4.o
	rm -rf $(SYNTACTIC_DIR)/ex5.asm $(SYNTACTIC_DIR)/ex5.asm $(SYNTACTIC_DIR)/ex5 $(SYNTACTIC_DIR)/ex5.o
	rm -rf $(SYNTACTIC_DIR)/ex6.asm $(SYNTACTIC_DIR)/ex6.asm $(SYNTACTIC_DIR)/ex6 $(SYNTACTIC_DIR)/ex6.o
	rm -rf $(SYNTACTIC_DIR)/ex7.asm $(SYNTACTIC_DIR)/ex7.asm $(SYNTACTIC_DIR)/ex7 $(SYNTACTIC_DIR)/ex7.o

clean_all: clean clean_output