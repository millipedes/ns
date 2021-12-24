#include<stdio.h>
#include"include/console.h"
#include"../symbol_table/include/symbol_table.h"

int main(void) {
	symbol_table_t * st = init_symbol_table();
    console_start(st);
	free_symbol_table(st);
    return 0;
}
