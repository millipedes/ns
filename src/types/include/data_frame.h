#ifndef DATF_H
#define DATF_H

#include<stdlib.h>
#include"../../symbol_table/include/symbol_table.h"
#include"../../types/include/types.h"
#include"../../tokenizer/include/token.h"
#include"../../tokenizer/include/token_types.h"

typedef struct DATA_FRAME_T {
    void ** comps;
    int length;
    types type;
}data_frame_t;

data_frame_t * init_data_frame(token_T ** token_list, symbol_table_t * st);
token_T ** get_sub_list(token_T ** list, int start, int end);

#endif
