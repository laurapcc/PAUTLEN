########################################################
CC=gcc
CFLAGS= -g -Wall
########################################################


all: main

main: tablaSimbols.o
	$(CC) $(CFLAGS) -o main tablaSimbols.o

tablaSimbols.o: tablaSimbols.c tablaSimbols.h
	$(CC) $(CFLAGS) -c tablaSimbols.c

clean:
	rm -rf *.o main

