/**
 * @file integer.h
 * @brief This file contains function definitions for the integer.c file
 * @author Matthew C. Lindeman
 * @date January 08, 2022
 * @bug None know
 * @todo Nothing atm
 */
#ifndef INT_OP_H
#define INT_OP_H

#include<stdlib.h>
#include<math.h>

void * integer_addition_operator(void * value_one, void * value_two);
void * integer_subtraction_operator(void * value_one, void * value_two);
void * integer_division_operator(void * value_one, void * value_two);
void * integer_multiplication_operator(void * value_one, void * value_two);
void * integer_power_operator(void * value_one, void * value_two);
void * integer_less_than_operator(void * value_one, void * value_two);
void * integer_greater_than_operator(void * value_one, void * value_two);
void * integer_equal_test_operator(void * value_one, void * value_two);
void * integer_less_than_equal_to_operator(void * value_one, void * value_two);
void * integer_greater_than_equal_to_operator(void * value_one, void * value_two);
void * integer_not_equal_operator(void * value_one, void * value_two);

#endif
