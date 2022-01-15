/**
* @file console.c
* @brief This file is responsible for those functions which the console should
* perform (i.e. appropriately delegating user input to its proper channels)
* @author Matthew C. Lindeman
* @date Sept 20, 2021
* @bug None currently
* @todo A lot
*/
#include"include/console.h"

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
    token_T ** token_list = generate_token_list(lexer);
	ast_t * ast = init_ast();

	ast = generate_tree(token_list, st, ast);

    ter_t * value = evaluate_tree(ast, st);

    switch (value->type) {
        case INTEGER:
            printf("%d\n", *(int *)value->result);
            free(value->result);
            free(value);
            break;
        case DATA_FRAME:
            //for(int i = 0; i < 
            break;
        case RESERVED:
            break;
    }

	// Free token list, maybe make unique function (looping headers lexer.c)
	for (int i = 0; token_list[i]->type != TOKEN_EOL; i++) {
		free_token(token_list[i]);
		if(token_list[i + 1]->type == TOKEN_EOL) {
			free_token(token_list[i + 1]);
			break;
		}
	}
	free(token_list);
    free_lexer(lexer);
	free_tree(ast);
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
