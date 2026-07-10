/*
** EPITECH PROJECT, 2025
** df_col_create
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "my.h"
#include "dataframe.h"
#include "utils.h"

dataframe_col_desc_t *df_col_desc_get(dataframe_col_desc_t *cols_desc,
    int index)
{
    if (cols_desc == NULL || index < 0)
        return NULL;
    for (int i = 0; cols_desc != NULL; i++) {
        if (cols_desc->column_id == index)
            return cols_desc;
        cols_desc = cols_desc->next;
    }
    return NULL;
}

dataframe_col_desc_t *df_col_desc_get_name(dataframe_col_desc_t *cols_desc,
    const char *column)
{
    if (cols_desc == NULL || column == NULL)
        return NULL;
    for (int i = 0; cols_desc != NULL; i++) {
        if (my_strcmp(cols_desc->column_name, column) == CMP_EXACT)
            return cols_desc;
        cols_desc = cols_desc->next;
    }
    return NULL;
}

column_type_t df_col_desc_get_name_type(dataframe_col_desc_t *cols_desc,
    const char *column)
{
    if (cols_desc == NULL || column == NULL)
        return UNDEFINED;
    for (int i = 0; cols_desc != NULL; i++) {
        if (my_strcmp(cols_desc->column_name, column) == CMP_EXACT)
            return cols_desc->type;
        cols_desc = cols_desc->next;
    }
    return UNDEFINED;
}

column_type_t df_col_desc_get_type(dataframe_col_desc_t *cols_desc,
    int index)
{
    if (cols_desc == NULL || index < 0)
        return UNDEFINED;
    for (int i = 0; cols_desc != NULL; i++) {
        if (cols_desc->column_id == index)
            return cols_desc->type;
        cols_desc = cols_desc->next;
    }
    return UNDEFINED;
}
