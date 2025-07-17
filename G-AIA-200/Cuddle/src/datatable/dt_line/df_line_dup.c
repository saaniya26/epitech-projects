/*
** EPITECH PROJECT, 2025
** df_line_dup
** File description:
** Cuddle
*/

#include <stdio.h>
#include "df_core/df_line.h"
#include "df_core/df_col.h"
#include "utils.h"

static dataframe_line_t *make_line(dataframe_t *dt, dataframe_line_t *src)
{
    dataframe_line_t *new_line = NULL;

    if (src == NULL)
        return NULL;
    new_line = df_line_create(dt);
    if (new_line == NULL)
        return NULL;
    new_line->n = src->n;
    new_line->cols = df_col_dup_chain(dt->cols_types, src->cols);
    return new_line;
}

dataframe_line_t *df_line_dup(dataframe_t *dt, dataframe_line_t *src)
{
    dataframe_line_t *new_lines = NULL;

    if (dt == NULL || src == NULL)
        return NULL;
    for (; src != NULL; src = src->next)
        if (df_line_chain(&new_lines, make_line(dt, src)) == FUNC_FAILED)
            return new_lines;
    return new_lines;
}
