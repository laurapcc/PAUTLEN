#include "symbols_table.h"
#include "hash.c"

typedef struct _symbol {
    char id[MAX_ID_LENGTH];
    int type;
} symbol;

typedef struct _hash_table {
    Hash_Table *global_table;
    Hash_Table *local_table;
    int exists_local;
} symbols_table;



/* Deletes a symbols table. */
void delete_table(symbols_table * table) {
    if(table) {
        if(table->local_table) {
            hash_table_delete(table->local_table);
        }
        if(table->global_table) {
            hash_table_delete(table->global_table);
        }
        free(table);
    }
}

/* Creates an the symbols table structure only initializing the global table. */
symbols_table * create_table() {
    symbols_table * table = NULL;

    table = (symbols_table *) calloc(1, sizeof(symbols_table));
    if (table == NULL) {
        fprintf(stderr, "ERROR: Error allocating memory.\n");
        return NULL;
    }

    table->global_table = creat_hash_table();
    if(table->global_table == NULL) {
        delete_table(table);
        fprintf(stderr, "ERROR: Error when creating global hash table.\n");
        return NULL;
    }
    table->local_table = NULL;
    table->exists_local = FALSE;

    return table;
}


/* Searches a symbol in an specific hash table by its id. */
int search_hash_symbol(Hash_Table * table, char * id) {
    symbol * symbol = get_value_from_hstable(table, id, strlen(id));
    if(symbol == NULL) return NOT_FOUND;
    return symbol->type;
}

/* Inserts a symbol in an specific hash table given its id and value. */
int insert_hash_symbol(Hash_Table * table, char* id, int value) {
    /* If the symbol already exists in the table: error */
    if (search_hash_symbol(table, id) != -1){
        return ERROR;
    }
    
    symbol * s = (symbol *) calloc(1, sizeof(symbol));
    if(s == NULL) {
        fprintf(stderr, "ERROR: Cannot allocate memory for new symbol with id %s", id);
        return ERROR;
    }

    if(strlen(id) < MAX_ID_LENGTH - 1) {
        strcpy(s->id, id);
    } else {
        fprintf(stderr, "ERROR: Symbol identifier too long: %s\n", id);
        return ERROR;
    }
    s->type = value;

    if(add_node2HashTable(table, id, strlen(id), s) == -1)  {
        fprintf(stderr, "ERROR: Cannot insert into hashtable new symbol with id %s", id);
        return ERROR;
    }

    return OK;
}

/* Inserts a symbol in the symbol table given its id and value. */
int insert_symbol(symbols_table * table, char * id, int value) {
    /* If a local table exists, we insert the element there. */
    if (table -> exists_local) {
        return insert_hash_symbol(table->local_table, id, value);
    }
    /* If not, we insert it in the global table */
    return insert_hash_symbol(table->global_table, id, value);
}

/* Searches a symbol in the symbol table by its id. */
int search_symbol(symbols_table * table, char* id) {
    /* If a local table exists, we search the element there. */
    if(table -> exists_local) {
        int value = search_hash_symbol(table->local_table, id);
        if(value != NOT_FOUND) return value;
    }
    /* If not, we search it in the global table */
    return search_hash_symbol(table -> global_table, id);
}


/* Deletes the local hash table of the given symbol table. */
int close_scope(symbols_table * table) {
    if(table->exists_local == FALSE || table->local_table == NULL) {
        return ERROR;
    } else {
        hash_table_delete(table->local_table);
    }
    table->exists_local = FALSE;
    table->local_table = NULL;
    return OK;
}

/* Creates a new local table, possibly eliminating the previous and inserting the new element. */
int open_scope(symbols_table* table, char* id, int value) {

    /* Searh for the element in the global table, if it exists, error. */
    if (search_hash_symbol(table -> global_table, id) != NOT_FOUND){
        fprintf(stderr, "ERROR: function %s already exists.\n", id);
        return ERROR;
    }

    /* Insert the element in the global table. */
    if (insert_hash_symbol(table -> global_table, id, value) == ERROR) {
        fprintf(stderr, "ERROR: error while opening scope for function %s: insertion in global table failed.\n", id);
        return ERROR;
    }

    /* Initialize local table. */
    close_scope(table);
    table->local_table = creat_hash_table();
    if(table->local_table == NULL) {
        delete_table(table);
        fprintf(stderr, "ERROR: Error while opening scope for function %s: Error when creating local hash table.\n", id);
        return ERROR;
    }
    table->exists_local = TRUE;
    if (insert_hash_symbol(table -> local_table, id, value) == ERROR) {
        printf("ERROR: Error while opening scope for function %s: insertion in local table failed.\n", id);
        return ERROR;
    }

    return OK;
}


/* Auxiliary function for handle_in_out. */
void insert_print_file(symbols_table * table, FILE * fout, char * id, int type){
    if (type == -999) {
        if (close_scope(table) == ERROR) {
            fprintf(fout, "-1\t%s\n", id);
        }
        else {
            fprintf(fout, "%s\n", id);
        }
    }
    else if (type < -1) {
        if (open_scope(table, id, type) == ERROR) {
            fprintf(fout, "-1\t%s\n", id);
        }
        else {
            fprintf(fout, "%s\n", id);
        }
    }
    else {
        if (insert_symbol(table, id, type) == ERROR) {
            fprintf(fout, "-1\t%s\n", id);
        }
        else {
            fprintf(fout, "%s\n", id);
        }
    }
}

/* Auxiliary function for handle_in_out. */
void search_print_file(symbols_table * table, FILE * fout, char * id){
    int symbol = search_symbol(table, id);
    fprintf(fout, "%s\t%d\n", id, symbol);
}

/* Given two oppened files, reads the input inserting and searching in a new symbols 
table while writing in the output file the information of each operation. */
int handle_in_out(FILE * fin, FILE * fout){
    if(fin == NULL || fout == NULL) return ERROR;

    symbols_table *table = create_table();
    if (table == NULL) {
        fprintf(stderr, "ERRROR: Error when creating the table.\n");
        return ERROR;
    }

    char* line = NULL, *token1 = NULL, *token2 = NULL;
    size_t len = 0;
    size_t read;
    int type; 

    /* walk through all tokens */
    while ((read = getline(&line, &len, fin)) != -1) {
        token1 = strtok(line, " ");
        token1[strcspn(token1, "\n")] = 0;
        token2 = strtok(NULL, " ");
        if (token2) {
            type = atoi(token2);
            insert_print_file(table, fout, token1, type);
        } else {
            search_print_file(table, fout, token1);
        }
    }

    delete_table(table);

    return OK;
}