/*
** EPITECH PROJECT, 2025
** df_get_value
** File description:
** Cuddle
*/

#include <stdlib.h>
#include <stdbool.h>
#include "df_core/df_line.h"
#include "df_core/df_col.h"

void *df_get_value(dataframe_t *dataframe, int row, const char *column)
{
    dataframe_line_t *line = NULL;
    dataframe_column_t *col = NULL;

    if (dataframe == NULL || row < 0 || column == NULL)
        return NULL;
    if (row > dataframe->nb_rows)
        return NULL;
    line = df_line_get(dataframe->lines, row);
    if (line == NULL)
        return NULL;
    col = df_col_get_name(line->cols, column);
    return col != NULL ? col->value : NULL;
}
