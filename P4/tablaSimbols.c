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

/* Auxiliary function to search for a symbol in a table */
int search_symbol(symbol** table, char* id) { 

    symbol* sym;

    /* If the symbol of id='id' is found, it is stored in 'sym'*/
    HASH_FIND_STR(*table, id, sym);
    
    if (sym == NULL){
        /* Symbol not found */
        return -1;
    }
    return 0;
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
    else{
        return insert_symbol(table -> global_table, id, value);
    }
}