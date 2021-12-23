/**
 * @file abstract_syntax_tree_node.c
 * @brief This file performs operations relating to ast nodes to include making
 * them
 * @author Matthew C. Lindeman
 * @date 12/18/21
 * @bug None known
 * @todo Nothing atm
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"include/abstract_syntax_tree_node.h"
#include"../tokenizer/include/token_stack.h"
#include"../tokenizer/include/token_types.h"
#include"../constants_macros/include/constants.h"
#include"../symbol_table/include/symbol_table.h"
#include"../symbol_table/include/operator.h"

/**
 * This function initializes a node
 * @param the token from which you initalize the node
 * @return the node
 */
ast_node_t * init_node(token_T * token, symbol_table_t * st) {
	int symbol_index = find_symbol(st, token->id);
	ast_node_t * node = calloc(1, sizeof(struct AST_NODE_T));
	node->name = calloc(strnlen(token->id, MAX_OPERATOR), sizeof(char));
	for(int i = 0; i < strnlen(token->id, MAX_OPERATOR); i++) {
		// Set up name/if it is an operator
		node->name[i] = token->id[i];
		if(is_operator(token)) {
			node->is_op = 1;
		} else {
			node->is_op = 0;
		}

		// Each case as to what the language recognizes
		if(token->type == TOKEN_INT) {
			int * tmp = calloc(1, sizeof(int));
			*tmp = atoi(token->id);
			node->value = tmp;
			return node;
		}

		if(symbol_index != -1) {
			if(!strncmp(node->name, "+", MAX_OPERATOR)) {
				node->value = init_operator("+");
				return node;
			}
			if(!strncmp(node->name, "-", MAX_OPERATOR)) {
				node->value = init_operator("-");
				return node;
			}  
			if(!strncmp(node->name, "*", MAX_OPERATOR)) {
				node->value = init_operator("*");
				return node;
			}  
			if(!strncmp(node->name, "/", MAX_OPERATOR)) {
				node->value = init_operator("/");
				return node;
			}
		} else {
			printf("[ERROR]: `%s` is undefined", token->id);
		}
	}
	return node;
}

void print_node(ast_node_t * node) {
	printf("[NODE NAME]: %s\t[IS_OP]: %s\n", node->name, (node->is_op == 1 ? "TRUE" : "FALSE"));
}

void free_node(ast_node_t * node) {
	if (node->name) {
		free(node->name);
	}
	free(node);
}	

