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
#include <ctype.h>
#include"../../constants_macros/include/constants.h"

typedef struct SYMBOL_TABLE_T {
	char ** keys;
	void ** values;
	int no_symbols;
} symbol_table_t;

symbol_table_t * init_symbol_table(void);
void init_null_st_entry(symbol_table_t * st, char * entry);
char * deep_copy_string(char * dest, char * str);
int find_symbol(symbol_table_t * st, char * key_to_check);
symbol_table_t * add_symbol(char * key, void * value);
void free_symbol_table(symbol_table_t * st);

#endif
