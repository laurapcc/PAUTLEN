#ifndef _TABLASIMBOLS_H
#define _TABLASIMBOLS_H

#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _hash_table hash_table;

hash_table * createTable(void);
void deleteTable(hash_table* table);
int addElement(hash_table* table, char* id, int value);
int searchElement(hash_table* table, char* id);
int openScope(hash_table* table, char* id, int value);
int closeScope(hash_table* table);

#endif