#ifndef TOK_H
#define TOK_H
#include"token_types.h"

typedef struct TOKEN_STRUCT {
    char * id;
    token_type type;
} token_T;

token_T * init_token(char * id, int type);
void print_token_list(token_T ** token_list);
char * token_to_str(token_T * token);
int is_operator(token_T * token);
int operator_degree(token_T * token);
void free_token(token_T * token);

#endif
