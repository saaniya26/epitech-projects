/*
** EPITECH PROJECT, 2025
** df_apply
** File description:
** Cuddle
*/

#include <stdlib.h>
#include <stdbool.h>
#include "df_core/df_line.h"
#include "df_core/df_col.h"

static int apply(dataframe_t *df, const char *column,
    void *(*apply_func)(void *value))
{
    dataframe_line_t *line = NULL;
    dataframe_line_t *n_line = NULL;
    dataframe_column_t *col = NULL;
    void *prev_value = NULL;

    if (df == NULL || column == NULL || apply_func == NULL)
        return FUNC_FAILED;
    n_line = df->lines;
    for (line = n_line; line != NULL; line = n_line) {
        n_line = line->next;
        col = df_col_get_name(line->cols, column);
        if (col == NULL)
            continue;
        prev_value = col->value;
        col->value = apply_func(col->value);
        free(prev_value);
    }
    return FUNC_SUCCESS;
}

dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value))
{
    dataframe_t *new_df = NULL;

    if (dataframe == NULL || column == NULL || apply_func == NULL)
        return NULL;
    new_df = df_dup(dataframe);
    if (new_df == NULL)
        return NULL;
    if (apply(new_df, column, apply_func) == FUNC_FAILED)
        return df_free_n(new_df);
    return new_df;
}
