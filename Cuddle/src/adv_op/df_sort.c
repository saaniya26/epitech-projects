/*
** EPITECH PROJECT, 2025
** df_sort
** File description:
** Cuddle
*/

#include <stdio.h>
#include "df_core/df_line.h"

dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool (*sort_func)(void *value1, void *value2))
{
    dataframe_t *new_df = NULL;

    if (dataframe == NULL || column == NULL || sort_func == NULL)
        return NULL;
    new_df = df_dup(dataframe);
    if (new_df == NULL)
        return NULL;
    if (df_line_quick_sort(new_df, sort_func, column) == FUNC_FAILED)
        return df_free_n(new_df);
    return new_df;
}
