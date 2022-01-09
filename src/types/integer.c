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
int addition_operator(int value_one, int value_two) {
    return value_one + value_two;
}
 
/**
 * This function is the subtraction wrapper for type integer
 * @param The first and second integers to be subtracted
 * @return The result of the subtraction of the two integers
 */
int subtraction_operator(int value_one, int value_two) {
    return value_one - value_two;
} 

/**
 * This function is the multiplication wrapper for type integer
 * @param The first and second integers to be multiplied
 * @return The result of the multiplication of the two integers
 */
int multiplication_operator(int value_one, int value_two) {
    return value_one * value_two;
}

/**
 * This function is the division wrapper for type integer
 * @param The first and second integers to be divided
 * @return The result of the division of the two integers
 */
int division_operator(int value_one, int value_two) {
    return value_one / value_two;
} 

/**
 * This function is the division wrapper for type integer
 * @param The first and second integers to be divided
 * @return The result of the division of the two integers
 */
int power_operator(int value_one, int value_two) {
    return (int)pow(value_one, value_two);
}

/**
 * This function is the less than wrapper for type integer
 * @param The first and second integers to be compared
 * @return 0: false 1: true
 */
int less_than_operator(int value_one, int value_two) {
    if(value_one > value_two) {
        return 0;
    } else {
        return 1;
    }
}

/**
 * This function is the greater than wrapper for type integer
 * @param The first and second integers to be compared
 * @return 0: false 1: true
 */
int greater_than_operator(int value_one, int value_two) {
    if(value_one > value_two) {
        return 1;
    } else {
        return 0;
    }
}
