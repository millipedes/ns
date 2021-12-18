#include<stdio.h>
#include<stdlib.h>
#include"include/token_stack.h"
#include"include/token.h"
#include"include/token_types.h"

token_stack_T * init_token_stack(token_T * token) {
    token_stack_T * token_stack = calloc(1, sizeof(struct TOKEN_STACK_STRUCT *));
    token_stack->previous = NULL;
    token_stack->current = token;
    return token_stack;
}

token_stack_T * push_token(token_stack_T * token_stack, token_T * token) {
    token_stack_T * new_stack_top = init_token_stack(token);
    new_stack_top->previous = token_stack;
    return new_stack_top;
}

token_stack_T * pop_token(token_stack_T * token_stack) {
    token_stack_T * tmp = token_stack->previous;
    if(token_stack->current) {
        free_token(token_stack->current);
        free(token_stack);
    }
    return tmp;
}

void pop_print_stack(token_stack_T * token_stack) {
    while(token_stack->current != NULL && token_stack->previous != NULL) {
        printf("[TOKEN ID]: %s, [TOKEN]: %s\n", token_stack->current->id, token_to_str(token_stack->current));
        token_stack = pop_token(token_stack);
    }
    if(token_stack) {
        printf("[TOKEN ID]: %s, [TOKEN]: %s\n", token_stack->current->id, token_to_str(token_stack->current));
        pop_token(token_stack);
    }
}

token_stack_T * stack_from_list(token_T ** token_list) {
    token_stack_T * new_stack = init_token_stack(token_list[0]);
    for(int i = 1; token_list[i]->type != TOKEN_EOL; i++) {
        new_stack = push_token(new_stack, token_list[i]);
    }
    return new_stack;
}
