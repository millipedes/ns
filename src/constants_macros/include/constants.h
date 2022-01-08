#ifndef CONST_H
#define CONST_H

#include"../../symbol_table/include/operator.h"
#include"../../symbol_table/include/variable.h"

#define MAX_LINE 4096
#define MAX_OPERATOR 16
#define MAX_LEN 80
#define ST_PRESET_SIZE 5
#define typename(x) _Generic((x),		\
	  char *: "std_pointer",		    \
	   int *: "std_pointer",			\
      void *: "void pointer",           \
operator_t *: "operator_pointer",   	\
variable_t *: "pointer to variable"     \
)

#endif
