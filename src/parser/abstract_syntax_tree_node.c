/**
 * @file abstract_syntax_tree_node.c
 * @brief This file performs operations relating to ast nodes to include making
 * them
 * @author Matthew C. Lindeman
 * @date 12/18/21
 * @bug None known
 * @todo Nothing atm
 */
#include"include/abstract_syntax_tree_node.h"

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
				node->value = calloc(1, sizeof(int));
				*((int *)node->value + 0) = atoi(token->id);
                node->type = deep_copy_string(node->type, (char *)"integer");
				return node; 
			case TOKEN_WORD:
                // TODO ADD THE TYPE!!
				node->value = (char *)calloc(strnlen(token->id, MAX_OPERATOR), sizeof(char));
                node->type = deep_copy_string(node->type, (char *)"integer");
				for(int i = 0; i < strnlen(token->id, MAX_OPERATOR); i++) {
					*((char *)node->value + i) = token->id[i];
				}
				return node; 
			case TOKEN_L_PAREN:
                node->type = deep_copy_string(node->type, "operator");
				node->value = init_operator((char *)"(");
				return node;
			case TOKEN_R_PAREN:
                node->type = deep_copy_string(node->type, "operator");
				node->value = init_operator((char *)")");
				return node;
			case TOKEN_CARROT_POW:
                node->type = deep_copy_string(node->type, "operator");
				node->value = init_operator((char *)"^");
				return node;  
			case TOKEN_SPACE:
				fprintf(stderr, "[ERROR]: TOKEN_SPACE passed to parse tree!");
				exit(1);
				return node;  
			case TOKEN_PLUS:
                node->type = deep_copy_string(node->type, "operator");
				node->value = init_operator((char *)"+");
				return node;  
			case TOKEN_MINUS:
                node->type = deep_copy_string(node->type, "operator");
				node->value = init_operator((char *)"-");
				return node;  
			case TOKEN_STAR_MULT:
                node->type = deep_copy_string(node->type, "operator");
				node->value = init_operator((char *)"*");
				return node;  
			case TOKEN_FS_DIVIDE:
                node->type = deep_copy_string(node->type, "operator");
				node->value = init_operator((char *)"/");
				return node;  
			case TOKEN_LESS_THAN:
                node->type = deep_copy_string(node->type, "operator");
				node->value = init_operator((char *)"<");
				return node;  
			case TOKEN_GREATER_THAN:
                node->type = deep_copy_string(node->type, "operator");
				node->value = init_operator((char *)">");
				return node;  
			case TOKEN_L_BRACKET:
                node->type = deep_copy_string(node->type, "operator");
				node->value = init_operator((char *)"[");
				return node;  
			case TOKEN_R_BRACKET:
                node->type = deep_copy_string(node->type, "operator");
				node->value = init_operator((char *)"]");
				return node;  
			case TOKEN_SEMICOLON:
				node->value = init_operator((char *)";");
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
	/**
     * A few cases requiring unique freeing of node.  See constants.h for
     * a complete definition of typename().
     *
     * Note that if it is a standard pointer (i.e. not pointer to a struct)
     * we can cast to any pointer, thus I have chosen char * psuedorandomly
     */
	if(!strncmp("integer", node->type, MAX_LINE)) {
		free((char *)node->value);
	}

    if (!strncmp("operator", node->type, MAX_LINE)) {
        free_operator((operator_t *)node->value);
    }

    if(node->type) {
        free(node->type);
    }
	free(node);
}	

