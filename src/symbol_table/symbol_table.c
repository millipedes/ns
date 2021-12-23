/**
 * @file symbol_table.c
 * @brief This file contains functions relating to the symbol table
 * @author Matthew C. Lindeman
 * @date 12/22/21
 * @bug None known
 * @todo Nothing atm
 */
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include"include/symbol_table.h"
#include"../constants_macros/include/constants.h"

/**
 * This function initializes the symbol_table with all of the reserved symbols
 * @param N/a
 * @return N/a
 */
symbol_table_t * init_symbol_table(void) {
	symbol_table_t * st = calloc(1, sizeof(struct SYMBOL_TABLE_T));
	st->keys = calloc(ST_PRESET_SIZE, sizeof(char *));
	st->values = calloc(ST_PRESET_SIZE, sizeof(char *));
	st->no_symbols = 0;
	init_null_st_entry(st, "+");
	init_null_st_entry(st, "-");
	init_null_st_entry(st, "/");
	init_null_st_entry(st, "(");
	init_null_st_entry(st, ")");
	return st;
}

/**
 * This function initializes an entry in the symbol table whose value is NULL
 * @param the symbol table and the entry
 * @return N/a
 */
void init_null_st_entry(symbol_table_t * st, char * entry) {
	deep_copy_string(st->keys[st->no_symbols], entry);
	st->values[st->no_symbols] = NULL;
	st->no_symbols++;
}

void deep_copy_string(char * dest, char * src) {
	dest = calloc(strnlen(src, MAX_LEN), sizeof(char));
	for(int i = 0; i < strnlen(src, MAX_LEN); i++) {
		*(dest + i) = *(src + i);
	}
}

int find_symbol(symbol_table_t * st, char * key_to_check) {
	int flag = 0;
	
	if(isdigit(*key_to_check)) {
		for(int i = 0; i < strnlen(key_to_check, MAX_LEN); i++) {
			if(!isdigit(*(key_to_check + i))) {
					flag = 1;
			}
		}
	}
	if(!flag) {
		return atoi(key_to_check);
	}

	for(int i = 0; i < st->no_symbols; i++) {
		if(!strncmp(st->keys[i], key_to_check, MAX_LEN)) {
			return i;
		}
	}
	return -1;
}

symbol_table_t * add_symbol(char * key, void * value) {
	return NULL;
}

void free_symbol_table(symbol_table_t * st) {
	for(int i = 0; i < st->no_symbols; i++) {
		free(st->keys[i]);
		free(st->values[i]);
	}
	free(st->keys);
	free(st->values);
	free(st);
}	
