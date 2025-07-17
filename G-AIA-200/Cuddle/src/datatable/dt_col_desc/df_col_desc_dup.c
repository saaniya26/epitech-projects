/*
** EPITECH PROJECT, 2025
** df_col_desc_chain
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "my.h"
#include "df_core/df_col.h"
#include "utils.h"

dataframe_col_desc_t *df_col_desc_dup(dataframe_col_desc_t *src)
{
    dataframe_col_desc_t *new_desc = NULL;
    dataframe_col_desc_t *curr_dup = NULL;

    if (src == NULL)
        return NULL;
    for (; src != NULL; src = src->next) {
        curr_dup = df_col_desc_create(src->type, my_strdup(src->column_name));
        if (curr_dup == NULL)
            return NULL;
        curr_dup->column_id = src->column_id;
        if (df_col_desc_chain(&new_desc, curr_dup) == FUNC_FAILED)
            return new_desc;
    }
    return new_desc;
}
