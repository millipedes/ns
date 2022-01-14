/**
 * @file abstract_syntax_tree.h
 * @brief This file contains the definitions of the functions in 
 * abstract_syntax_tree.c
 * @author Matthew C. Lindeman
 * @date 12/22/21
 * @bug None known
 * @todo Nothing atm
 */
#ifndef AST_H
#define AST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"node_types.h"
#include"abstract_syntax_tree_node.h"
#include"../../constants_macros/include/constants.h"
#include"../../symbol_table/include/symbol_table.h"
#include"../../tokenizer/include/token_types.h"
#include"../../tokenizer/include/token.h"
#include"../../types/include/integer.h"
#include"../../types/include/data_frame.h"

typedef struct ABSTRACT_SYNTAX_TREE {
	struct ABSTRACT_SYNTAX_TREE ** children;
	ast_node_t * node;
	int no_children;
} ast_t;

ast_t * init_ast(void);
ast_t * generate_tree(token_T ** token_list, symbol_table_t * st, ast_t * ast);
void * evaluate_tree(ast_t * ast, symbol_table_t * st);
token_T *** initialize_potential_operands(int number_of_operands);
void free_potential_operands(token_T *** list_of_list, int number_of_operands);
void ** initialize_potential_values(ast_t * ast, symbol_table_t * st);
void free_potential_values(void ** values, ast_t * ast);
int get_list_size(token_T ** list);
void print_tree(ast_t * ast);
void free_tree(ast_t * ast);

#endif
