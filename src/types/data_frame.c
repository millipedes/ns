#include"include/data_frame.h"

data_frame_t * init_data_frame(token_T ** token_list) {
    data_frame_t * data_frame = calloc(1, sizeof(struct DATA_FRAME_T));
    token_T *** p_df = NULL;
    data_frame->length = 0;
    int flag = 0;
    int tl_index = 0;

    while(token_list[data_frame->length]->type != TOKEN_R_BRACKET) {
        switch(token_list[data_frame->length]->type) {
            case TOKEN_INT:
                data_frame->type = INTEGER;
                while(token_list[data_frame->length]->type == TOKEN_INT) {
                    data_frame->length++;
                }
                data_frame->comps = calloc(data_frame->length, sizeof(int *));
                for (int i = 0; i < data_frame->length; i++) {
                    ((int **)data_frame->comps)[i] = calloc(1, sizeof(int));
                    *((int **)data_frame->comps)[i] = atoi(token_list[i]->id);
                }
                return data_frame;
            case TOKEN_FLOAT:
                data_frame->type = FLOAT;
                while(token_list[data_frame->length]->type == TOKEN_FLOAT) {
                    data_frame->length++;
                }
                data_frame->comps = calloc(data_frame->length, sizeof(double *));
                for (int i = 0; i < data_frame->length; i++) {
                    ((double **)data_frame->comps)[i] = calloc(1, sizeof(double));
                    *((double **)data_frame->comps)[i] = atof(token_list[i]->id);
                }
                return data_frame;
            case TOKEN_L_BRACKET:
                data_frame->type = DATA_FRAME;
                //---------------BEGIN GET LEN
                    do {
                        switch (token_list[tl_index]->type) {
                            case TOKEN_R_BRACKET:
                                flag--;
                                break;
                            case TOKEN_L_BRACKET:
                                flag++;
                                if(flag == 1) {
                                    data_frame->length++;
                                }
                                break;
                            default:
                                break;
                        }
                        tl_index++;
                    } while(flag != -1);

                //---------------END GET LEN

                //---------------CALLOC **
                data_frame->comps = calloc(data_frame->length, sizeof(struct DATA_FRAME_T *));
                p_df = initialize_potential_data_frames(data_frame->length);

                //---------------CALLOC/ASSIGN *
                for(int i = 0; i < data_frame->length; i++) {
                    flag = 0;
                    if(i == 0) {
                        p_df[i] = get_sub_list(token_list, 1, get_list_size(token_list));
                        data_frame->comps[i] = init_data_frame(p_df[i]);
                    } else {
                        do {
                            switch (token_list[tl_index]->type) {
                                case TOKEN_R_BRACKET:
                                    flag--;
                                    break;
                                case TOKEN_L_BRACKET:
                                    flag++;
                                    break;
                                default:
                                    break;
                            }
                            tl_index++;
                        } while(flag != 0);
                        /**================TODO==================
                         * Fix the whole bracket detection, tl_index doesn't work (i.e. [[1] [2] [1 2]])
                         */
                        //tl_index += 1; // to get from ']' to '['
                        p_df[i] = get_sub_list(token_list, tl_index, get_list_size(token_list));
                        data_frame->comps[i] = init_data_frame(p_df[i]);
                    }
                    //---------FINALLY ASSIGN
                }

                //--------------FREE SUB LIST
                free_potential_data_frames(p_df, data_frame->length);
                return data_frame;
            default:
                fprintf(stderr, "[INIT DF]: RESERVED member\nExiting\n");
                exit(1);
        }
    }

    return data_frame;
}

data_frame_t * clone_data_frame(data_frame_t * df) {
    data_frame_t * copy = calloc(1, sizeof(struct DATA_FRAME_T));
    copy->length = df->length;
    switch (df->type) {
        case INTEGER:
            copy->type = df->type;
            copy->comps = calloc(df->length, sizeof(int *));
            for(int i = 0; i < df->length; i++) {
                copy->comps[i] = calloc(1, sizeof(int));
                *((int *)copy->comps[i]) = *((int *)df->comps[i]);
            }
            break;
        case FLOAT:
            copy->type = df->type;
            copy->comps = calloc(df->length, sizeof(double *));
            for(int i = 0; i < df->length; i++) {
                copy->comps[i] = calloc(1, sizeof(double));
                *((double *)copy->comps[i]) = *((double *)df->comps[i]);
            }
            break;
        case STRING:
            copy->type = df->type;
            copy->comps = calloc(df->length, sizeof(char **));
            for (int i = 0; i < df->length; i++) {
                copy->comps[i] = clone_string((char *)copy->comps[i], (char *)df->comps[i]);
            }
            break;
        case DATA_FRAME:
            copy->type = df->type;
            copy->comps = calloc(df->length, sizeof(struct DATA_FRAME_T *));
            for(int i = 0; i < df->length; i++) {
                copy->comps[i] = clone_data_frame((data_frame_t *)df->comps[i]);
            }
            break;
        case RESERVED:
            fprintf(stderr, "[CLONE DATA] Error\nExiting\n");
            break;
    }
    return copy;
}

