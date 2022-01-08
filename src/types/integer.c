#include"include/integer.h"

int addition_operator(int value_one, int value_two) {
    return value_one + value_two;
}
 
int subtraction_operator(int value_one, int value_two) {
    return value_one - value_two;
} 

int multiplication_operator(int value_one, int value_two) {
    return value_one * value_two;
} 
 
int division_operator(int value_one, int value_two) {
    return value_one / value_two;
} 
  
int power_operator(int value_one, int value_two) {
    return (int)pow(value_one, value_two);
}

int less_than_operator(int value_one, int value_two) {
    if(value_one > value_two) {
        return 0;
    } else {
        return 1;
    }
}

int greater_than_operator(int value_one, int value_two) {
    if(value_one > value_two) {
        return 1;
    } else {
        return 0;
    }
}
