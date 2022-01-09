/**
 * @file symbol_table.h
 * @brief This file contains the function definitions relating to the
 * symbol_table.c
 * @author Matthew C. Lindeman
 * @date January 08, 2022
 * @bug None known
 * @todo Nothing atm
 */
#ifndef SYM_H
#define SYM_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"../../constants_macros/include/constants.h"
#include"../../parser/include/node_types.h"
#include"../../types/include/types.h"

/**
 * Noteworthy observation, all pointers to structs have size 8 as well as
 * the natively supported pointers in c, otherwise indexing this st would
 * be either very difficult or impossible
 */
typedef struct SYMBOL_TABLE_T {
	char ** keys;
	void ** values;
    types * types;
	int no_symbols;
} symbol_table_t;

symbol_table_t * init_symbol_table(void);
void init_null_st_entry(symbol_table_t * st, char * entry);
char * deep_copy_string(char * dest, char * str);
int make_entry(symbol_table_t * st, char * name, void * value, node_type nt);
int is_reserved(symbol_table_t * st, char * name);
int find_symbol(symbol_table_t * st, char * key_to_check);
types node_type_to_st_type(symbol_table_t * st, char * key, node_type nt);
void write_st_entry(symbol_table_t * st, char * key, void * value, node_type nt);
void add_st_entry(symbol_table_t * st, char * key, void * value, types type);
void free_symbol_table(symbol_table_t * st);

#endif
