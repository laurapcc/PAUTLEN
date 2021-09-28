CC=gcc
CFLAGS=-g -Wall

all: example1

generacion.o: generacion.h generacion.c
	$(CC) $(CFLAGS) -c generacion.c

example1: example1.o generacion.o
	$(CC) $(CFLAGS) -o $@  $^

example1.o: example1.c generacion.h generacion.c
	$(CC) $(CFLAGS) -c example1.c

clean:
	rm -rf *.o 
	rm -rf example1

rm-files:
	rm -rf *.txt


