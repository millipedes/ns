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
#include"../constants_macros/include/constants.h"

/**
 * This function initializes a node
 * @param the token from which you initalize the node
 * @return the node
 */
ast_node_t * init_node(token_T * token) {
	ast_node_t * node = calloc(1, sizeof(struct AST_NODE_T));
	node->name = calloc(strnlen(token->id, MAX_OPERATOR), sizeof(char));
	for(int i = 0; i < strnlen(token->id, MAX_OPERATOR); i++) {
		node->name[i] = token->id[i];
		if(is_operator(token)) {
			node->is_op = 1;
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

