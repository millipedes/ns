/**
 * @file float.h
 * @brief This file contains function definitions for the float.c file
 * @author Matthew C. Lindeman
 * @date January 16, 2022
 * @bug None know
 * @todo Nothing atm
 */
#ifndef FLOAT_OP_H
#define FLOAT_OP_H

#include<stdlib.h>
#include<math.h>

void * float_addition_operator(void * value_one, void * value_two);
void * float_subtraction_operator(void * value_one, void * value_two);
void * float_division_operator(void * value_one, void * value_two);
void * float_multiplication_operator(void * value_one, void * value_two);
void * float_power_operator(void * value_one, void * value_two);
void * float_less_than_operator(void * value_one, void * value_two);
void * float_greater_than_operator(void * value_one, void * value_two);
void * float_equal_test_operator(void * value_one, void * value_two);
void * float_less_than_equal_to_operator(void * value_one, void * value_two);
void * float_greater_than_equal_to_operator(void * value_one, void * value_two);
void * float_not_equal_operator(void * value_one, void * value_two);

#endif
