/*
** EPITECH PROJECT, 2025
** df_to_type
** File description:
** Cuddle
*/

#include <stdio.h>
#include "dataframe.h"
#include "df_core/df_col.h"
#include "utils.h"

dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast)
{
    dataframe_t *new_df = NULL;

    if (dataframe == NULL || column == NULL || downcast == UNDEFINED)
        return NULL;
    new_df = df_dup(dataframe);
    if (new_df == NULL)
        return NULL;
    if (df_col_promote(new_df, downcast, column) == FUNC_FAILED)
        return df_free_n(new_df);
    return new_df;
}