char * clone_string(char * src, char * dest) {
    size_t len = strnlen(src, MAX_LEN);
	dest = calloc(len + 1, sizeof(char));
	for(int i = 0; i < strnlen(src, MAX_LEN) + 1; i++) {
		*(dest + i) = *(src + i);
	}
	return dest;
}

/**
 * This funciton generates a deep copy of the list between start and end 
 * inclusive. If the sequence is not terminated by an EOL_TOKEN then this
 * function adds one.
 * @param The token_list, the start index (starting at 0), and the end index
 * (starting at 0).
 * @return The sub list of tokens
 */
token_T ** get_sub_list(token_T ** list, int start, int end) {
	if(start > end) {
		fprintf(stderr, "[ABSTRACT SYNTAX TREE]: from get_sub_list START: `%d`"
                " END `%d`\nExiting", start, end);
		exit(1);
	}
    token_T ** sub_list;

	if(start == end) {
		token_T ** sub_list = calloc(2, sizeof(struct TOKEN_T *));
		sub_list[0] = init_token(list[start]->id, list[start]->type);
        sub_list[1] = init_token((char *)"0", TOKEN_EOL);
		return sub_list;
	}

    // get_list_size rets list[size]->type == EOL, i.e. check one more
    if(list[end]->type == TOKEN_EOL) {
        sub_list = calloc(end - start + 1, sizeof(struct TOKEN_T *));
        for(int i = start; i < (end + 1); i++) {
            sub_list[i - start] = init_token(list[i]->id, list[i]->type);
        }
    } else {
        sub_list = calloc(end - start + 2, sizeof(struct TOKEN_T *));
        for(int i = start; i < (end + 2); i++) {
            if(i == end + 1) {
                    sub_list[i - start] = init_token((char *)"0", TOKEN_EOL);
            } else {
                sub_list[i - start] = init_token(list[i]->id, list[i]->type);
            }
        }
    }
    return sub_list;
}

token_T *** initialize_potential_data_frames(int number_of_df) {
    token_T *** list_of_list = calloc(number_of_df,
            sizeof(struct token_T **));
    return list_of_list;
}

void free_potential_data_frames(token_T *** list_of_list, int number_of_data_frames) {
    for (int i = 0; i < number_of_data_frames; i++) {
        for (int j = 0; list_of_list[i][j]->type != TOKEN_EOL; j++) {
            free_token(list_of_list[i][j]);
            if(list_of_list[i][j + 1]->type == TOKEN_EOL) {
                free_token(list_of_list[i][j + 1]);
                break;
            }
        }
        free(list_of_list[i]);
    }
    free(list_of_list);
}

/**
 * This function gets the size of a given token_list
 * @param the token list
 * @return th size as an integer
 */
int get_list_size(token_T ** list) {
	int size = 0;
	for(int i = 0; list[i]->type != TOKEN_EOL; i++) {
		size++;
	}
	return size;
}

void print_data_frame(data_frame_t * df) {
    switch (df->type) {
        case INTEGER:
            printf("[");
            for(int i = 0; i < df->length; i++) {
                if(i == 0) {
                    printf("%d", *((int **)df->comps)[i]);
                } else {
                    printf(" %d", *((int **)df->comps)[i]);
                }
            }
            printf("]");
            break;
        case FLOAT:
            printf("[");
            for(int i = 0; i < df->length; i++) {
                if(i == 0) {
                    printf("%lf", *((double *)df->comps[i]));
                } else {
                    printf(" %lf", *((double *)df->comps[i]));
                }
            }
            printf("]");
            break;
        case STRING:
            printf("[");
            for(int i = 0; i < df->length; i++) {
                if(i == 0) {
                    printf("%s", (char *)df->comps[i]);
                } else {
                    printf(" %s", (char *)df->comps[i]);
                }
            }
            printf("]");
            break;
        case DATA_FRAME:
            //printf("[");
            for (int i = 0; i < df->length; i++) {
                print_data_frame(((data_frame_t **)df->comps)[i]);
            }
            //printf("]");
            break;
        case RESERVED:
            fprintf(stderr, "[PRINT DATA FRAME]: RESERVED data frame type\nExiting\n");
            exit(1);
    }
}

void free_data_frame(data_frame_t * df) {
    if(df->type == INTEGER) {
        for(int i = 0; i < df->length; i++) {
            free(((int **)df->comps)[i]);
        }
        if(df) {
            free(df);
        }
    } else if(df->type == DATA_FRAME) {
        for(int i = 0; i < df->length; i++) {
            free_data_frame(((data_frame_t **)df->comps)[i]);
        }
        free(df->comps);
        free(df);
    }
}
