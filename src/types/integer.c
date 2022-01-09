/**
 * @file integer.c
 * @brief This file contains the operator wrappes for the integer type
 * @author Matthew C. Lindeman
 * @date January 08, 2022
 * @bug None know
 * @todo Nothing atm
 */
#include"include/integer.h"

/**
 * This function is the addition wrapper for type integer
 * @param The first and second integers to be added
 * @return The result of the addition of the two integers
 */
void * addition_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(int));
    *(int *)result = *(int *)value_one + *(int *)value_two;
    return result;
} 
  
/**
 * This function is the subtraction wrapper for type integer
 * @param The first and second integers to be subtracted
 * @return The result of the subtraction of the two integers
 */
void * subtraction_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(int));
    *(int *)result = *(int *)value_one - *(int *)value_two;
    return result;
} 

/**
 * This function is the multiplication wrapper for type integer
 * @param The first and second integers to be multiplied
 * @return The result of the multiplication of the two integers
 */
void * multiplication_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(int));
    *(int *)result = *(int *)value_one * *(int *)value_two;
    return result;
}

/**
 * This function is the division wrapper for type integer
 * @param The first and second integers to be divided
 * @return The result of the division of the two integers
 */
void * division_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(int));
    *(int *)result = *(int *)value_one / *(int *)value_two;
    return result;
} 

/**
 * This function is the division wrapper for type integer
 * @param The first and second integers to be divided
 * @return The result of the division of the two integers
 */
void * power_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(int));
    *(int *)result = (int)pow(*(int *)value_one, *(int *)value_two);
    return result;
}

/**
 * This function is the less than wrapper for type integer
 * @param The first and second integers to be compared
 * @return 0: false 1: true
 */
void * less_than_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(int));
    if(*(int *)value_one < *(int *)value_two) {
        *(int *)result = 1;
        return result;
    } else {
        *(int *)result = 0;
        return result;
    }
}

/**
 * This function is the greater than wrapper for type integer
 * @param The first and second integers to be compared
 * @return 0: false 1: true
 */
void * greater_than_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(int));
    if(*(int *)value_one > *(int *)value_two) {
        *(int *)result = 1;
        return result;
    } else {
        *(int *)result = 0;
        return result;
    }
}

/**
 * This function is the equal test to wrapper for type integer
 * @param The first and second integers to be compared
 * @return 0: false 1: true
 */
void * equal_test_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(int));
    if(*(int *)value_one == *(int *)value_two) {
        *(int *)result = 1;
        return result;
    } else {
        *(int *)result = 0;
        return result;
    }
}

/**
 * This function is the less than or equal to wrapper for type integer
 * @param The first and second integers to be compared
 * @return 0: false 1: true
 */
void * less_than_equal_to_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(int));
    if(*(int *)value_one <= *(int *)value_two) {
        *(int *)result = 1;
        return result;
    } else {
        *(int *)result = 0;
        return result;
    }
}

/**
 * This function is the greater than or equal to wrapper for type integer
 * @param The first and second integers to be compared
 * @return 0: false 1: true
 */
void * greater_than_equal_to_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(int));
    if(*(int *)value_one >= *(int *)value_two) {
        *(int *)result = 1;
        return result;
    } else {
        *(int *)result = 0;
        return result;
    }
}

/**
 * This function is the not equal to wrapper for type integer
 * @param The first and second integers to be compared
 * @return 0: false 1: true
 */
void * not_equal_operator(void * value_one, void * value_two) {
    void * result = calloc(1, sizeof(int));
    if(*(int *)value_one != *(int *)value_two) {
        *(int *)result = 1;
        return result;
    } else {
        *(int *)result = 0;
        return result;
    }
}

