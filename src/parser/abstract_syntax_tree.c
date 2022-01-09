/**
 * @file abstract_syntax_tree.c
 * @brief This file contains the functions relating to making an abstract parse 
 * tree from a token stack
 * @author Matthew C. Lindeman
 * @date 12/22/21
 * @bug None known
 * @todo Nothing atm
 */
#include"include/abstract_syntax_tree.h"

/**
* This function initializes an abstaract syntax tree
* @param N/a
* @return The tree that was initialized
*/
ast_t * init_ast(void) {
	ast_t * ast = calloc(1, sizeof(struct ABSTRACT_SYNTAX_TREE));
	ast->node = NULL;
	ast->children = NULL;
	ast->no_children = 0;
	return ast;
}

/**
 * This function generates an ast from a token list
 * @param The token list, the symbol table, and an index (always pass 0)
 * @return The ast
 */
ast_t * generate_tree(token_T ** token_list, symbol_table_t * st, ast_t * ast) {
	int flag = 0;
    int operands = 0;
    token_T *** potential_operands;
    /* See initialize_potential_operands for better description of why this
     * exits
     */

	if(token_list[0]->type == TOKEN_INT || token_list[0]->type == TOKEN_WORD) {
		ast->node = init_node(token_list[0], st);
		ast->children = NULL;
		ast->no_children = 0;
		return ast;
    } else {
		switch(token_list[0]->type) {
			case TOKEN_L_PAREN:
                operands = 1;
                potential_operands = initialize_potential_operands(operands);
                potential_operands[0] = get_sub_list(token_list, 1, 
                        get_list_size(token_list));
                ast->no_children++;
                ast->children = calloc(ast->no_children, 
                        sizeof(struct ABSTRACT_SYNTAX_TREE *));
                ast->node = init_node(token_list[0], st);
                ast->children[0] = init_ast();
                ast->children[0] = generate_tree(potential_operands[0], st,
                        ast->children[0]);
                free_potential_operands(potential_operands, operands);
                return ast;
			case TOKEN_INITIAL:
			case TOKEN_WORD:
			case TOKEN_R_PAREN:
			case TOKEN_INT:
			case TOKEN_EOL:
			case TOKEN_SPACE:
			case TOKEN_L_BRACKET:
			case TOKEN_R_BRACKET:
			case TOKEN_SEMICOLON:
				printf("[ABSTRACT SYNTAX TREE]: Garbage Passed As AST NODE\n"
                        "Exiting\n");
				exit(1);
				break;
			case TOKEN_PLUS:
			case TOKEN_MINUS:
			case TOKEN_FS_DIVIDE:
			case TOKEN_STAR_MULT:
			case TOKEN_LESS_THAN:
			case TOKEN_GREATER_THAN:
			case TOKEN_CARROT_POW:
            case TOKEN_EQUAL_TEST:
            case TOKEN_LTE:
            case TOKEN_GTE:
            case TOKEN_NE:
            case TOKEN_ASSIGN:
				// BINARY OPERATORS
				ast->no_children++;
				ast->no_children++;
				ast->children = calloc(ast->no_children, 
                        sizeof(struct ABSTRACT_SYNTAX_TREE *));
				ast->node = init_node(token_list[0], st);
				ast->children[0] = init_ast();
				ast->children[1] = init_ast();
				/** Massive code blurb checking for + INT INT || + EXPR INT
				 * || + INT EXPT || + EXPR EXPR
				 */
				if(token_list[1]->type == TOKEN_INT && 
                        token_list[2]->type == TOKEN_INT) {
                    operands = 2;
                    potential_operands = initialize_potential_operands(operands);
					potential_operands[0] = get_sub_list(token_list, 1, 1);
					potential_operands[1] = get_sub_list(token_list, 2, 
                            get_list_size(token_list));
					ast->children[0] = generate_tree(potential_operands[0], st,
                            ast->children[0]);
					ast->children[1] = generate_tree(potential_operands[1], st,
                            ast->children[1]);
                    free_potential_operands(potential_operands, operands);
					return ast;
				} else if(token_list[1]->type == TOKEN_INT && 
                        token_list[2]->type == TOKEN_L_PAREN) {
                    operands = 2;
                    potential_operands = initialize_potential_operands(operands);
					potential_operands[0] = get_sub_list(token_list, 1, 1);
					potential_operands[1] = get_sub_list(token_list, 2,
                            get_list_size(token_list));
					ast->children[0] = generate_tree(potential_operands[0], st,
                            ast->children[0]);
					ast->children[1] = generate_tree(potential_operands[1], st,
                            ast->children[1]);
                    free_potential_operands(potential_operands, operands);
					return ast;
				} else if(token_list[1]->type == TOKEN_L_PAREN) {
					flag = 0;
					for(int i = 1; i < get_list_size(token_list); i++) {
						if(token_list[i]->type == TOKEN_L_PAREN) {
							flag++;
						}
						if(token_list[i]->type == TOKEN_R_PAREN) {
							flag--;
						}
						if(flag == 0) {
                            operands = 2;
                            potential_operands
                                = initialize_potential_operands(operands);
                            potential_operands[0] = get_sub_list(token_list, 1, i);
                            potential_operands[1] = get_sub_list(token_list,
                                    i + 1, get_list_size(token_list));
							ast->children[0] = generate_tree(potential_operands[0],
                                    st, ast->children[0]);
							ast->children[1] = generate_tree(potential_operands[1],
                                    st, ast->children[1]);
                            free_potential_operands(potential_operands,
                                    operands);
							return ast;
						}
					}
				}
				break;
		}
	}
	fprintf(stderr, "[ABSTRACT SYNTAX TREE]: Something went very wrong\n");
	return NULL;
}


