/**
 * @file lexer.c
 * @brief This file contains functions that relate to the functions of the
 * lexer.
 * @author Matthew C. Lindeman
 * @date January 08, 2022
 * @bug None known
 * @todo Nothing atm
 */
#include"include/lexer.h"

/**
 * This function initializes a lexer_t * struct
 * @param The IMMUTABLE source from the program to be lexed
 * @return the new lexer
 */
lexer_T * init_lexer(char * source) {
    lexer_T * lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->source = source;
    lexer->src_size = strnlen(source, MAX_LINE);
    lexer->c = lexer->source[0];
    return lexer;
}

/**
 * This function gets the next token from the input (moves the current
 * character up in the struct)
 * @param The lexer with the code to be read
 * @return The newly generated token
 */
token_T * lexer_next_token(lexer_T * lexer) {
    while(lexer->c != '\n' && lexer->c != '\r') {
        lexer_skip_whitespace(lexer);

        if(isalpha(lexer->c)) {
            return lexer_parse_word(lexer);
        }

        if(isdigit(lexer->c) && lexer->c != '!') {
            return lexer_parse_digit(lexer);
        }

        switch(lexer->c) {
            case '(':
                lexer_advance(lexer);
                return init_token((char *)"(", TOKEN_L_PAREN);
            case ')':
                lexer_advance(lexer);
                return init_token((char *)")", TOKEN_R_PAREN);
            case '^':
                lexer_advance(lexer);
                return init_token((char *)"^", TOKEN_CARROT_POW);
            case '\n':
            case '\r':
                lexer_advance(lexer);
                return init_token((char *)"\n", TOKEN_EOL);
            case '+':
                lexer_advance(lexer);
                return init_token((char *)"+", TOKEN_PLUS);
            case '-':
                lexer_advance(lexer);
                return init_token((char *)"-", TOKEN_MINUS);
            case '*':
                lexer_advance(lexer);
                return init_token((char *)"*", TOKEN_STAR_MULT);
            case '/':
                lexer_advance(lexer);
                return init_token((char *)"/", TOKEN_FS_DIVIDE);
            case '<':
                if(lexer_peak(lexer) == '=') {
                    lexer_advance(lexer);
                    lexer_advance(lexer);
                    return init_token((char *)"<=", TOKEN_LTE);
                } else {
                    lexer_advance(lexer);
                    return init_token((char *)"<", TOKEN_LESS_THAN);
                }
            case '>':
                if(lexer_peak(lexer) == '=') {
                    lexer_advance(lexer);
                    lexer_advance(lexer);
                    return init_token((char *)">=", TOKEN_GTE);
                } else {
                    lexer_advance(lexer);
                    return init_token((char *)">", TOKEN_GREATER_THAN);
                }
            case '=':
                if(lexer_peak(lexer) == '=') {
                    lexer_advance(lexer);
                    lexer_advance(lexer);
                    return init_token((char *)"==", TOKEN_EQUAL_TEST);
                } else {
                    lexer_advance(lexer);
                    return init_token((char *)"=", TOKEN_ASSIGN);
                }
            case '!':
                if(lexer_peak(lexer) == '=') {
                    lexer_advance(lexer);
                    lexer_advance(lexer);
                    return init_token((char *)"!=", TOKEN_NE);
                } else {
                    printf("[Error Generated from Lexer]: Unexpected Character `%c`"
                            "\n", lexer->c);
                    exit(1);
                    break;
                }
            case'[':
                lexer_advance(lexer);
                return init_token((char *)"[", TOKEN_L_BRACKET);
            case']':
                lexer_advance(lexer);
                return init_token((char *)"]", TOKEN_R_BRACKET);
            case';':
                lexer_advance(lexer);
                return init_token((char *)";", TOKEN_SEMICOLON);
            default:
                printf("[Error Generated from Lexer]: Unexpected Character `%c`"
                        "\n", lexer->c);
                exit(1);
                break;
        }
    }
	// The id doesn't matter since they are all deep copied/freed
    return init_token((char *)"0", TOKEN_EOL);
}

/**
 * This function parses a digit from some source provided by the lexer
 * @param The lexer
 * @return The digit as an integer token
 */
token_T * lexer_parse_digit(lexer_T * lexer) {
    char * integer = (char *)calloc(1, sizeof(char));
    char * digit = (char *)calloc(1, sizeof(char));
	token_T * token;
    while(isdigit(lexer->c)) {
        integer = (char *)realloc(integer, (strnlen(integer, MAX_LEN) + 1)
                * sizeof(char));
        *(digit + 0) = lexer->c;
        strncat(integer, digit, MAX_LINE);
        lexer_advance(lexer);
    }
	token = init_token(integer, TOKEN_INT);
    free(digit);
	free(integer);
    return token;
}

/**
 * This function parses a keyword from the lexer source
 * @param The lexer
 * @return the integer token
 */
token_T * lexer_parse_word(lexer_T * lexer) {
    char * keyword = (char *)calloc(1, sizeof(char));
    char * tmp = (char *)calloc(1, sizeof(char));
	token_T * token;
    // As long as current char is a character in the alphabet advance
    while(isalpha(lexer->c)) {
        keyword = (char *)realloc(keyword, (strnlen(keyword, MAX_LINE) + 1)
                * sizeof(char));
        *tmp = lexer->c;
        strncat(keyword, tmp, MAX_LINE);
        lexer_advance(lexer);
    }
	token = init_token(keyword, TOKEN_WORD);
    free(tmp);
	free(keyword);
    return token;
}

/**
 * This function takes a lexer and generates a list of tokens from the source
 * @TODO This function doesn't belong here, fix the library looping problem in
 * token
 * @param the lexer
 * @return the token list
 */
token_T ** generate_token_list(lexer_T * lexer) {
	int max = 1;
	int count = 0;
	token_T ** token_list = calloc(max, sizeof(token_T *));

	while(lexer->c != '\n' && lexer->c != '\r' && lexer->i < lexer->src_size) {
		if(count == max) {
			max *= 2;
			token_list = realloc(token_list, max * sizeof(token_T *));
		}
		token_list[count] = lexer_next_token(lexer);
		count++;
	}
	// For the EOL_TOKEN
	if(count == max) {
		max *= 2;
		token_list = realloc(token_list, max * sizeof(token_T *));
	}
	token_list[count] = lexer_next_token(lexer);
	count++;

	return token_list;
}

/**
 * This function peaks at the next character in source without changing
 * lexer->c
 * @param the lexer
 * @return the character we are peaking at
 */
char lexer_peak(lexer_T * lexer) {
    return lexer->source[lexer->i + 1];
}

/**
 * This function advances where the lexer points to by 1 (assuming valid)
 * @param the lexer
 * @return N/a
 */
void lexer_advance(lexer_T * lexer) {
    if((lexer->c != '\n' && lexer->c != '\r') && lexer->i < lexer->src_size) {
        lexer->i++;
        lexer->c = lexer->source[lexer->i];
    }
}

/**
 * This function skips whitespace in the source
 * @param the lexer
 * @return N/a
 */
void lexer_skip_whitespace(lexer_T * lexer) {
    if(lexer->c == ' ') {
        lexer_advance(lexer);
    }
}

/**
 * This function frees the lexer (surprisingly easy)
 * @param the lexer
 * @return N/a
 */
void free_lexer(lexer_T * lexer) {
    if(lexer) {
        free(lexer);
    }
}
