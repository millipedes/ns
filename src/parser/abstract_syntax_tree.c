/**
 * @file This file contains the functions relating to making an abstract parse
 * tree from a token stack
 * @brief The functions in this file generate an asbstract syntax tree from a
 * token stack
 * @author Matthew C. Lindeman
 * @date 12/22/21
 * @bug None known
 * @todo Nothing atm
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"include/abstract_syntax_tree.h"
#include"../tokenizer/include/token_stack.h"
#include"../symbol_table/include/symbol_table.h"

/**
 * This function generates an ast from a token stack
 * @param The token stack, and the symbol table
 * @return The ast
 */
ast_t * generate_tree(token_stack_T * token_stack, symbol_table_t * symbol_table) {
	if(token_stack->previous == NULL) {
	}
	return NULL;
}
