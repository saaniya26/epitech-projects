/*
** EPITECH PROJECT, 2025
** df_col_free
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "df_core/df_core.h"
#include "utils.h"

void df_col_free(dataframe_column_t *col)
{
    if (col == NULL)
        return;
    free(col->value);
    free(col);
}
