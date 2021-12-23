#ifndef CONST_H
#define CONST_H

#include"../../symbol_table/include/operator.h"

#define MAX_LINE 4096
#define MAX_OPERATOR 16
#define MAX_LEN 80
#define ST_PRESET_SIZE 5
#define typename(x) _Generic((x),		\
	  char *: "pointer to char",		\
	   int *: "pointer to int",			\
operator_t *: "pointer to operator"		\
)

#endif
