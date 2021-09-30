CC=gcc
CFLAGS=-g -Wall

all: example1

generacion.o: generacion.h generacion.c
	$(CC) $(CFLAGS) -c generacion.c

example1.o: example1.c generacion.h generacion.c
	$(CC) $(CFLAGS) -c example1.c

example1: example1.o generacion.o
	$(CC) $(CFLAGS) -o $@  $^
	./example1 ex1.asm
	nasm -g -o ex1.o -f elf32 ex1.asm
	gcc -Wall -g -m32 -o ex1 ex1.o alfalib.o

clean:
	rm -rf example1.o example1
	rm -rf ex1.o ex1 ex1.asm



