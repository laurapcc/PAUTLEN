CC=gcc
CFLAGS=-Wall
SYMBOLS_DIR=symbols_table
SYNTACTIC_DIR=syntactic
CODE_GENERATION_DIR=code_generation

all: compiler test1

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

test1:
	./compiler $(SYNTACTIC_DIR)/entrada_sin_1.txt $(SYNTACTIC_DIR)/output_sin_1.asm

test_basico:
	./compiler $(SYNTACTIC_DIR)/entrada_basica.txt $(SYNTACTIC_DIR)/output_basico.asm

test_basico_nasm:
	nasm -g -o $(SYNTACTIC_DIR)/output_basico.o -f elf32 $(SYNTACTIC_DIR)/output_basico.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/basico $(SYNTACTIC_DIR)/output_basico.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/basico

clean: 
	rm -rf *.o 
	rm -rf compiler *.gch 
	rm -rf output_sin_1.txt output_sin_2.txt output_sin_3.txt output_sin_4.txt output_sin_5.txt
	rm -rf y.output y.tab.c y.tab.h lex.yy.c

clean_output: 
	rm -rf $(SYMBOLS_DIR)/mi_salida.txt $(CODE_GENERATION_DIR)/ex1.asm
	rm -rf $(SYNTACTIC_DIR)/output_sin_1.asm $(SYNTACTIC_DIR)/output_basico.asm $(SYNTACTIC_DIR)/basico $(SYNTACTIC_DIR)/output_basico.o

clean_all: clean clean_output