/**
 * This function evaluates the ast
 * @param The ast and symbol table
 * @return The integer value of the evaluation of the tree
 */
void * evaluate_tree(ast_t * ast, symbol_table_t * st) {
    void * result;
    switch (ast->node->type) {
        case NODE_INT:
            result = calloc(1, sizeof(int));
            *(int *)result = *((int *)ast->node->value);
            return result;
        case NODE_L_PAREN:
            return evaluate_tree(ast->children[0], st);
        case NODE_CARROT_POW:
            return power_operator(evaluate_tree(ast->children[0], st),
                    evaluate_tree(ast->children[1], st));
        case NODE_PLUS:
            return addition_operator(evaluate_tree(ast->children[0], st),
                    evaluate_tree(ast->children[1], st));
        case NODE_MINUS:
            return subtraction_operator(evaluate_tree(ast->children[0], st),
                    evaluate_tree(ast->children[1], st));
        case NODE_STAR_MULT:
            return multiplication_operator(evaluate_tree(ast->children[0], st),
                    evaluate_tree(ast->children[1], st));
        case NODE_FS_DIVIDE:
            return division_operator(evaluate_tree(ast->children[0], st),
                    evaluate_tree(ast->children[1], st));
        case NODE_LESS_THAN:
            return less_than_operator(evaluate_tree(ast->children[0], st),
                    evaluate_tree(ast->children[1], st));
        case NODE_GREATER_THAN:
            return greater_than_operator(evaluate_tree(ast->children[0], st),
                    evaluate_tree(ast->children[1], st));
        case NODE_EQUAL_TEST:
            return equal_test_operator(evaluate_tree(ast->children[0], st),
                    evaluate_tree(ast->children[1], st));
        case NODE_LTE:
            return less_than_equal_to_operator(evaluate_tree(ast->children[0], st),
                    evaluate_tree(ast->children[1], st));
        case NODE_GTE:
            return greater_than_equal_to_operator(evaluate_tree(ast->children[0], st),
                    evaluate_tree(ast->children[1], st));
        case NODE_NE:
            return not_equal_operator(evaluate_tree(ast->children[0], st),
                    evaluate_tree(ast->children[1], st));
        case NODE_ASSIGN:
            break;
        default:
            fprintf(stderr, "[ABSTRACT SYNTAX TREE]: evaluate_tree function crashed\n");
            exit(1);
            break;
    }
    fprintf(stderr, "[ABSTRACT SYNTAX TREE]: evaluate_tree function crashed\n");
    exit(1);
}

