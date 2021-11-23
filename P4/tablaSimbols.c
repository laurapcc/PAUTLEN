#include "tablaSimbols.h"

typedef struct _symbol {
    char *id;
    int type;
    UT_hash_handle hash_handle;
} symbol;

typedef struct _hash_table {
    symbol **global_table;
    symbol **local_table;
    int exists_local;
} hash_table;



hash_table * createTable(void) {

    hash_table * table;

    /* Allocate memory */
    table = (hash_table*)malloc(sizeof(hash_table));
    
    if (table == NULL) {
        printf("Error allocating memory.\n");
        return NULL;
    }

    /* Allocate memory for global table */
    table -> global_table = (symbol**)malloc(sizeof(symbol));

    if (table -> global_table == NULL) {
        free(table);
        print("Error allocating memory for global table.\n");
        return NULL;
    }

    /* Allocate memory for local table */
    table -> local_table = (symbol**)malloc(sizeof(symbol));

    if (table -> local_table == NULL) {
        free(table);
        free(table -> global_table);
        printf("Error allocating memory for local table.\n");
        return NULL;
    }

    /* Initialize parameters */
    *(table -> global_table) = NULL;
    *(table -> local_table) = NULL;
    table -> exists_local = 0;
    
    return table;
}



void deleteTable(hash_table* table) {

    symbol *sym, *table_sym;

    /* Delete global table */

    /* Iter through the symbols of the table and delete them */
    HASH_ITER(hh, table -> global_table, sym, table_sym) {
        HASH_DEL(table -> global_table, sym);
        free(sym -> id);
        free(sym);
    }

    /* Delete local table */
    HASH_ITER(hh, table -> local_table, sym, table_sym) {
        HASH_DEL(table -> local_table, sym);
        free(sym -> id);
        free(sym);
    }

    /* Free tables */
    free(table -> global_table);
    free(table -> local_table);
    free(table);
}

/* Auxiliary function to search for a symbol in a table.
If symbol is found, return its type. */
int search_symbol(symbol** table, char* id) { 

    symbol* sym;

    /* If the symbol of id='id' is found, it is stored in 'sym'*/
    HASH_FIND_STR(*table, id, sym);
    
    if (sym == NULL){
        /* Symbol not found */
        return -1;
    }
    return sym -> type;
}

/* Auxiliary function to insert in the table a symbol */
int insert_symbol(symbol** table, char* id, int value) {

    symbol *new_sym;

    /* If the symbol already exists in the table: error */
    if (search_symbol(table, id) != -1){
        return -1;
    }

    /* Allocate memory for the new symbol */
    new_sym = (symbol*)malloc(sizeof(symbol));
    if (new_sym == NULL) {
        printf("Error when allocating memory for new symbol %s.\n", id);
        return -1;
    }

    new_sym -> id = (char*)malloc(sizeof(char)*(strlen(id) + 1));
    if (new_sym -> id == NULL) {
        free(new_sym);
        printf("Error when allocating memory for new symbol %s.\n", id);
        return -1;
    }

    strcpy(new_sym -> id, id);;
    new_sym -> type = value;

    HASH_ADD_STR(*table, id, new_sym);

    return 0;
}


int addElement(hash_table* table, char* id, int value) {

    /* If a local table exists, we insert the element there. If not, we insert
    it in the global table */
    if (table -> exists_local) {
        return insert_symbol(table -> local_table, id, value);
    }
    else {
        return insert_symbol(table -> global_table, id, value);
    }
}

int searchElement(hash_table* table, char* id) {

    int type;

    /* If a local table exists, we search for the element there. If not, we search for
    it in the global table */
    if (table -> exists_local) {
        type = search_symbol(table -> local_table, id);

        /* If the element doesn't exist in the local table, we look for it in the global. */
        if (type == -1) {
            return search_symbol(table ->global_table, id);
        }
        else {
            return type;
        }
    }
    else {
        return search_symbol(table -> global_table, id);
    }
}

int openScope(hash_table* table, char* id, int value) {

    /* Searh for the element in the global table, if it exists, error. */
    if (search_symbol(table -> global_table, id) != -1){
        printf("Error, function %s already exists.\n", id);
        return -1;
    }

    /* Insert the element in the global table. */
    if (insert_symbol(table -> global_table, id, value) == -1) {
        printf("Error while opening scope for function %s: insertion in global table failed.\n", id);
        return -1;
    }

    /* Initialize local table. */
    if (insert_symbol(table -> local_table, id, value) == -1) {
        printf("Error while opening scope for function %s: insertion in local table failed.\n", id);
        return -1;
    }
    table -> exists_local = 1;
    return 0;
}

int closeScope(hash_table* table) {

    symbol *sym, *table_sym;
    int i = 0;

    /* If no local table exist, error. */
    if (!table -> exists_local) {
        printf("Error while closing scope, no active local tables.\n");
        return -1;
    }

    /* Iter through the elements of the table deleting them. */
    HASH_ITER(hh, table -> local_table, sym, table_sym) {
        HASH_DEL(table -> local_table, sym);
        if (i != 0) {
            free(sym -> id);
            free(sym);
        }
        else {
            i++;
        }
    }

    free(table -> local_table);
    table -> exists_local = 0;
    return 0;
}