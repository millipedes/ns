#include<string.h>
#include<stdlib.h>
#include"include/operator.h"
#include"../constants_macros/include/constants.h"


operator_t * init_operator(char * op) {
	int op_size = strnlen(op, MAX_OPERATOR);
	operator_t * new_op = calloc(1, sizeof(struct OPERATOR_T));
	new_op->op_name = calloc(op_size, sizeof(char));
	for(int i = 0; i < op_size; i++) {
		new_op->op_name[i] = op[i];
	}
	return new_op;
}

void free_operator(operator_t * op) {
	if(op) {
		free(op->op_name);
		free(op);
	}
}
