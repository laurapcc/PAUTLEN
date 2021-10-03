CC=gcc
CFLAGS=-g -Wall

all: example1 example2 example3 

generacion.o: generacion.h generacion.c
	$(CC) $(CFLAGS) -c generacion.c

example1.o: example1.c generacion.h generacion.c
	$(CC) $(CFLAGS) -c example1.c

example1: example1.o generacion.o
	$(CC) $(CFLAGS) -o $@  $^
	./example1 ex1.asm
	nasm -g -o ex1.o -f elf32 ex1.asm
	gcc -Wall -g -m32 -o ex1 ex1.o alfalib.o

example2.o: example2.c generacion.h generacion.c
	$(CC) $(CFLAGS) -c example2.c

example2: example2.o generacion.o
	$(CC) $(CFLAGS) -o $@  $^
	./example2 ex2.asm
	nasm -g -o ex2.o -f elf32 ex2.asm
	gcc -Wall -g -m32 -o ex2 ex2.o alfalib.o

example3.o: example3.c generacion.h generacion.c
	$(CC) $(CFLAGS) -c example3.c

example3: example3.o generacion.o
	$(CC) $(CFLAGS) -o $@  $^
	./example3 ex3.asm
	nasm -g -o ex3.o -f elf32 ex3.asm
	gcc -Wall -g -m32 -o ex3 ex3.o alfalib.o

clean:
	rm -rf *.asm generacion.o 
	rm -rf example1 ex1 example1.o ex1.o
	rm -rf example2 ex2 example2.o ex2.o
	rm -rf example3 ex3 example3.o ex3.o



