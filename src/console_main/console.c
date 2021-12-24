/**
* @file console.c
* @brief This file is responsible for those functions which the console should perform (i.e. appropriately delegating user input to its proper channels)
* @author Matthew C. Lindeman
* @date Sept 20, 2021
* @bug None currently
* @todo A lot
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"include/menus.h"
#include"../constants_macros/include/constants.h"
#include"../lexical_analyzer/include/lexer.h"
#include"../tokenizer/include/token.h"
#include"../tokenizer/include/token_stack.h"
#include"../symbol_table/include/symbol_table.h"
#include"../parser/include/abstract_syntax_tree.h"

/**
 * This function
 * @param user_input_buffer - the input buffer from the user
 * @return - 1 if the loop should exit, 0 if it should not exit
*/
int exit_check(char user_input_buffer[]) {
    user_input_buffer[strnlen(user_input_buffer, MAX_LINE) - 1] = '\0';
    if(strncmp(user_input_buffer, (const char *)"exit", MAX_LINE) == 0) {
        return 0;
    }
    return 1;
}

/**
 * This function executes a line of code written by the user
 * @param the inputted line
 * @return N/a 
 */
void execute_line(char user_input_buffer[], symbol_table_t * st) {
    lexer_T * lexer = init_lexer(user_input_buffer);
    token_stack_T * token_stack = init_token_stack(lexer_next_token(lexer));
	ast_t * ast;

    while(token_stack->current->type != TOKEN_EOL) {
        token_stack = push_token(token_stack, lexer_next_token(lexer));
    }

    //pop_print_stack(token_stack);
	ast = generate_tree(token_stack, st);
	print_tree(ast);
	//pop_print_stack(token_stack);
	free_tree(ast);
    free_lexer(lexer);
}

/**
 * This funciton starts the console
 */
void console_start(symbol_table_t * st) {
    char user_input_buffer[MAX_LINE];
    /*the buffer used to handle user input*/

    print_welcome_screen();
    while(exit_check(user_input_buffer)) {
        printf("|>");
        fgets(user_input_buffer, MAX_LINE, stdin);
        execute_line(user_input_buffer, st);
    }
}
