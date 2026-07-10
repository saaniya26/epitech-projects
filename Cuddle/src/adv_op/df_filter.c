/*
** EPITECH PROJECT, 2025
** df_filter
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdbool.h>
#include "df_core/df_line.h"
#include "df_core/df_col.h"

static int filter(dataframe_t *df, const char *column,
    bool (*filter_func)(void *value))
{
    dataframe_line_t *line = NULL;
    dataframe_line_t *n_line = NULL;
    dataframe_column_t *col = NULL;

    if (df == NULL || column == NULL || filter_func == NULL)
        return FUNC_FAILED;
    n_line = df->lines;
    for (line = n_line; line != NULL; line = n_line) {
        n_line = line->next;
        col = df_col_get_name(line->cols, column);
        if (col == NULL)
            return FUNC_FAILED;
        if (filter_func(col->value) == FALSE)
            df_line_delete(line);
    }
    return FUNC_SUCCESS;
}

dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *value))
{
    dataframe_t *new_df = NULL;

    if (dataframe == NULL || column == NULL || filter_func == NULL)
        return NULL;
    new_df = df_dup(dataframe);
    if (new_df == NULL)
        return NULL;
    if (filter(new_df, column, filter_func) == FUNC_FAILED)
        return df_free_n(new_df);
    return new_df;
}
