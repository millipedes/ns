#ifndef OPE_H
#define OPE_H

typedef struct OPERATOR_T {
	char * op_name;
} operator_t;

operator_t * init_operator(char * op);
void free_operator(operator_t * op);

#endif
