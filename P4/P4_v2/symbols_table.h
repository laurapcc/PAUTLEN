#ifndef _TABLASIMBOLS_H
#define _TABLASIMBOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
//#include "hash.c"

#define NOT_FOUND -1
#define ERROR -1
#define OK 0

#define TRUE 1
#define FALSE 0

#define MAX_ID_LENGTH 128

/*
symbols_table * create_table();
void delete_table(symbols_table * table);
int search_hash_symbol(Hash_Table * table, char * id);
int insert_hash_symbol(Hash_Table * table, char* id, int value);
int insert_symbol(symbols_table * table, char * id, int value);
int search_symbol(symbols_table * table, char* id);
int open_scope(symbols_table* table, char* id, int value);
int close_scope(symbols_table * table);
*/
int handle_in_out(FILE * fin, FILE * fout);

#endif