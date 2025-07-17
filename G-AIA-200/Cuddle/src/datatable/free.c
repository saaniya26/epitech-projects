/*
** EPITECH PROJECT, 2025
** free
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "my.h"
#include "df_core/df_core.h"
#include "df_core/df_col.h"
#include "df_core/df_line.h"
#include "utils.h"

void df_free(dataframe_t *dataframe)
{
    if (dataframe == NULL)
        return;
    df_line_destroy(dataframe->lines);
    df_col_desc_destroy(dataframe->cols_types);
    my_tabfree((void **) dataframe->initial_header);
    free(dataframe->separator);
    free(dataframe);
}

void *df_free_n(dataframe_t *dataframe)
{
    df_free(dataframe);
    return NULL;
}
