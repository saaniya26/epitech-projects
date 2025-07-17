/*
** EPITECH PROJECT, 2025
** dup
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "my.h"
#include "df_core/df_core.h"
#include "df_core/df_col.h"
#include "df_core/df_line.h"
#include "utils.h"

dataframe_t *df_dup(dataframe_t *src)
{
    dataframe_t *new_df = NULL;

    if (src == NULL)
        return NULL;
    new_df = df_create();
    if (new_df == NULL)
        return NULL;
    new_df->cols_types = df_col_desc_dup(src->cols_types);
    new_df->initial_header = NULL;
    new_df->initial_header = my_tabdup(src->initial_header);
    new_df->nb_rows = src->nb_rows;
    new_df->nb_columns = src->nb_columns;
    new_df->separator = my_strdup(src->separator);
    new_df->lines = df_line_dup(new_df, src->lines);
    return new_df;
}
