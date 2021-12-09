#include "symbols_table.h"
#include "hash.c"

/* SYMBOL STRUCTURE MANIPULATION FUNCTIONS */

symbol * new_symbol(char * id) {
    symbol * s = (symbol *) calloc(1, sizeof(symbol));
    if(s == NULL) {
        fprintf(stderr, "ERROR: Cannot allocate memory for new symbol with id %s", id);
        return NULL;
    }

    if(strlen(id) >= MAX_ID_LENGTH - 1) {
        fprintf(stderr, "ERROR: Symbol identifier too long: %s\n", id);
        destroy_symbol(s);
        return NULL;
    }
    strcpy(s->id, id);
    s->value = ERROR;
    s->category = ERROR;
    s->classs = ERROR;
    s->type = ERROR;
    s->size = ERROR;
    s->num_locals = ERROR;
    s->pos_local = ERROR;
    s->num_params = ERROR;
    s->pos_param = ERROR;

    return s;
}

void destroy_symbol(symbol * s) {
    if(s) free(s);
}

void print_symbol(FILE * f, symbol * s) {
    fprintf(f, "Symbol with id %s, ", s->id);
    if(s->value != ERROR) fprintf(f, "value: %d, ", s->value);
    if(s->category != ERROR) {
        if(s->category == VARIABLE) { fprintf(f, "category: VARIABLE, "); } 
        else if(s->category == PARAMETRO) { fprintf(f, "category: PARAMETRO, "); } 
        else if(s->category == FUNCION) { fprintf(f, "category: FUNCION, "); }
    }
    if(s->classs != ERROR) {
        if(s->classs == ESCALAR) { fprintf(f, "classs: ESCALAR, "); } 
        else if(s->classs == VECTOR) { fprintf(f, "classs: VECTOR, "); }
    }
    if(s->type != ERROR) {
        if(s->type == INT) { fprintf(f, "type: INT, "); } 
        else if(s->type == BOOLEAN) { fprintf(f, "type: BOOLEAN, "); }
    }
    if(s->size != ERROR) { fprintf(f, "size: %d, ", s->size); }
    if(s->num_locals != ERROR) { fprintf(f, "num_locals: %d, ", s->num_locals); }
    if(s->pos_local != ERROR) { fprintf(f, "pos_local: %d, ", s->pos_local); }
    if(s->num_params != ERROR) { fprintf(f, "num_params: %d, ", s->num_params); }
    if(s->pos_param != ERROR) { fprintf(f, "pos_param: %d, ", s->pos_param); }
    fprintf(f, "\n");
}

void symbol_set_value(symbol * s, int value) { s->value = value; }
void symbol_set_category(symbol * s, int category) { s->category = category; }
void symbol_set_classs(symbol * s, int classs) { s->classs = classs; }
void symbol_set_type(symbol * s, int type) { s->type = type; }
void symbol_set_size(symbol * s, int size) { s->size = size; }
void symbol_set_num_locals(symbol * s, int num_locals) { s->num_locals = num_locals; }
void symbol_set_pos_local(symbol * s, int pos_local) { s->pos_local = pos_local; }
void symbol_set_num_params(symbol * s, int num_params) { s->num_params = num_params; }
void symbol_set_pos_param(symbol * s, int pos_param) { s->pos_param = pos_param; }
void symbol_inc_num_locals(symbol * s) { (s->num_locals)++; }
void symbol_inc_num_params(symbol * s) { (s->num_params)++; }

int symbol_get_value(symbol * s) { return s->value; }
int symbol_get_category(symbol * s) { return s->category; }
int symbol_get_classs(symbol * s) { return s->classs; }
int symbol_get_type(symbol * s) { return s->type; }
int symbol_get_size(symbol * s) { return s->size; }
int symbol_get_num_locals(symbol * s) { return s->num_locals; }
int symbol_get_pos_local(symbol * s) { return s->pos_local; }
int symbol_get_num_params(symbol * s) { return s->num_params; }
int symbol_get_pos_param(symbol * s) { return s->pos_param; }




/* SYMBOL TABLE MANIPULATION FUNCTIONS */

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

/* Returns boolean indicating if we are using a local table */
int is_local_scope(symbols_table * table) {
    return table->exists_local;
}



/* SEARCH FUNCTIONS */

/* Searches a symbol in an specific hash table by its id. */
int search_hash_symbol(Hash_Table * table, char * id) {
    symbol * symbol = get_value_from_hstable(table, id, strlen(id));
    if(symbol == NULL) return NOT_FOUND;
    return symbol->type;
}

/* Searches a symbol in the local symbol table by its id. */
int search_local(symbols_table * table, char * id) {
    /* If a local table exists, we search the element there. */
    if(table -> exists_local) {
        return search_hash_symbol(table->local_table, id);
    }
    return NOT_FOUND;
}

/* Searches a symbol in the global symbol table by its id. */
int search_global(symbols_table * table, char* id) {
    return search_hash_symbol(table->global_table, id);
}

/* Searches a symbol in the local and if not the global symbol table by its id. */
int search_local_global(symbols_table * table, char* id) {
    /* If a local table exists, we search the element there. */
    if(table -> exists_local) {
        int value = search_hash_symbol(table->local_table, id);
        if(value != NOT_FOUND) return value;
    }
    /* If not, we search it in the global table */
    return search_hash_symbol(table -> global_table, id);
}



/* INSERTION FUNCTIONS */

/* Inserts a symbol in an specific hash table. */
int insert_hash_symbol(Hash_Table * table, symbol * s) {
    /* If the symbol already exists in the table: error */
    if (search_hash_symbol(table, s->id) != -1){ return ERROR; }

    if(add_node2HashTable(table, s->id, strlen(s->id), s) == -1)  {
        fprintf(stderr, "ERROR: Cannot insert into hashtable new symbol: ");
        print_symbol(stderr, s);
        return ERROR;
    }

    return OK;
}

/* Inserts a symbol in the local symbol table given its id and value. */
int declare_local_variable(symbols_table * table, char* id, int value, int category, int classs,
    int type, int size, int num_locals, int pos_local, int num_params, int pos_param ) {
    if(!(table -> exists_local)) { 
        fprintf(stderr, "ERROR: exists_local is False.\n");
        return ERROR; 
    }

    symbol * s = new_symbol(id);
    if(s == NULL) {
        fprintf(stderr, "ERROR: Error when initializing symbol.\n");
        return ERROR;
    }
    symbol_set_value(s, value);
    symbol_set_category(s, category);

}

/* Inserts a symbol in the global symbol table given its id and value. */
int declare_global_variable(symbols_table * table, char * id, int value) {
    return insert_hash_symbol(table->global_table, id, value);
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

