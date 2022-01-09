/**
 * @file variable.c
 * @brief This file contains the functions relating to variables
 * @author Matthew C. Lindeman
 * @date January 08, 2022
 * @bug None know
 * @todo Nothing atm
 */
#include"include/variable.h"

variable_t * init_variable(void * value, types type) {
    //TODO assign value correctly deep
    variable_t * variable = calloc(1, sizeof(struct VARIABLE_T));

    return variable;
}
      
void free_variable(variable_t * variable) {
    //TODO add suppport with a switch for other struct types
    if(variable->value) {
        free((char *)variable->value);
    }

    if(variable) {
        free(variable);
    }
}
