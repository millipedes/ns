#ifndef ASTN_H
#define ASNT_H

#include"../../tokenizer/include/token.h"
#include"../../symbol_table/include/symbol_table.h"

typedef struct AST_NODE_T {
	char * name;
	void * value;
	int is_op;
} ast_node_t;

ast_node_t * init_node(token_T * token, symbol_table_t * st);
void print_node(ast_node_t * node);
void free_node(ast_node_t * node);

#endif
