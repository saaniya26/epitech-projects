/*
** EPITECH PROJECT, 2025
** df_line_free
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "df_core/df_core.h"
#include "df_core/df_col.h"
#include "utils.h"

void df_line_free(dataframe_line_t *line)
{
    dataframe_column_t *curr_col = NULL;
    dataframe_column_t *next_col = NULL;

    if (line == NULL)
        return;
    curr_col = line->cols;
    for (; curr_col != NULL; curr_col = next_col) {
        next_col = curr_col->next;
        df_col_free(curr_col);
    }
    free(line);
}
