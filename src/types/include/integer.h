/**
 * @file integer.h
 * @brief This file contains function definitions for the integer.c file
 * @author Matthew C. Lindeman
 * @date January 08, 2022
 * @bug None know
 * @todo Nothing atm
 */
#ifndef TYPE_H
#define TYPE_H

#include<stdlib.h>
#include<math.h>

void * addition_operator(void * value_one, void * value_two);
void * subtraction_operator(void * value_one, void * value_two);
void * division_operator(void * value_one, void * value_two);
void * multiplication_operator(void * value_one, void * value_two);
void * power_operator(void * value_one, void * value_two);
void * less_than_operator(void * value_one, void * value_two);
void * greater_than_operator(void * value_one, void * value_two);
void * equal_test_operator(void * value_one, void * value_two);
void * less_than_equal_to_operator(void * value_one, void * value_two);
void * greater_than_equal_to_operator(void * value_one, void * value_two);
void * not_equal_operator(void * value_one, void * value_two);

#endif
