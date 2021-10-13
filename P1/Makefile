CC=gcc
CFLAGS=-g -Wall

all: example1 example2 example3 example4 example6 example5 example7 example8 example9

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

example4.o: example4.c generacion.h generacion.c
	$(CC) $(CFLAGS) -c example4.c

example4: example4.o generacion.o
	$(CC) $(CFLAGS) -o $@  $^
	./example4 ex4.asm
	nasm -g -o ex4.o -f elf32 ex4.asm
	gcc -Wall -g -m32 -o ex4 ex4.o alfalib.o

example5.o: example5.c generacion.h generacion.c
	$(CC) $(CFLAGS) -c example5.c

example5: example5.o generacion.o
	$(CC) $(CFLAGS) -o $@  $^
	./example5 ex5.asm
	nasm -g -o ex5.o -f elf32 ex5.asm
	gcc -Wall -g -m32 -o ex5 ex5.o alfalib.o

example6.o: example6.c generacion.h generacion.c
	$(CC) $(CFLAGS) -c example6.c

example6: example6.o generacion.o
	$(CC) $(CFLAGS) -o $@  $^
	./example6 ex6.asm
	nasm -g -o ex6.o -f elf32 ex6.asm
	gcc -Wall -g -m32 -o ex6 ex6.o alfalib.o

example7.o: example7.c generacion.h generacion.c
	$(CC) $(CFLAGS) -c example7.c

example7: example7.o generacion.o
	$(CC) $(CFLAGS) -o $@  $^
	./example7 ex7.asm
	nasm -g -o ex7.o -f elf32 ex7.asm
	gcc -Wall -g -m32 -o ex7 ex7.o alfalib.o

example8.o: example8.c generacion.h generacion.c
	$(CC) $(CFLAGS) -c example8.c

example8: example8.o generacion.o
	$(CC) $(CFLAGS) -o $@  $^
	./example8 ex8.asm
	nasm -g -o ex8.o -f elf32 ex8.asm
	gcc -Wall -g -m32 -o ex8 ex8.o alfalib.o

example9.o: example9.c generacion.h generacion.c
	$(CC) $(CFLAGS) -c example9.c

example9: example9.o generacion.o
	$(CC) $(CFLAGS) -o $@  $^
	./example9 ex9.asm
	nasm -g -o ex9.o -f elf32 ex9.asm
	gcc -Wall -g -m32 -o ex9 ex9.o alfalib.o

clean:
	rm -rf *.asm generacion.o 
	rm -rf example1 ex1 example1.o ex1.o
	rm -rf example2 ex2 example2.o ex2.o
	rm -rf example3 ex3 example3.o ex3.o
	rm -rf example4 ex4 example4.o ex4.o
	rm -rf example5 ex5 example5.o ex5.o
	rm -rf example6 ex6 example6.o ex6.o
	rm -rf example7 ex7 example7.o ex7.o
	rm -rf example8 ex8 example8.o ex8.o
	rm -rf example9 ex9 example9.o ex9.o



