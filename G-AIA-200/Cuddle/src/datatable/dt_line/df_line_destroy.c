/*
** EPITECH PROJECT, 2025
** df_line_free
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "df_core/df_core.h"
#include "df_core/df_line.h"
#include "df_core/df_col.h"
#include "utils.h"

void df_line_destroy(dataframe_line_t *line)
{
    dataframe_line_t *curr_line = NULL;
    dataframe_line_t *next_line = NULL;
    dataframe_t *dt = NULL;

    if (line == NULL)
        return;
    curr_line = line;
    dt = line->dt;
    if (dt == NULL)
        return;
    for (; curr_line != NULL; curr_line = next_line) {
        dt->nb_rows--;
        next_line = curr_line->next;
        df_line_free(curr_line);
    }
}

void df_line_destroy_rev(dataframe_line_t *line)
{
    dataframe_line_t *curr_line = NULL;
    dataframe_line_t *next_line = NULL;
    dataframe_t *dt = NULL;

    if (line == NULL)
        return;
    curr_line = line;
    dt = line->dt;
    if (dt == NULL)
        return;
    for (; curr_line != NULL; curr_line = next_line) {
        dt->nb_rows--;
        next_line = curr_line->prev;
        df_line_free(curr_line);
    }
}
