#ifndef TOK_ST_H
#define TOK_ST_H

#include"token.h"

typedef struct TOKEN_STACK_STRUCT {
    struct TOKEN_STACK_STRUCT * previous;
    token_T * current;
} token_stack_T;

token_stack_T * init_token_stack(token_T * token);
token_stack_T * push_token(token_stack_T * token_stack, token_T * token);
token_stack_T * pop_token(token_stack_T * token_stack);
token_stack_T * stack_from_list(token_T ** token_list);
void pop_print_stack(token_stack_T * token_stack);

#endif
