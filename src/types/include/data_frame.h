#ifndef DATF_H
#define DATF_H

#include<stdlib.h>
#include<string.h>
#include"../../symbol_table/include/symbol_table.h"
#include"../../types/include/types.h"
#include"../../tokenizer/include/token.h"
#include"../../tokenizer/include/token_types.h"

typedef struct DATA_FRAME_T {
    void ** comps;
    int length;
    types type;
}data_frame_t;

typedef struct P_DF_INDEX_T {
    int * bracs;
    int size;
}p_df_index_t;

data_frame_t * init_data_frame(token_T ** token_list);
token_T ** get_sub_list(token_T ** list, int start, int end);
token_T *** initialize_potential_data_frames(int number_of_df);
void free_potential_data_frames(token_T *** list_of_list, int number_of_data_frames);
int get_list_size(token_T ** list);
data_frame_t * clone_data_frame(data_frame_t * df);
char * clone_string(char * src, char * dest);
void print_data_frame(data_frame_t * df);
void free_data_frame(data_frame_t * df);
p_df_index_t * init_p_df_index_t(void);
void free_p_df_index_t(p_df_index_t * pdfi);

#endif
