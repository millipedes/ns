#include"include/types.h"

void * addition_operator(void * value_one, void * value_two, types type) {
    switch(type) {
        case INTEGER:
            return integer_addition_operator(value_one, value_two);
        case DATA_FRAME:
            break;
        case FLOAT:
            return float_addition_operator(value_one, value_two);
        case RESERVED:
            fprintf(stderr, "[OPERATOR]: trying to add reserved types\nExiting\n");
            exit(1);
    }
    return NULL;
}

void * subtraction_operator(void * value_one, void * value_two, types type) {
    switch(type) {
        case INTEGER:
            return integer_subtraction_operator(value_one, value_two);
        case DATA_FRAME:
            break;
        case FLOAT:
            return float_subtraction_operator(value_one, value_two);
        case RESERVED:
            fprintf(stderr, "[OPERATOR]: trying to sub reserved types\nExiting\n");
            exit(1);
    }
    return NULL;
}

void * division_operator(void * value_one, void * value_two, types type) {
    switch(type) {
        case INTEGER:
            return integer_division_operator(value_one, value_two);
        case FLOAT:
            return float_division_operator(value_one, value_two);
        case DATA_FRAME:
            break;
        case RESERVED:
            fprintf(stderr, "[OPERATOR]: trying to div reserved types\nExiting\n");
            exit(1);
    }
    return NULL;
}

void * multiplication_operator(void * value_one, void * value_two, types type) {
    switch(type) {
        case INTEGER:
            return integer_multiplication_operator(value_one, value_two);
        case FLOAT:
            return float_multiplication_operator(value_one, value_two);
        case DATA_FRAME:
            break;
        case RESERVED:
            fprintf(stderr, "[OPERATOR]: trying to mult reserved types\nExiting\n");
            exit(1);
    }
    return NULL;
}

void * power_operator(void * value_one, void * value_two, types type) {
    switch(type) {
        case INTEGER:
            return integer_power_operator(value_one, value_two);
        case FLOAT:
            return float_power_operator(value_one, value_two);
        case DATA_FRAME:
            break;
        case RESERVED:
            fprintf(stderr, "[OPERATOR]: trying to pow reserved types\nExiting\n");
            exit(1);
    }
    return NULL;
}

void * less_than_operator(void * value_one, void * value_two, types type) {
    switch(type) {
        case INTEGER:
            return integer_less_than_operator(value_one, value_two);
        case FLOAT:
            return float_less_than_operator(value_one, value_two);
        case DATA_FRAME:
            break;
        case RESERVED:
            fprintf(stderr, "[OPERATOR]: trying to lt reserved types\nExiting\n");
            exit(1);
    }
    return NULL;
}

void * greater_than_operator(void * value_one, void * value_two, types type) {
    switch(type) {
        case INTEGER:
            return integer_greater_than_operator(value_one, value_two);
        case FLOAT:
            return float_greater_than_operator(value_one, value_two);
        case DATA_FRAME:
            break;
        case RESERVED:
            fprintf(stderr, "[OPERATOR]: trying to gt reserved types\nExiting\n");
            exit(1);
    }
    return NULL;
}

void * equal_test_operator(void * value_one, void * value_two, types type) {
    switch(type) {
        case INTEGER:
            return integer_equal_test_operator(value_one, value_two);
        case FLOAT:
            return float_equal_test_operator(value_one, value_two);
        case DATA_FRAME:
            break;
        case RESERVED:
            fprintf(stderr, "[OPERATOR]: trying to eq reserved types\nExiting\n");
            exit(1);
    }
    return NULL;
}

void * less_than_equal_to_operator(void * value_one, void * value_two, types type) {
    switch(type) {
        case INTEGER:
            return integer_less_than_equal_to_operator(value_one, value_two);
        case FLOAT:
            return float_less_than_equal_to_operator(value_one, value_two);
        case DATA_FRAME:
            break;
        case RESERVED:
            fprintf(stderr, "[OPERATOR]: trying to lte reserved types\nExiting\n");
            exit(1);
    }
    return NULL;
}

void * greater_than_equal_to_operator(void * value_one, void * value_two, types type) {
    switch(type) {
        case INTEGER:
            return integer_greater_than_equal_to_operator(value_one, value_two);
        case FLOAT:
            return float_greater_than_equal_to_operator(value_one, value_two);
        case DATA_FRAME:
            break;
        case RESERVED:
            fprintf(stderr, "[OPERATOR]: trying to gte reserved types\nExiting\n");
            exit(1);
    }
    return NULL;
}

void * not_equal_operator(void * value_one, void * value_two, types type) {
    switch(type) {
        case INTEGER:
            return integer_not_equal_operator(value_one, value_two);
        case FLOAT:
            return float_not_equal_operator(value_one, value_two);
        case DATA_FRAME:
            break;
        case RESERVED:
            fprintf(stderr, "[OPERATOR]: trying to ne reserved types\nExiting\n");
            exit(1);
    }
    return NULL;
}

