/**
 * @file token_stack.c
 * @brief This file contains the functions for the token_stack_t structure
 * @author Matthew C. Lindeman
 * @date 12/22/21
 * @bug None known
 * @todo Nothing atm
 */
#include<stdio.h>
#include<stdlib.h>
#include"include/token_stack.h"
#include"include/token.h"
#include"include/token_types.h"

/**
 * This function initializes a token_sack given a token
 * @param a token
 * @return the initialized stack
 */
token_stack_T * init_token_stack(token_T * token) {
    token_stack_T * token_stack = calloc(1, sizeof(struct TOKEN_STACK_STRUCT *));
    token_stack->previous = NULL;
    token_stack->current = token;
    return token_stack;
}

/**
 * This function pushes a token onto the stack
 * @param The token_stack and the token to be pushed
 * @return The new token stack top
 */
token_stack_T * push_token(token_stack_T * token_stack, token_T * token) {
    token_stack_T * new_stack_top = init_token_stack(token);
    new_stack_top->previous = token_stack;
    return new_stack_top;
}

/**
 * This function pops a token
 * @param The token stack from which to pop
 * @return the new top of the stack
 */
token_stack_T * pop_token(token_stack_T * token_stack) {
    token_stack_T * tmp = token_stack->previous;
    if(token_stack->current) {
        free_token(token_stack->current);
        free(token_stack);
    }
    return tmp;
}

/**
 * This function pops the entire stack while printing it
 * @param The token_stack to be printed and popped
 * @return N/a 
 */
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

/**
 * A function from a previous iteration of this code-base.  It takes in a
 * token list and makes a stack from it.  It will likely be removed soon.
 * @param The token list
 * @return the token_stack
 */
token_stack_T * stack_from_list(token_T ** token_list) {
    token_stack_T * new_stack = init_token_stack(token_list[0]);
    for(int i = 1; token_list[i]->type != TOKEN_EOL; i++) {
        new_stack = push_token(new_stack, token_list[i]);
    }
    return new_stack;
}
