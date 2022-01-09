/**
 * @file operator.c
 * @brief This file contains functions relating to the operator_t data type
 * @author Matthew C. Lindeman
 * @date January 08, 2022
 * @bug None know
 * @todo Nothing atm
 */
#include"include/operator.h"

/**
 * This function initializes an operator
 * @param The character pointer that defines the operator
 * (i.e. '+' || "!=" etc)
 * @return The operator
 */
operator_t * init_operator(char * op) {
	int op_size = strnlen(op, MAX_OPERATOR);
	operator_t * new_op = calloc(1, sizeof(struct OPERATOR_T));
	new_op->op_name = calloc(op_size, sizeof(char));
	for(int i = 0; i < op_size; i++) {
		new_op->op_name[i] = op[i];
	}
	return new_op;
}

/**
 * This function frees an operator
 * @param this function frees a given operator
 * @return N/a
 */
void free_operator(operator_t * op) {
	if(op) {
		free(op->op_name);
		free(op);
	}
}
