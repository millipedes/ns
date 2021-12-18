#ifndef CMM_LEX_H
#define CMM_LEX_H
#include "../../tokenizer/include/token.h"
#include<stdio.h>

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
void lexer_advance(lexer_T * lexer);
void lexer_skip_whitespace(lexer_T * lexer);
void free_lexer(lexer_T * lexer);

#endif
