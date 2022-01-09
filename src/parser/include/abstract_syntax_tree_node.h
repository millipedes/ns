/**
 * @file This file contains the function definitions of functions used for the
 * abstract syntax tree nodes
 * @brief N/a
 * @author Matthew C. Lindeman
 * @date 12/22/21
 * @bug None known
 * @todo Nothing atm
 */
#ifndef ASTN_H
#define ASNT_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"node_types.h"
#include"../../tokenizer/include/token.h"
#include"../../symbol_table/include/symbol_table.h"
#include"../../tokenizer/include/token_stack.h"
#include"../../tokenizer/include/token_types.h"
#include"../../constants_macros/include/constants.h"
#include"../../symbol_table/include/operator.h"

typedef struct AST_NODE_T {
	char * name;
    node_type type;
	void * value;
	int is_op;
} ast_node_t;

ast_node_t * init_node(token_T * token, symbol_table_t * st);
void print_node(ast_node_t * node);
void free_node(ast_node_t * node);

#endif
