/*
** EPITECH PROJECT, 2025
** df_col_desc_destroy
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "df_core/df_core.h"
#include "df_core/df_col.h"
#include "utils.h"

void df_col_desc_destroy(dataframe_col_desc_t *col_desc)
{
    dataframe_col_desc_t *curr_col = NULL;
    dataframe_col_desc_t *next_col = NULL;

    if (col_desc == NULL)
        return;
    curr_col = col_desc;
    for (; curr_col != NULL; curr_col = next_col) {
        next_col = curr_col->next;
        free(curr_col->column_name);
        free(curr_col);
    }
}
