/**
* @file console.h
* @brief This file contains the definitions for those functions in console.c
* @author Matthew C. Lindeman
* @date January 08, 2022
* @bug None currently
* @todo None currently
*/
#ifndef CON_H
#define CON_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"menus.h"
#include"../../constants_macros/include/constants.h"
#include"../../lexical_analyzer/include/lexer.h"
#include"../../tokenizer/include/token.h"
#include"../../tokenizer/include/token_stack.h"
#include"../../symbol_table/include/symbol_table.h"
#include"../../parser/include/abstract_syntax_tree.h"
#include"../../symbol_table/include/symbol_table.h"

int exit_check(char user_input_buffer[]);
void execute_line(char user_input_buffer[], symbol_table_t * st);
void console_start(symbol_table_t * st);

#endif
