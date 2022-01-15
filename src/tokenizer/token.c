/**
* @file token.c
* @brief This file makes and performs various operations relating to the
* token_T struct defined in token.h
* @author Matthew C. Lindeman
* @date Oct 11, 2021
* @bug None currently
* @todo None currently
*/
#include"include/token.h"

/**
 * This function makes a pointer to a token ``object" with given identifier and
 * type.
 * @param  id                 the identifier of the token
 * @param  type               the type of the token
 * @return      a pointer the generated token
 */
token_T * init_token(char * id, int type) {
    token_T * token = calloc(1, sizeof(struct TOKEN_STRUCT));
    size_t len = strnlen(id, MAX_LINE);
    // NUL terminate => + 1
	token->id = calloc(len + 1, sizeof(char));
	for (int i = 0; i < len + 1; i++) {
		token->id[i] = id[i];
	}
    token->type = type;
    return token;
}

/**
 * This function prints all of the tokens in a list
 * @param token_list  the list of tokens to be printed
 */
void print_token_list(token_T ** token_list) {
    for(int i = 0; token_list[i]->type != TOKEN_EOL; i++) {
        printf("[TOKEN ID]: %s, [TOKEN TYPE]: %s\n", token_list[i]->id,
                token_to_str(token_list[i]));
    }
}

/**
 * This function takes a token and converts it to a character pointer form
 * @param The token to be stringified
 * @return the character pointer of the token type
 */
char * token_to_str(token_T * token) {
    switch(token->type) {
        case TOKEN_INITIAL:
            return (char *) "TOKEN_INITIAL";
        case TOKEN_INT:
            return (char *) "TOKEN_INT";
        case TOKEN_WORD:
            return (char *) "TOKEN_WORD";
        case TOKEN_L_PAREN:
            return (char *) "TOKEN_L_PAREN";
        case TOKEN_R_PAREN:
            return (char *) "TOKEN_R_PAREN";
        case TOKEN_CARROT_POW:
            return (char *) "TOKEN_CARROT_POW";
        case TOKEN_SPACE:
            return (char *) "TOKEN_SPACE";
        case TOKEN_PLUS:
            return (char *) "TOKEN_PLUS";
        case TOKEN_MINUS:
            return (char *) "TOKEN_MINUS";
        case TOKEN_STAR_MULT:
            return (char *) "TOKEN_STAR_MULT";
        case TOKEN_FS_DIVIDE:
            return (char *) "TOKEN_FS_DIVIDE";
        case TOKEN_LESS_THAN:
            return (char *) "TOKEN_LESS_THAN";
        case TOKEN_GREATER_THAN:
            return (char *) "TOKEN_GREATER_THAN";
        case TOKEN_L_BRACKET:
            return (char *) "TOKEN_L_BRACKET";
        case TOKEN_R_BRACKET:
            return (char *) "TOKEN_R_BRACKET";
        case TOKEN_SEMICOLON:
            return (char *) "TOKEN_SEMICOLON";
        case TOKEN_EQUAL_TEST:
            return (char *) "TOKEN_EQUAL_TEST"; 
        case TOKEN_LTE:
            return (char *) "TOKEN_LTE";
        case TOKEN_GTE:
            return (char *) "TOKEN_GTE";
        case TOKEN_NE:
            return (char *) "TOKEN_NE";
        case TOKEN_ASSIGN:
            return (char *) "TOKEN_ASSIGN";
        case TOKEN_EOL:
            return (char *) "TOKEN_EOL";
    }
    printf("[UNEXPECTED ERROR WHEN TOKENIZING]\n[TOKEN ID]: %s\n", token->id);
    return 0;
}

/**
 * This function determines if the token is an operator
 * @param The token
 * @return 0 if not op, 1 if op, -1 if error
 */
int is_operator(token_T * token) {
	switch(token->type) {
        case TOKEN_INITIAL:
        case TOKEN_INT:
        case TOKEN_SEMICOLON:
        case TOKEN_WORD:
        case TOKEN_EOL:
			return 0;
        case TOKEN_EQUAL_TEST:
        case TOKEN_LTE:
        case TOKEN_GTE:
        case TOKEN_NE:
        case TOKEN_ASSIGN:
        case TOKEN_L_PAREN:
        case TOKEN_R_PAREN:
        case TOKEN_L_BRACKET:
        case TOKEN_R_BRACKET:
        case TOKEN_CARROT_POW:
        case TOKEN_PLUS:
        case TOKEN_MINUS:
        case TOKEN_STAR_MULT:
        case TOKEN_FS_DIVIDE:
        case TOKEN_LESS_THAN:
        case TOKEN_GREATER_THAN:
        case TOKEN_SPACE:
			return 1;
	}
	return -1;
}

/**
 * This function determines the degree of an operator
 * @param The token of the operator
 * @return the degree of the operator (i.e. how many arguments does it have)
 */
int operator_degree(token_T * token) {
    switch(token->type) {
        case TOKEN_INITIAL:
        case TOKEN_INT:
        case TOKEN_WORD:
        case TOKEN_L_PAREN:
        case TOKEN_R_PAREN:
        case TOKEN_L_BRACKET:
        case TOKEN_R_BRACKET:
        case TOKEN_SEMICOLON:
            return 1;
        case TOKEN_EQUAL_TEST:
        case TOKEN_LTE:
        case TOKEN_GTE:
        case TOKEN_NE:
        case TOKEN_ASSIGN:
        case TOKEN_CARROT_POW:
        case TOKEN_PLUS:
        case TOKEN_MINUS:
        case TOKEN_STAR_MULT:
        case TOKEN_FS_DIVIDE:
        case TOKEN_LESS_THAN:
        case TOKEN_GREATER_THAN:
            return 2;
        case TOKEN_SPACE:
        case TOKEN_EOL:
        printf("[UNEXPECTED ERROR WHEN TOKENIZING]\n[TOKEN ID]: %s\n",
                token->id);
        return 0;
    }
    printf("[UNEXPECTED ERROR WHEN TOKENIZING]\n[TOKEN ID]: %s\n",
            token->id);
    return 0;
}

/**
 * This function frees a token
 * @param The token to be freed
 * @return N/a
 */
void free_token(token_T * token) {
    if(token->id) {
        free(token->id);
    }
    if(token) {
        free(token);
    }
}
