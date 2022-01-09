/**
 * @file operator.h
 * @brief This file contains the function definitons relating to operator.c
 * @author Matthew C. Lindeman
 * @date January 08, 2022
 * @bug None know
 * @todo Nothing atm
 */
#ifndef OPE_H
#define OPE_H
#include<string.h>
#include<stdlib.h>
#include"../../constants_macros/include/constants.h"

typedef struct OPERATOR_T {
	char * op_name;
} operator_t;

operator_t * init_operator(char * op);
void free_operator(operator_t * op);

#endif
