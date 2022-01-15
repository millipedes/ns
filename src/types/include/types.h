/**
* @file types.h
* @brief This file contains the enumeration that contains types
* @author Matthew C. Lindeman
* @date January 09, 2022
* @bug None currently
* @todo None currently
*/
#ifndef TYPE_H
#define TYPE_H

#include<stdio.h>
#include<stdlib.h>
#include"integer.h"

typedef enum {
    INTEGER,
    DATA_FRAME,
    RESERVED
} types;

void * addition_operator(void * value_one, void * value_two, types type);
void * subtraction_operator(void * value_one, void * value_two, types type);
void * division_operator(void * value_one, void * value_two, types type);
void * multiplication_operator(void * value_one, void * value_two, types type);
void * power_operator(void * value_one, void * value_two, types type);
void * less_than_operator(void * value_one, void * value_two, types type);
void * greater_than_operator(void * value_one, void * value_two, types type);
void * equal_test_operator(void * value_one, void * value_two, types type);
void * less_than_equal_to_operator(void * value_one, void * value_two, types type);
void * greater_than_equal_to_operator(void * value_one, void * value_two, types type);
void * not_equal_operator(void * value_one, void * value_two, types type);

#endif
