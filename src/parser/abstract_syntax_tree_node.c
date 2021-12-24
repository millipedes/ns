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
		node->name[i] = token->id[i];
	}

	if(is_operator(token)) {
		node->is_op = 1;
	} else {
		node->is_op = 0;
	}

	if(symbol_index != -1) {
		switch(token->type) {
			case TOKEN_INITIAL:
				fprintf(stderr, "[ERROR]: TOKEN_INITIAL passed to parse tree!");
				exit(1);
			case TOKEN_INT:
				int * tmp = calloc(1, sizeof(int));
				*tmp = atoi(token->id);
				node->value = tmp;
				return node; 
			case TOKEN_WORD:
				node->value = (char *)calloc(strnlen(token->id, MAX_OPERATOR), sizeof(char));
				for(int i = 0; i < strnlen(token->id, MAX_OPERATOR); i++) {
					*((char *)node->value + i) = token->id[i];
				}
				return node; 
			case TOKEN_L_PAREN:
				node->value = init_operator("(");
				return node;
			case TOKEN_R_PAREN:
				node->value = init_operator(")");
				return node;
			case TOKEN_CARROT_POW:
				node->value = init_operator("^");
				return node;  
			case TOKEN_SPACE:
				fprintf(stderr, "[ERROR]: TOKEN_SPACE passed to parse tree!");
				exit(1);
				return node;  
			case TOKEN_PLUS:
				node->value = init_operator("+");
				return node;  
			case TOKEN_MINUS:
				node->value = init_operator("-");
				return node;  
			case TOKEN_STAR_MULT:
				node->value = init_operator("*");
				return node;  
			case TOKEN_FS_DIVIDE:
				node->value = init_operator("/");
				return node;  
			case TOKEN_LESS_THAN:
				node->value = init_operator("<");
				return node;  
			case TOKEN_GREATER_THAN:
				node->value = init_operator(">");
				return node;  
			case TOKEN_L_BRACKET:
				node->value = init_operator("[");
				return node;  
			case TOKEN_R_BRACKET:
				node->value = init_operator("]");
				return node;  
			case TOKEN_SEMICOLON:
				node->value = init_operator(";");
				return node;  
			case TOKEN_EOL:
				fprintf(stderr, "[ERROR]: TOKEN_EOL passed to parse tree!");
				exit(1);
				return node;
		}
	} else {
		printf("[ERROR]: `%s` is undefined", token->id);
	}
	return node;
}

/**
 * This function prints the name of a node and whether it is an operator
 * @param The node
 * @return N/a
 */
void print_node(ast_node_t * node) {
	printf("[NODE NAME]: %s\t[IS_OP]: %s\n", node->name, (node->is_op == 1 ? "TRUE" : "FALSE"));
}

/**
 * This function frees a node
 * @param The node
 * @return N/a
 */
void free_node(ast_node_t * node) {
	if (node->name) {
		free(node->name);
	}
	// Since all values/pointers have size 8 bytes, just cast to char *
	if((char *)node->value) {
		free((char *)node->value);
	}
	free(node);
}	

