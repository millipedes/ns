/**
 * @file variable.h
 * @brief This file contains the function definitions for the functions
 * variable.c
 * @author Matthew C. Lindeman
 * @date January 08, 2022
 * @bug None know
 * @todo Nothing atm
 */
#ifndef VAR_H
#define VAR_H

#include<stdio.h>
#include<stdlib.h>
#include"../../types/include/types.h"

typedef struct VARIABLE_T {
    void * value;
    types type;
}variable_t;

variable_t * init_variable(void * value, types type);
void free_variable(variable_t * variable);

#endif
