/*
** EPITECH PROJECT, 2025
** df_col_create
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "df_core/df_col.h"
#include "my.h"
#include "utils.h"

dataframe_column_t *df_col_get(dataframe_column_t *cols,
    int index)
{
    if (cols == NULL || index < 0)
        return NULL;
    for (int i = 0; cols != NULL; i++) {
        if (cols->col_id == index)
            return cols;
        cols = cols->next;
    }
    return NULL;
}

dataframe_column_t *df_col_get_name(dataframe_column_t *cols,
    const char *name)
{
    if (cols == NULL || name == NULL)
        return NULL;
    for (; cols != NULL; cols = cols->next) {
        if (my_strcmp(cols->col_descriptor != NULL ?
            cols->col_descriptor->column_name : NULL, name) == CMP_EXACT)
            return cols;
    }
    return NULL;
}
