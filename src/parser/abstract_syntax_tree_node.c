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
ast_node_t * init_node(token_T ** token, symbol_table_t * st) {
	ast_node_t * node = calloc(1, sizeof(struct AST_NODE_T));
    node->name = deep_copy_string(node->name, token[0]->id);
    token_T ** sub_list = NULL;

	if(is_operator(token[0])) {
		node->is_op = 1;
	} else {
		node->is_op = 0;
	}

    switch(token[0]->type) {
        case TOKEN_INITIAL:
            fprintf(stderr, "[ERROR]: TOKEN_INITIAL passed to parse tree!");
            exit(1);
        case TOKEN_INT:
            node->value = calloc(1, sizeof(int));
            *((int *)node->value + 0) = atoi(token[0]->id);
            node->type = NODE_INT;
            return node; 
        case TOKEN_WORD:
            node->value = deep_copy_string(node->value, token[0]->id);
            node->type = NODE_WORD;
            return node; 
        case TOKEN_L_PAREN:
            node->type = NODE_L_PAREN;
            node->value = init_operator((char *)"(");
            return node;
        case TOKEN_R_PAREN:
            node->type = NODE_R_PAREN;
            node->value = init_operator((char *)")");
            return node;
        case TOKEN_CARROT_POW:
            node->type = NODE_CARROT_POW;
            node->value = init_operator((char *)"^");
            return node;  
        case TOKEN_SPACE:
            fprintf(stderr, "[ERROR]: TOKEN_SPACE passed to parse tree!");
            exit(1);
            return node;  
        case TOKEN_PLUS:
            node->type = NODE_PLUS;
            node->value = init_operator((char *)"+");
            return node;  
        case TOKEN_MINUS:
            node->type = NODE_MINUS;
            node->value = init_operator((char *)"-");
            return node;  
        case TOKEN_STAR_MULT:
            node->type = NODE_STAR_MULT;
            node->value = init_operator((char *)"*");
            return node;  
        case TOKEN_FS_DIVIDE:
            node->type = NODE_FS_DIVIDE;
            node->value = init_operator((char *)"/");
            return node;  
        case TOKEN_LESS_THAN:
            node->type = NODE_LESS_THAN;
            node->value = init_operator((char *)"<");
            return node;  
        case TOKEN_GREATER_THAN:
            node->type = NODE_GREATER_THAN;
            node->value = init_operator((char *)">");
            return node;  
        case TOKEN_L_BRACKET:
            sub_list = get_sub_list(token, 1, get_list_size(token));
            node->type = NODE_DATA_FRAME;
            node->value = init_data_frame(sub_list);
            for(int i = 0; sub_list[i]->type != TOKEN_EOL; i++) {
                free_token(sub_list[i]);
                if(sub_list[i + 1]->type == TOKEN_EOL) {
                    free_token(sub_list[i + 1]);
                    break;
                }
            }
            free(sub_list);
            return node;  
        case TOKEN_R_BRACKET:
            node->type = NODE_R_BRACKET;
            node->value = init_operator((char *)"]");
            return node;  
        case TOKEN_SEMICOLON:
            node->type = NODE_SEMICOLON;
            node->value = init_operator((char *)";");
            return node;  
        case TOKEN_EQUAL_TEST:
            node->type = NODE_EQUAL_TEST;
            node->value = init_operator((char *)"==");
            return node;
        case TOKEN_LTE:
            node->type = NODE_LTE;
            node->value = init_operator((char *)"<=");
            return node;
        case TOKEN_GTE:
            node->type = NODE_GTE;
            node->value = init_operator((char *)">=");
            return node;
        case TOKEN_NE:
            node->type = NODE_NE;
            node->value = init_operator((char *)"!=");
            return node;
        case TOKEN_ASSIGN:
            node->type = NODE_ASSIGN;
            node->value = init_operator((char *)"=");
            return node;
        case TOKEN_EOL:
            fprintf(stderr, "[ERROR]: TOKEN_EOL passed to parse tree!");
            exit(1);
            return node;
    }
	return node;
}

/**
 * This function prints the name of a node and whether it is an operator
 * @param The node
 * @return N/a
 */
void print_node(ast_node_t * node) {
	printf("[NODE NAME]: %s\t[IS_OP]: %s\n", node->name,
            (node->is_op == 1 ? "TRUE" : "FALSE"));
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
	
    // A few cases requiring unique freeing of node.  
    switch (node->type) {
        case NODE_INT:
            free((int *)node->value);
            break;
        case NODE_WORD:
            free((char *)node->value);
            break;
        case NODE_L_PAREN:
            free_operator((operator_t *)node->value);
            break;
        case NODE_R_PAREN:
            free_operator((operator_t *)node->value);
            break;
        case NODE_CARROT_POW:
            free_operator((operator_t *)node->value);
            break;
        case NODE_PLUS:
            free_operator((operator_t *)node->value);
            break;
        case NODE_MINUS:
            free_operator((operator_t *)node->value);
            break;
        case NODE_STAR_MULT:
            free_operator((operator_t *)node->value);
            break;
        case NODE_FS_DIVIDE:
            free_operator((operator_t *)node->value);
            break;
        case NODE_LESS_THAN:
            free_operator((operator_t *)node->value);
            break;
        case NODE_GREATER_THAN:
            free_operator((operator_t *)node->value);
            break;
        case NODE_DATA_FRAME:
            free_data_frame((data_frame_t *)node->value);
            break;
        case NODE_L_BRACKET:
            free_operator((operator_t *)node->value);
            break;
        case NODE_R_BRACKET:
            free_operator((operator_t *)node->value);
            break;
        case NODE_SEMICOLON:
            free_operator((operator_t *)node->value);
            break;
        case NODE_EQUAL_TEST:
            free_operator((operator_t *)node->value);
            break;
        case NODE_LTE:
            free_operator((operator_t *)node->value);
            break;
        case NODE_GTE:
            free_operator((operator_t *)node->value);
            break;
        case NODE_NE:
            free_operator((operator_t *)node->value);
            break;
        case NODE_ASSIGN:
            free_operator((operator_t *)node->value);
            break;             
    }
	free(node);
}	

