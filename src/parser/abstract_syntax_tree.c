/**
 * @file abstract_syntax_tree.c
 * @brief This file contains the functions relating to making an abstract parse 
 * tree from a token stack
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
#include"../tokenizer/include/token_types.h"

/**
 * This function generates an ast from a token stack
 * @param The token stack, and the symbol table
 * @return The ast
 */
ast_t * generate_tree(token_stack_T * token_stack, symbol_table_t * st) {
	ast_t * ast = calloc(1, sizeof(struct ABSTRACT_SYNTAX_TREE));

	if(token_stack->current->type == TOKEN_EOL) {
		token_stack = pop_token(token_stack);
	}

	if(token_stack->previous == NULL) {
		ast->node = init_node(token_stack->current, st);
		ast->no_children = 0;
		ast->children = NULL;
		return ast;
	} else {

	}
	return ast;
}

void print_tree(ast_t * ast) {
	if(ast->children == NULL) {
		printf("%s\n", ast->node->name);
	} else if(ast->children != NULL) {
		printf("%s\n", ast->node->name);
		for(int i = 0; i < ast->no_children; i++) {
			print_tree(ast->children[i]);
		}
	}
}
