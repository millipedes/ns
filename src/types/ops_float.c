/**
 * @file float.c
 * @brief This file contains the operator wrappes for the float type
 * @author Matthew C. Lindeman
 * @date January 16, 2022
 * @bug None know
 * @todo Nothing atm
 */
#include"include/ops_float.h"

/**
 * This function is the addition wrapper for type float
 * @param The first and second floats to be added
 * @return The result of the addition of the two integers
 */
void * float_addition_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(double));
    *(double *)result = *(double *)value_one + *(double *)value_two;
    return result;
} 
  
/**
 * This function is the subtraction wrapper for type float
 * @param The first and second floats to be subtracted
 * @return The result of the subtraction of the two floats
 */
void * float_subtraction_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(double));
    *(double *)result = *(double *)value_one - *(double *)value_two;
    return result;
} 

/**
 * This function is the multiplication wrapper for type float
 * @param The first and second floats to be multiplied
 * @return The result of the multiplication of the two floats
 */
void * float_multiplication_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(double));
    *(double *)result = *(double *)value_one * *(double *)value_two;
    return result;
}

/**
 * This function is the division wrapper for type float
 * @param The first and second floats to be divided
 * @return The result of the division of the two floats
 */
void * float_division_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(double));
    *(double *)result = *(double *)value_one / *(double *)value_two;
    return result;
} 

/**
 * This function is the division wrapper for type float
 * @param The first and second floats to be divided
 * @return The result of the division of the two floats
 */
void * float_power_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(double));
    *(double *)result = (double)pow(*(double *)value_one, *(double *)value_two);
    return result;
}

/**
 * This function is the less than wrapper for type float
 * @param The first and second floats to be compared
 * @return 0: false 1: true
 */
void * float_less_than_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(double));
    if(*(double *)value_one < *(double *)value_two) {
        *(double *)result = 1;
        return result;
    } else {
        *(double *)result = 0;
        return result;
    }
}

/**
 * This function is the greater than wrapper for type float
 * @param The first and second floats to be compared
 * @return 0: false 1: true
 */
void * float_greater_than_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(double));
    if(*(double *)value_one > *(double *)value_two) {
        *(double *)result = 1;
        return result;
    } else {
        *(double *)result = 0;
        return result;
    }
}

/**
 * This function is the equal test to wrapper for type float
 * @param The first and second floats to be compared
 * @return 0: false 1: true
 */
void * float_equal_test_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(double));
    if(*(double *)value_one == *(double *)value_two) {
        *(double *)result = 1;
        return result;
    } else {
        *(double *)result = 0;
        return result;
    }
}

/**
 * This function is the less than or equal to wrapper for type float
 * @param The first and second floats to be compared
 * @return 0: false 1: true
 */
void * float_less_than_equal_to_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(double));
    if(*(double *)value_one <= *(double *)value_two) {
        *(double *)result = 1;
        return result;
    } else {
        *(double *)result = 0;
        return result;
    }
}

/**
 * This function is the greater than or equal to wrapper for type float
 * @param The first and second floats to be compared
 * @return 0: false 1: true
 */
void * float_greater_than_equal_to_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(double));
    if(*(double *)value_one >= *(double *)value_two) {
        *(double *)result = 1;
        return result;
    } else {
        *(double *)result = 0;
        return result;
    }
}

/**
 * This function is the not equal to wrapper for type float
 * @param The first and second floats to be compared
 * @return 0: false 1: true
 */
void * float_not_equal_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(double));
    if(*(double *)value_one != *(double *)value_two) {
        *(double *)result = 1;
        return result;
    } else {
        *(double *)result = 0;
        return result;
    }
}

