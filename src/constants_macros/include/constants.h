/**
 * @file constants.h
 * @brief This file contains all of the constants and macros used in the
 * prorgamming language
 * @author Matthew C. Lindeman
 * @date January 08, 2022
 * @bug None currently
 * @todo None currently
 */
#ifndef CONST_H
#define CONST_H

#include"../../symbol_table/include/operator.h"
#include"../../symbol_table/include/variable.h"

#define MAX_LINE 4096
#define MAX_OPERATOR 16
#define MAX_LEN 80
#define ST_PRESET_SIZE 3
#define typename(x) _Generic((x),		\
	  char *: "std_pointer",		    \
	   int *: "std_pointer",			\
      void *: "void pointer",           \
operator_t *: "operator_pointer",   	\
variable_t *: "pointer to variable"     \
)

#endif
