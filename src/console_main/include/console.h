#ifndef CON_H
#define CON_H

#include"../../symbol_table/include/symbol_table.h"

int exit_check(char user_input_buffer[]);
void execute_line(char user_input_buffer[], symbol_table_t * st);
void console_start(symbol_table_t * st);

#endif
