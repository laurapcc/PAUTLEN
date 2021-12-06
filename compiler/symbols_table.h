#ifndef _SYMBOLS_TABLE_H
#define _SYMBOLS_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "hash.h"
#include "alfa.h"

#define NOT_FOUND -1
#define ERROR -1
#define OK 0

#define TRUE 1
#define FALSE 0

#define MAX_ID_LENGTH 100


typedef struct _symbol {
    char id[MAX_ID_LENGTH+1];
    int category; /* VARIABLE PARAMETRO or FUNCION */
    int type; /* INT or BOOLEAN */
    int size; /* number of elements in a vector */
    int num_locals; /* number of local variables */
    int pos_local; /* position of local variable */
    int num_params; /* number of parameters */
    int pos_param; /* position of parameter */
} symbol;


typedef struct _hash_table {
    Hash_Table *global_table;
    Hash_Table *local_table;
    int exists_local;
} symbols_table;


symbols_table * create_table();
void delete_table(symbols_table * table);
int search_hash_symbol(Hash_Table * table, char * id);
int insert_hash_symbol(Hash_Table * table, char* id, int value);
int insert_symbol(symbols_table * table, char * id, int value);
int search_symbol(symbols_table * table, char* id);
int open_scope(symbols_table* table, char* id, int value);
int close_scope(symbols_table * table);

int handle_in_out(FILE * fin, FILE * fout);

#endif