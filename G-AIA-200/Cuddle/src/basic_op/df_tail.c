/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_tail
*/

#include <stdlib.h>
#include "dataframe.h"
#include "df_core/df_line.h"
#include "my.h"

static int patch_tail(dataframe_t *tail, dataframe_line_t *line)
{
    if (tail == NULL || line == NULL)
        return FUNC_FAILED;
    df_line_destroy_rev(line->prev);
    tail->lines = line;
    line->prev = NULL;
    return FUNC_SUCCESS;
}

dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows)
{
    int index = 1;
    dataframe_t *tail = NULL;
    dataframe_line_t *line = NULL;

    if (dataframe == NULL || nb_rows <= 0)
        return NULL;
    if (dataframe->lines == NULL)
        return NULL;
    tail = df_dup(dataframe);
    if (tail == NULL)
        return NULL;
    for (line = tail->lines; line->next != NULL; line = line->next);
    if (line == NULL)
        return df_free_n(tail);
    for (; line->prev != NULL && index != nb_rows; line = line->prev)
        index++;
    if (patch_tail(tail, line) == FUNC_FAILED)
        return df_free_n(tail);
    return tail;
}
