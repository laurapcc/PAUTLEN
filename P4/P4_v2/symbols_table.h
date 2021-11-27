#ifndef _SYMBOLS_TABLE_H
#define _SYMBOLS_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "hash.h"

#define NOT_FOUND -1
#define ERROR -1
#define OK 0

#define TRUE 1
#define FALSE 0

#define MAX_ID_LENGTH 128



typedef struct _symbol {
    char id[MAX_ID_LENGTH];
    int type;
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