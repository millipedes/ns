#ifndef AST_H
#define AST_H

#include"abstract_syntax_tree_node.h"
#include"../../tokenizer/include/token_stack.h"
#include"../../symbol_table/include/symbol_table.h"

typedef struct ABSTRACT_SYNTAX_TREE {
	struct ABSTRACT_SYNTAX_TREE ** children;
	ast_node_t * node;
	int no_children;
} ast_t;

ast_t * generate_tree(token_stack_T * token_stack, symbol_table_t * symbol_table);

#endif
