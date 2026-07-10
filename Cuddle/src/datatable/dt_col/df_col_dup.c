/*
** EPITECH PROJECT, 2025
** df_col_dup
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "df_core/df_col.h"
#include "df_core/df_types.h"
#include "utils.h"

dataframe_column_t *df_col_dup(dataframe_col_desc_t *desc,
    dataframe_column_t *src)
{
    dataframe_column_t *new_col = NULL;

    if (desc == NULL || src == NULL)
        return NULL;
    new_col = malloc(sizeof(dataframe_column_t));
    new_col->col_id = src->col_id;
    new_col->col_descriptor = desc;
    new_col->value = df_create_value(src->value, desc->type);
    new_col->next = NULL;
    return new_col;
}

dataframe_column_t *df_col_dup_chain(dataframe_col_desc_t *desc,
    dataframe_column_t *src)
{
    int index = 0;
    dataframe_column_t *new_col = NULL;

    if (desc == NULL || src == NULL)
        return NULL;
    for (; src != NULL; src = src->next) {
        if (df_col_chain(&new_col, df_col_dup(df_col_desc_get(desc, index),
            src)) == FUNC_FAILED)
            return new_col;
        index++;
    }
    return new_col;
}
