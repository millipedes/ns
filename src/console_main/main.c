/**
* @file main.c
* @brief the main function for the programming language
* @author Matthew C. Lindeman
* @date January 08, 2022
* @bug None know
* @todo Nothing atm
*/
#include<stdio.h>
#include"include/console.h"
#include"../symbol_table/include/symbol_table.h"

int main(void) {
	symbol_table_t * st = init_symbol_table();
    console_start(st);
	free_symbol_table(st);
    return 0;
}
