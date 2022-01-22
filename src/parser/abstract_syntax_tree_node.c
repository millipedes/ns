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
    //int st_index = 0;

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
            // seg faults on just variable w/o access moidifier otherwise
            //if(token[1] && token[1]->type != TOKEN_EOL) {
            //    if(token[1]->type == TOKEN_PIPE) {
            //        st_index = find_symbol(st, token[0]->id);
            //        if(st_index) {
            //            //access_modifier(token, st, node, st_index);
            //        } else {
            //            fprintf(stderr, "[AST NODE]: lexeme `%s` doesn't exist"
            //                    "in the symbol table!\nExiting\n", token[0]->id);
            //        }
            //    } 
            //} else {
                node->value = deep_copy_string(node->value, token[0]->id);
                node->type = NODE_WORD;
            //}
            return node; 
        case TOKEN_STRING:
            node->value = deep_copy_string(node->value, token[0]->id);
            node->type = NODE_STRING;
            return node;
        case TOKEN_FLOAT:
            node->value = calloc(1, sizeof(double));
            *((double *)node->value + 0) = atof(token[0]->id);
            node->type = NODE_FLOAT;
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
            node->type = NODE_DATA_FRAME;
            node->value = init_data_frame(token);
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
        case TOKEN_PIPE:
        case TOKEN_EOL:
            fprintf(stderr, "[ERROR]: TOKEN_EOL passed to parse tree!");
            exit(1);
            return node;
    }
	return node;
}

//void * access_modifer(token_T ** token_list, symbol_table_t * st, ast_node_t * node, int st_index) {
//    int tl_index = 0;
//    p_df_index_t * pdfi = init_p_df_index_t();
//    
//    while(token_list[tl_index]->type != TOKEN_EOL) {
//        if(token_list[tl_index]->type == TOKEN_WORD) {
//            tl_index++;
//        } else if(token_list[tl_index]->type == TOKEN_PIPE) {
//            if(pdfi->size == 0) {
//                pdfi->bracs[pdfi->size] = atoi(token_list[tl_index + 1]->id);
//                pdfi->size++;
//            } else {
//                pdfi->bracs = realloc(pdfi->bracs, (pdfi->size + 1) * sizeof(int));
//                pdfi->bracs[pdfi->size] = atoi(token_list[tl_index + 1]->id);
//                pdfi->size++;
//            }
//            tl_index++;
//            tl_index++;
//        }
//    }
//
//    if(pdfi) {
//        free_p_df_index_t(pdfi);
//    }
//}

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
        case NODE_STRING:
            free((char *)node->value);
            break;
        case NODE_FLOAT:
            free((double *)node->value);
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

