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
	if(token_list[0]->type == TOKEN_INT || token_list[0]->type == TOKEN_WORD) {
		ast->node = init_node(token_list[0], st);
		ast->children = NULL;
		ast->no_children = 0;
		return ast;
    } else {
		switch(token_list[0]->type) {
			case TOKEN_L_PAREN:
			case TOKEN_INITIAL:
			case TOKEN_WORD:
			case TOKEN_R_PAREN:
			case TOKEN_INT:
			case TOKEN_EOL:
			case TOKEN_SPACE:
			case TOKEN_L_BRACKET:
			case TOKEN_R_BRACKET:
			case TOKEN_SEMICOLON:
				printf("[ABSTRACT SYNTAX TREE]: Garbage Passed As AST NODE\nExiting\n");
				exit(1);
				break;
			case TOKEN_PLUS:
			case TOKEN_MINUS:
			case TOKEN_FS_DIVIDE:
			case TOKEN_STAR_MULT:
			case TOKEN_LESS_THAN:
			case TOKEN_GREATER_THAN:
			case TOKEN_CARROT_POW:
				// BINARY OPERATORS
				ast->no_children++;
				ast->no_children++;
				ast->children = calloc(ast->no_children, sizeof(struct ABSTRACT_SYNTAX_TREE *));
				ast->node = init_node(token_list[0], st);
				ast->children[0] = init_ast();
				ast->children[1] = init_ast();
				/** Massive code blurb checking for + INT INT || + EXPR INT
				 * || + INT EXPT || + EXPR EXPR
				 */
				if((token_list[1]->type == TOKEN_INT && token_list[2]->type == TOKEN_INT) || (token_list[1]->type == TOKEN_WORD && token_list[2]->type == TOKEN_INT) || (token_list[1]->type == TOKEN_INT && token_list[2]->type == TOKEN_WORD) || (token_list[1]->type == TOKEN_WORD && token_list[2]->type == TOKEN_WORD)) {
					ast->children[0] = generate_tree(get_sub_list(token_list, 1, 2), st, ast);
					ast->children[1] = generate_tree(get_sub_list(token_list, 1, 2), st, ast);
					return ast;
				} else if((token_list[1]->type == TOKEN_INT && token_list[2]->type == TOKEN_L_PAREN) || (token_list[1]->type == TOKEN_WORD && token_list[2]->type == TOKEN_L_PAREN)) {
					ast->children[0] = generate_tree(get_sub_list(token_list, 1, 2), st, ast);
					ast->children[1] = generate_tree(get_sub_list(token_list, 1, 2), st, ast);
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
							ast->children[0] = generate_tree(get_sub_list(token_list, 1, 2), st, ast);
							ast->children[1] = generate_tree(get_sub_list(token_list, 1, 2), st, ast);
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

token_T ** get_sub_list(token_T ** list, int start, int end) {
	if(start > end) {
		fprintf(stderr, "[ABSTRACT SYNTAX TREE]: from get_sub_list START: `%d` END `%d`\nExiting", start, end);
		exit(1);
	}
	token_T ** sub_list = calloc(end - start, sizeof(struct TOKEN_T *));
	for(int i = start; i < end; i++) {
		sub_list[i - start] = init_token(list[i]->id, list[i]->type);
	}
	return sub_list;
}

int get_list_size(token_T ** list) {
	int size = 0;
	for(int i = 0; list[i]->type != TOKEN_EOL; i++) {
		size = i;
	}
	return size;
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

void free_tree(ast_t * ast) {
	if(ast->children == NULL) {
		free_node(ast->node);
		free(ast);
	} else if(ast->children != NULL) {
		for(int i = 0; i < ast->no_children; i++) {
			free_tree(ast);
		}
		free_node(ast->node);
		free(ast);
	}
}
