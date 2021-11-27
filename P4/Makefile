########################################################
CC=gcc
CFLAGS= -g -Wall
########################################################


all: main

main: tablaSimbols.o
	$(CC) $(CFLAGS) -o main tablaSimbols.o main.c

tablaSimbols.o: tablaSimbols.c tablaSimbols.h
	$(CC) $(CFLAGS) -c -o tablaSimbols.o tablaSimbols.c

test:
	./main entrada.txt output.txt

compare: 
	diff -b output.txt expected_output.txt

clean:
	rm -rf *.o main output.txt

