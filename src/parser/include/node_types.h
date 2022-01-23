/**
* @file node_types.h
* @brief This file contains the enumeration that contains the node types
* @author Matthew C. Lindeman
* @date January 08, 2022
* @bug None currently
* @todo None currently
*/
#ifndef NOD_TYPE_H
#define NOD_TYPE_H

typedef enum {
    NODE_INT,
    NODE_WORD,
    NODE_STRING,
    NODE_FLOAT,
    NODE_L_PAREN,
    NODE_R_PAREN,
    NODE_CARROT_POW,
    NODE_PLUS,
    NODE_MINUS,
    NODE_STAR_MULT,
    NODE_FS_DIVIDE,
    NODE_LESS_THAN,
    NODE_GREATER_THAN,
    NODE_DATA_FRAME,
    NODE_L_BRACKET,
    NODE_R_BRACKET,
    NODE_SEMICOLON,
    NODE_EQUAL_TEST,
    NODE_LTE,
    NODE_GTE,
    NODE_NE,
    NODE_ASSIGN,
    NODE_PIPE
} node_type;
#endif