/** This function requires some explaining in my opinion, so here we go :|
 *
 *
 * This function is a type of "wrapper" for making an efficient way to 
 * dynamically allocate a list of token_T**'s while still being able to 
 * reasonaby free them.  The need for this function arises from the fact that
 * across stack frames, the EOL_TOKEN gets lost from the list (as get_sub_list 
 * is called multiple times).  I could replace EOL_TOKEN on all lists, but this
 * would lead to one with two EOL_TOKENs and this would make it very difficult 
 * to free.
 * @param
 * @return
 */
token_T *** initialize_potential_operands(int number_of_operands) {
    token_T *** list_of_list = calloc(number_of_operands,
            sizeof(struct TOKEN_T **));
    return list_of_list;
}

/**
 * The free function for the potential_operands
 * @param the potential_operands and the number of operands
 * @return N/a
 */
void free_potential_operands(token_T *** list_of_list, int number_of_operands) {
    for (int i = 0; i < number_of_operands; i++) {
        for (int j = 0; list_of_list[i][j]->type != TOKEN_EOL; j++) {
            free_token(list_of_list[i][j]);
            if(list_of_list[i][j + 1]->type == TOKEN_EOL) {
                free_token(list_of_list[i][j + 1]);
                break;
            }
        }
        free(list_of_list[i]);
    }
    free(list_of_list);
}

/**
 * This funciton generates a deep copy of the list between start and end 
 * inclusive. If the sequence is not terminated by an EOL_TOKEN then this
 * function adds one.
 * @param The token_list, the start index (starting at 0), and the end index
 * (starting at 0).
 * @return The sub list of tokens
 */
token_T ** get_sub_list(token_T ** list, int start, int end) {
	if(start > end) {
		fprintf(stderr, "[ABSTRACT SYNTAX TREE]: from get_sub_list START: `%d`"
                " END `%d`\nExiting", start, end);
		exit(1);
	}
    token_T ** sub_list;

	if(start == end) {
		token_T ** sub_list = calloc(2, sizeof(struct TOKEN_T *));
		sub_list[0] = init_token(list[start]->id, list[start]->type);
        sub_list[1] = init_token((char *)"0", TOKEN_EOL);
		return sub_list;
	}

    // get_list_size rets list[size]->type == EOL, i.e. check one more
    if(list[end]->type == TOKEN_EOL) {
        sub_list = calloc(end - start + 1, sizeof(struct TOKEN_T *));
        for(int i = start; i < (end + 1); i++) {
            sub_list[i - start] = init_token(list[i]->id, list[i]->type);
        }
    } else {
        sub_list = calloc(end - start + 2, sizeof(struct TOKEN_T *));
        for(int i = start; i < (end + 2); i++) {
            if(i == end + 1) {
                    sub_list[i - start] = init_token((char *)"0", TOKEN_EOL);
            } else {
                sub_list[i - start] = init_token(list[i]->id, list[i]->type);
            }
        }
    }
    return sub_list;
}

/**
 * This function gets the size of a given token_list
 * @param the token list
 * @return the size as an integer
 */
int get_list_size(token_T ** list) {
	int size = 0;
	for(int i = 0; list[i]->type != TOKEN_EOL; i++) {
		size++;
	}
	return size;
}

/**
 * This function prints an ast
 * @param the ast
 * @return N/a
 */
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

/**
 * This function frees a given ast
 * @param the ast
 * @return N/a
 */
void free_tree(ast_t * ast) {
	if(ast->children == NULL) {
		if(ast->node) {
			free_node(ast->node);
		}
		if(ast) {
			free(ast);
		}
	} else if(ast->children != NULL) {
		for(int i = 0; i < ast->no_children; i++) {
			free_tree(ast->children[i]);
		}
		if(ast->children) {
			free(ast->children);
		}
		if(ast->node) {
			free_node(ast->node);
		}
		if(ast) {
			free(ast);
		}
	}
}
