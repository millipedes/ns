/**
 * @file lexer.h
 * @brief This file contains the function definitions of those functions
 * in lexer.c
 * @author Matthew C. Lindeman
 * @date January 08, 2022
 * @bug None known
 * @todo Nothing atm
 */
#ifndef CMM_LEX_H
#define CMM_LEX_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "../../tokenizer/include/token.h"
#include"../../constants_macros/include/constants.h"

typedef struct LEXER_STRUCT {
    char * source;
    size_t src_size;
    char c;
    unsigned int i;
}lexer_T;

lexer_T * init_lexer(char * source);
token_T * lexer_next_token(lexer_T * lexer);
token_T * lexer_parse_digit(lexer_T * lexer);
token_T * lexer_parse_word(lexer_T * lexer);
token_T * lexer_parse_string(lexer_T * lexer);
token_T ** generate_token_list(lexer_T * lexer);
char lexer_peak(lexer_T * lexer);
void lexer_advance(lexer_T * lexer);
void lexer_skip_whitespace(lexer_T * lexer);
void free_lexer(lexer_T * lexer);

#endif
