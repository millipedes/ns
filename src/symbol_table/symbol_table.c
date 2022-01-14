/**
 * @file symbol_table.c
 * @brief This file contains functions relating to the symbol table
 * @author Matthew C. Lindeman
 * @date 12/22/21
 * @bug None known
 * @todo Nothing atm
 */
#include"include/symbol_table.h"

/**
 * This function initializes the symbol_table with all of the reserved symbols
 * @param N/a
 * @return N/a
 */
symbol_table_t * init_symbol_table(void) {
	symbol_table_t * st = calloc(1, sizeof(struct SYMBOL_TABLE_T));
    // All pointers have same size
	st->keys = calloc(ST_PRESET_SIZE, sizeof(char *));
	st->values = calloc(ST_PRESET_SIZE, sizeof(char *));
    st->types = calloc(ST_PRESET_SIZE, sizeof(types));
	st->no_symbols = 0;
	init_null_st_entry(st, (char *)"if");
	init_null_st_entry(st, (char *)"while");
	init_null_st_entry(st, (char *)"for");
	return st;
}

/**
 * This function initializes an entry in the symbol table whose value is NULL
 * @param the symbol table and the entry
 * @return N/a
 */
void init_null_st_entry(symbol_table_t * st, char * entry) {
	st->keys[st->no_symbols] = deep_copy_string(st->keys[st->no_symbols], entry);
    st->types[st->no_symbols] = RESERVED;
	st->values[st->no_symbols] = NULL;
	st->no_symbols++;
}

char * deep_copy_string(char * dest, char * src) {
	dest = calloc(strnlen(src, MAX_LEN), sizeof(char));
	for(int i = 0; i < strnlen(src, MAX_LEN); i++) {
		*(dest + i) = *(src + i);
	}
	return dest;
}

int make_entry(symbol_table_t * st, char * name, void * value, node_type nt) {
    if(is_reserved(st, name)) {
        fprintf(stderr, "[SYMBOL TABLE] : `%s` is a reserved word!\n", name);
        return 0;
    }

    // Index will never be 0 (i.e. 0 will only be if not found), "if" is reserved
    if(!find_symbol(st, name)) {
        add_st_entry(st, name, value, node_type_to_st_type(st, name, nt));
        return 1;
    } else {
        write_st_entry(st, name, value, nt);
        return 1;
    }

}

int is_reserved(symbol_table_t * st, char * name) {
    for(int i = 0; i < st->no_symbols; i++) {
        // if it has the same name as a NULL val (i.e. reserved)
        if((!strncmp(st->keys[i], name, MAX_LINE)) && st->types[i] == RESERVED) {
            return 1;
        }
    }
    return 0;
}

int find_symbol(symbol_table_t * st, char * key_to_check) {
	for(int i = 0; i < st->no_symbols; i++) {
		if(!strncmp(st->keys[i], key_to_check, MAX_LEN)) {
			return i;
		}
	}
	return 0;
}

types node_type_to_st_type(symbol_table_t * st, char * key, node_type nt) {
    int key_index;
    switch(nt) {
        case NODE_INT:
            return INTEGER;
        case NODE_WORD:
            key_index = find_symbol(st, key);
            if(key_index) {
                return st->types[key_index];
            }
            return -1;
        default:
            fprintf(stderr, "[SYMBOL TABLE]: node_type_to_st_type error!\n"
                    "Exiting\n");
            exit(1);
    }
}

//TODO write in variable_t * as it stands there is a weird memory problem fix this and that problem is fixed too 
void write_st_entry(symbol_table_t * st, char * key, void * value, node_type nt) {
    void * tmp;
    int key_index = find_symbol(st, key);
    if(st->types[key_index] != node_type_to_st_type(st, key, nt)) {
        fprintf(stderr, "[SYMBOL TABLE]: cannot assign `%s` wrong type!\n", key);
        exit(1);
    }
    tmp = st->values[key_index];
    st->values[key_index] = init_variable(value, st->types[key_index]);
    free_variable(tmp);
}

void add_st_entry(symbol_table_t * st, char * key, void * value, types type) {
    /** 
     * The way it is setup, no_children == |keys| => realloc size will always
     * be no_children, and again all pointers same size
     */
    st->keys = realloc(st->keys, (st->no_symbols + 1) * sizeof(char *));
    st->keys[st->no_symbols] = deep_copy_string(st->keys[st->no_symbols], key);
    st->values = realloc(st->values, (st->no_symbols + 1) * sizeof(char *));
    st->values[st->no_symbols] = init_variable(value, type);
    st->types[st->no_symbols] = type;
    st->no_symbols++;
}

/**
 * This function gets the st value of a particalar index.
 * NOTE: this function returns the pointer thus its intened use it only for
 * getting values not assigning pointers (it will lead to double free/seg 
 * fault).
 * @param the symbol table and the symbol index
 * @return the address of the value of the index sym_index
 */
void * get_st_value(symbol_table_t * st, int sym_index) {
    //TODO add functions etc.
    return st->values[sym_index];
}

void free_symbol_table(symbol_table_t * st) {
	for(int i = 0; i < st->no_symbols; i++) {
		free(st->keys[i]);
        switch(st->types[i]) {
            case INTEGER:
                free_variable((variable_t *)st->values[i]);
                break;
            case RESERVED:
                break;
        }
	}
	/** All pointers have the same size of 8 bytes i.e. as long as the
	 *  value is of a type pointer
	 */
	free((char **)st->values);
    if(st->types) {
        free(st->types);
    }
	free(st->keys);
	free(st);
}	
