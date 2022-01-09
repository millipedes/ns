/**
* @file token_types.h
* @brief This file contains the enumeration that containst the token types
* @author Matthew C. Lindeman
* @date January 08, 2022
* @bug None currently
* @todo None currently
*/
#ifndef TOK_TYPE_H
#define TOK_TYPE_H

typedef enum {
    TOKEN_INITIAL,
    TOKEN_INT,
    TOKEN_WORD,
    TOKEN_L_PAREN,
    TOKEN_R_PAREN,
    TOKEN_CARROT_POW,
    TOKEN_SPACE,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR_MULT,
    TOKEN_FS_DIVIDE,
    TOKEN_LESS_THAN,
    TOKEN_GREATER_THAN,
    TOKEN_L_BRACKET,
    TOKEN_R_BRACKET,
    TOKEN_SEMICOLON,
    TOKEN_EOL
} token_type;
#endif
