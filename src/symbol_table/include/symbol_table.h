#ifndef SYM_H
#define SYM_H

#define SIZE_INIT_ST 1

typedef struct SYMBOL_TABLE_T {
	char ** keys;
	void ** values;
	int no_symbols;
} symbol_table_t;

symbol_table_t * init_symbol_table(void);
void init_null_st_entry(symbol_table_t * st, char * entry);
void deep_copy_string(char * str, char * dest);
int find_symbol(symbol_table_t * st, char * key_to_check);
symbol_table_t * add_symbol(char * key, void * value);
void free_symbol_table(symbol_table_t * st);

#endif
