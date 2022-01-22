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
            break;
        case DATA_FRAME:
            print_data_frame((data_frame_t *)value->result);
            printf("\n");
            free_data_frame((data_frame_t *)value->result);
            break;
        case STRING:
            printf("`%s`\n", (char *)value->result);
            free(value->result);
            break;
        case FLOAT:
            printf("%lf\n", *(double *)value->result);
            free(value->result);
            break;
        case RESERVED:
            free(value->result);
            break;
    }
    free(value);


	// Free token list, maybe make unique function (looping headers lexer.c)
    free_token_list(token_list);
    free_lexer(lexer);
	free_tree(ast);
}

/**
 * This funciton starts the console
 */
void console_start(symbol_table_t * st) {
    char user_input_buffer[MAX_LINE]  = {};
    /*the buffer used to handle user input*/

    print_welcome_screen();
    do {
        printf("|>");
        fgets(user_input_buffer, MAX_LINE, stdin);
        execute_line(user_input_buffer, st);
        user_input_buffer[strnlen(user_input_buffer, MAX_LINE) - 1] = '\0';
    } while(strncmp(user_input_buffer, (char *)"exit", MAX_LINE));
}
